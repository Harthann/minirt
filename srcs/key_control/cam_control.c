/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:11:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 15:38:33 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

void	rotate_cam(t_scene *scene, int key, t_p axe)
{
	t_p		mat[3];
	t_p		vec;
	double	a;

	a = key == 123 || key == 126 ? -0.1 : 0.1;
	mat[0].x = axe.x * axe.x + (1 - axe.x * axe.x) * cos(a);
	mat[0].y = axe.x * axe.y * (1 - cos(a)) - axe.z * sin(a);
	mat[0].z = axe.x * axe.z * (1 - cos(a)) + axe.y * sin(a);
	mat[1].x = axe.x * axe.y * (1 - cos(a)) + axe.z * sin(a);
	mat[1].y = axe.y * axe.y + (1 - axe.y * axe.y) * cos(a);
	mat[1].z = axe.y * axe.z * (1 - cos(a)) - axe.x * sin(a);
	mat[2].x = axe.x * axe.z * (1 - cos(a)) - axe.y * sin(a);
	mat[2].y = axe.y * axe.z * (1 - cos(a)) + axe.x * sin(a);
	mat[2].z = axe.z * axe.z + (1 - axe.z * axe.z) * cos(a);
	vec = scene->image->cam.vector;
	scene->image->cam.vector.x = vec.x * mat[0].x;
	scene->image->cam.vector.x += vec.y * mat[0].y + vec.z * mat[0].z;
	scene->image->cam.vector.y = vec.x * mat[1].x;
	scene->image->cam.vector.y += vec.y * mat[1].y + vec.z * mat[1].z;
	scene->image->cam.vector.z = vec.x * mat[2].x;
	scene->image->cam.vector.z += vec.y * mat[2].y + vec.z * mat[2].z;
	scene->image->cam.vector = scene->image->cam.vector;

}

void	translate_cam(t_scene *scene, int key, t_p axe)
{
	double a;

	if (key == 13 || key == 2 || key == 49)
		a = 5;
	else
		a = -5;
	scene->image->cam.pos = shift_vec(scene->image->cam.pos, axe, a);
}

void	cam_control(t_scene *scene, int key)
{
	t_p axes[4];

	axes[3] = fill_vec(0, 1, 0);
	axes[2] = scene->image->cam.vector;
	axes[0] = find_top_vec(axes[2]);
	axes[1] = cross_poduct(axes[0], axes[2]);
	if (key >= 123 && key <= 126)
	{
		if (key == 123 || key == 124)
			rotate_cam(scene, key, axes[0]);
		else
			rotate_cam(scene, key, axes[1]);
	}
	else
	{
		if (key == 0 || key == 2)
			translate_cam(scene, key, axes[1]);
		else if (key == 13 || key == 1)
			translate_cam(scene, key, axes[2]);
		else
			translate_cam(scene, key, axes[0]);
	}
	draw_image(*scene, scene->image->cam, &scene->image->image);
	mlx_put_image_to_window(scene->win.mlx_ptr, scene->win.mlx_win,
	scene->image->ptr, 0, 0);
}
