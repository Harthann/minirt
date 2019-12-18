/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:19:49 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 12:15:32 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

t_color		itoc(int color)
{
	int		tmp;
	t_color res;

	tmp = 0xff0000;
	res.r = (tmp & color) >> 16;
	tmp = 0x00ff00;
	res.g = (tmp & color) >> 8;
	tmp = 0x0000ff;
	res.b = tmp & color;
	return (res);
}

t_color				texture_mapping(t_sphere sphere, t_inter *i)
{
	double	uv[2];
	// double	angles[2];

	if (!sphere.texture.texture)
		return (sphere.color);

	// uv[0] = 0.5 + (atan2(i->n.z, i->n.x) / (2 * M_PI));
	// uv[1] = 0.5 - asin(i->n.y) / M_PI;
	// uv[1] = 1 - uv[1];
	// angles[1] = acos(-1 * dot_product(norm_vec(fill_vec(0, 1, 0)), i->n));
	// uv[1] = angles[1] / M_PI;
	// point[1] = fill_vec(0, 0, 1);//cross_poduct(cross_poduct(i->n, norm_vec(fill_vec(0, 1, 0))), i->n);
	// angles[0] = acos(dot_product(i->n, point[1]) / sin(angles[1])) / ((double)2 * M_PI);
	// if (dot_product(cross_poduct(norm_vec(fill_vec(0, 1, 0)), point[1]), i->n) > 0)
	// 	uv[0] = angles[0];
	// else
	// 	uv[0] = 1 - angles[0];

	uv[0] = atan2(i->n.x, i->n.z) * (2 * M_PI) + 0.5;
	uv[1] = i->n.y * 0.5 + 0.5;

	uv[0] = uv[0] * sphere.texture.width;
	uv[1] = uv[1] * sphere.texture.heigth * sphere.texture.width;
	// printf("[%f] [%f]\n", uv[0], uv[1]);
	int color = sphere.texture.texture[(int)uv[0] + (int)uv[1]];
	return (itoc(color));
}