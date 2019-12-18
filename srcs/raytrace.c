/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:15:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 17:14:56 by nieyraud         ###   ########.fr       */
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

static t_color	fill_color(t_scene scene, t_p dir)
{
	t_color	color;
	double	x;
	double	y;

	if (!scene.skybox.ptr || !scene.skybox.texture)
	{
		color.r = scene.ambient.color.r * scene.ambient.intensity / 4;
		color.g = scene.ambient.color.g * scene.ambient.intensity / 4;
		color.b = scene.ambient.color.b * scene.ambient.intensity / 4;
	}
	else
	{
		x = 1 - (atan2(dir.z, dir.x) + M_PI) / (2 * M_PI);
		y = (asin(dir.y) + M_PI_2) / M_PI;
		x = x * scene.skybox.width;
		y = (1 - y) * scene.skybox.heigth;
		x < 0 ? x = 0 : 0;
		y < 0 ? y = 0 : 0;
		x > scene.skybox.width - 1 ? x = scene.skybox.width - 1 : 0;
		y > scene.skybox.heigth - 1 ? y = scene.skybox.heigth - 1 : 0;
		color = itoc(scene.skybox.texture[(int)x + (int)y
		* scene.skybox.width]);
	}
	return (color);
}

t_p				find_top_vec(t_p vec)
{
	t_p y[2];
	t_p x;

	y[0] = fill_vec(0, 1, 0);
	y[1] = fill_vec(0, -1, 0);
	x = fill_vec(1, 0, 0);
	if (comp_vec(vec, y[0]) || comp_vec(vec, y[1]))
		y[0] = cross_poduct(vec, x);
	return (y[0]);
}

int				raytrace(t_scene *scene, int i, int j, t_cam cam)
{
	t_p		point[3];
	t_inter inter;
	t_p		matrice[4];

	ft_bzero(&inter, sizeof(t_inter));
	inter.d = -1;
	point[0] = find_top_vec(cam.vector);
	matrice[0] = norm_vec(cross_poduct(point[0], cam.vector));
	matrice[1] = norm_vec(cross_poduct(cam.vector, matrice[0]));
	matrice[2] = cam.vector;
	matrice[3] = cam.pos;
	point[1] = init_screen(i, j, *scene);
	point[0].x = point[1].x * matrice[0].x
	+ point[1].y * matrice[1].x + point[1].z * matrice[2].x + matrice[3].x;
	point[0].y = point[1].x * matrice[0].y
	+ point[1].y * matrice[1].y + point[1].z * matrice[2].y + matrice[3].y;
	point[0].z = point[1].x * matrice[0].z
	+ point[1].y * matrice[1].z + point[1].z * matrice[2].z + matrice[3].z;
	point[2] = norm_vec(shift_vec(point[0], cam.pos, -1));
	inter.color = fill_color(*scene, point[2]);
	if (check_inter(scene, point[2], cam.pos, &inter) != -1)
		inter.color = pixel_intens(inter, scene->obj.light, *scene);
	return (rgb_conv(inter.color));
}
