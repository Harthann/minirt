/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:34:50 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/13 22:45:26 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

void	rotate_obj(t_p *point, t_p axe, double speed)
{
	t_p		mat[3];
	t_p		vec;
	double	a;

	a = 0.1 * speed / 100;
	mat[0].x = axe.x * axe.x + (1 - axe.x * axe.x) * cos(a);
	mat[0].y = axe.x * axe.y * (1 - cos(a)) - axe.z * sin(a);
	mat[0].z = axe.x * axe.z * (1 - cos(a)) + axe.y * sin(a);
	mat[1].x = axe.x * axe.y * (1 - cos(a)) + axe.z * sin(a);
	mat[1].y = axe.y * axe.y + (1 - axe.y * axe.y) * cos(a);
	mat[1].z = axe.y * axe.z * (1 - cos(a)) - axe.x * sin(a);
	mat[2].x = axe.x * axe.z * (1 - cos(a)) - axe.y * sin(a);
	mat[2].y = axe.y * axe.z * (1 - cos(a)) + axe.x * sin(a);
	mat[2].z = axe.z * axe.z + (1 - axe.z * axe.z) * cos(a);
	vec = *point;
	point->x = vec.x * mat[0].x;
	point->x += vec.y * mat[0].y + vec.z * mat[0].z;
	point->y = vec.x * mat[1].x;
	point->y += vec.y * mat[1].y + vec.z * mat[1].z;
	point->z = vec.x * mat[2].x;
	point->z += vec.y * mat[2].y + vec.z * mat[2].z;
}

int		rotation(t_scene *scene)
{
	t_sphere	*obj;
	t_p			y;

	if (scene->rotation)
	{
		y = fill_vec(0, 1, 0);
		obj = scene->obj.sphere;
		while (obj)
		{
			rotate_obj(&obj->center, y, obj->speed);
			obj = obj->next;
		}
		draw_image(*scene, scene->image->cam, &scene->image->image);
		mlx_put_image_to_window(scene->win.mlx_ptr, scene->win.mlx_win,
		scene->image->ptr, 0, 0);
	}
	return (0);
}
