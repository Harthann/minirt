/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:20:20 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/25 16:21:09 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	inter_sphere(t_cam cam, t_sphere sphere, t_point dir)
{
	double a;
	double b;
	double c;
	double det;

	a = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
	b = 2 * (dir.x * (cam.pos.x - sphere.center.x)
		+ dir.y * (cam.pos.y - sphere.center.y)
		+ dir.z * (cam.pos.z - sphere.center.z));
	c = pow(cam.pos.x - sphere.center.x, 2)
		+ pow(cam.pos.y - sphere.center.y, 2)
		+ pow(cam.pos.z - sphere.center.z, 2)
		- sphere.radius * sphere.radius;
	det = b * b - 4 * a * c;
	if (det > 0)
	{
		det = (-b + sqrt(det)) / (2 * a);
		a = (-b - sqrt(det)) / (2 * a);
		if (det >  a)
			return (a);
		else
			return (det);
	}
	else if (det == 0)
		return (-b / (2 * a));
	return (-1);
}