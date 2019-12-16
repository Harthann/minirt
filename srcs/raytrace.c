/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:15:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 12:13:30 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

int				rgb_conv(t_color color)
{
	int col;

	col = color.r << 16;
	col = col | (color.g << 8);
	col = col | color.b;
	return (col);
}

t_p				init_screen(int i, int j, t_scene scene)
{
	t_p		point;
	double	coef;

	coef = (double)scene.win.width / (double)scene.win.heigth;
	point.x = coef * 2 * ((double)j + 0.5) / (double)scene.win.width - 1;
	point.y = 1 - 2 * ((double)i + 0.5) / (double)scene.win.heigth;
	point.z = tan(scene.win.fov / 2 * M_PI / 180);
	return (point);
}

static t_color	fill_color(t_scene scene)
{
	t_color color;

	color.r = scene.ambient.color.r * scene.ambient.intensity / 4;
	color.g = scene.ambient.color.g * scene.ambient.intensity / 4;
	color.b = scene.ambient.color.b * scene.ambient.intensity / 4;
	return (color);
}

t_p				find_top_vec(t_p vec)
{
	t_p y;
	t_p x;

	y = norm_vec(fill_vec(0, 1, 0));
	x = norm_vec(fill_vec(1, 0, 0));
	if (!dot_product(vec, x))
	{
		printf("[%f] [%f] [%f]\n", vec.x, vec.y, vec.z);
		y = cross_poduct(x, vec);
	}
	return (y);
}

int				raytrace(t_scene *scene, int i, int j, t_cam cam)
{
	t_p		point[3];
	t_inter inter;
	t_p		matrice[4];

	ft_bzero(&inter, sizeof(t_inter));
	inter.d = -1;
	point[0] = fill_vec(0, 1, 0);
	cam.vector = norm_vec(cam.vector);
	point[0] = find_top_vec(cam.vector);//comp_vec(cam.vector, point[0]) ? point[0] : fill_vec(0, 0, 1);
	matrice[0] = norm_vec(cross_poduct(point[0], cam.vector));
	matrice[1] = norm_vec(cross_poduct(cam.vector, matrice[0]));
	matrice[2] = cam.vector;
	matrice[3] = cam.pos;
	inter.color = fill_color(*scene);
	point[1] = init_screen(i, j, *scene);
	point[0].x = point[1].x * matrice[0].x
	+ point[1].y * matrice[1].x + point[1].z * matrice[2].x + matrice[3].x;
	point[0].y = point[1].x * matrice[0].y
	+ point[1].y * matrice[1].y + point[1].z * matrice[2].y + matrice[3].y;
	point[0].z = point[1].x * matrice[0].z
	+ point[1].y * matrice[1].z + point[1].z * matrice[2].z + matrice[3].z;
	point[2] = norm_vec(shift_vec(point[0], cam.pos, -1));
	if (check_inter(scene, point[2], cam.pos, &inter) != -1)
		inter.color = pixel_intens(inter, scene->obj.light, *scene);
	return (rgb_conv(inter.color));
}
