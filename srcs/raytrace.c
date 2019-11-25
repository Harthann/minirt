/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:15:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/25 14:58:39 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>




// static void	print_vec(t_point a, char *name)
// {
// 	printf("%-9s\t:\t[%f]\t[%f]\t[%f]\n",name, a.x,a.y,a.z);
// }

int		raytrace(t_scene *scene, int i, int j)
{
	double coef_x;
	double coef_y;
	t_point pos;
	double fov;

	fov = 90;
	coef_x = scene->cam.v_plane_w / scene->win.width;
	coef_y = scene->cam.v_plane_h / scene->win.heigth;
	pos = norm_vec(scene->cam.vector);
	pos.x = j - (scene->win.width / 2) + scene->cam.pos.x;
	pos.y = (scene->win.heigth / 2) - i + scene->cam.pos.y;
	pos.z = scene->win.heigth / 2 * tan(fov / 2) + scene->cam.pos.z;
	pos = norm_vec(pos);

	return (check_intersection(scene, pos));
}