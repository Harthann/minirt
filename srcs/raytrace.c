/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:15:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/06 23:04:47 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

int		rgb_conv(t_color color)
{
	int col;

	col = color.R << 16;
	col = col | (color.G << 8);
	col = col | color.B;
	return (col);
}

// static void	print_vec(t_point a, char *name)
// {
// 	printf("%-9s\t:\t[%f]\t[%f]\t[%f]\n",name, a.x,a.y,a.z);
// }

int		raytrace(t_scene *scene, int i, int j, t_cam cam)
{
	double coef;
	t_point dir;
	t_point point;
	t_inter inter;
	t_point matrice[4];

	ft_bzero(&inter, sizeof(t_inter));
	inter.d = -1;
	point.x = 0;
	point.y = 1;
	point.z = 0;
	point = norm_vec(point);
	cam.vector = norm_vec(cam.vector);
	matrice[0] = norm_vec(cross_poduct(point, cam.vector));
	matrice[1] = norm_vec(cross_poduct(cam.vector, matrice[0]));
	matrice[2] = cam.vector;
	matrice[3] = cam.pos;
	inter.color.R = scene->ambient.color.R * scene->ambient.intensity / 4;
	inter.color.G = scene->ambient.color.G * scene->ambient.intensity / 4;
	inter.color.B = scene->ambient.color.B * scene->ambient.intensity / 4;
	coef = (double)scene->win.width / (double)scene->win.heigth;

	t_point point_2;
	
	point.x = coef * 2 * ((double)j + 0.5) / (double)scene->win.width - 1;
	point.y = 1 - 2 * ((double)i + 0.5) / (double)scene->win.heigth;
	point.z = 1;
	point_2 = point;
	point.x = point_2.x * matrice[0].x + point_2.y * matrice[1].x + point_2.z * matrice[2].x + matrice[3].x;
	point.y = point_2.x * matrice[0].y + point_2.y * matrice[1].y + point_2.z * matrice[2].y + matrice[3].y;
	point.z = point_2.x * matrice[0].z + point_2.y * matrice[1].z + point_2.z * matrice[2].z + matrice[3].z;
	dir = shift_vec(point, cam.pos, 1, '-');
	dir = norm_vec(dir);
	if (check_intersection(scene, dir, cam.pos, &inter) != -1)
		inter.color = pixel_intensity(inter, scene->obj.light, cam, *scene);
	return (rgb_conv(inter.color));
}