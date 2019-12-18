/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:19:49 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 15:04:31 by nieyraud         ###   ########.fr       */
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
	double	u;
	double	v;
	int		color;

	if (!sphere.texture.ptr || !sphere.texture.texture)
		return (sphere.color);
	u = 1 - (atan2(i->n.z, i->n.x) + M_PI) / (2 * M_PI);
	v = (asin(i->n.y) + M_PI_2) / M_PI;
	u = u * sphere.texture.width;
	v = (1 - v) * sphere.texture.heigth;
	u < 0 ? u = 0 : 0;
	v < 0 ? v = 0 : 0;
	u > sphere.texture.width - 1 ? u = sphere.texture.width - 1 : 0;
	v > sphere.texture.heigth - 1 ? v = sphere.texture.heigth - 1 : 0;
	color = sphere.texture.texture[(int)u + (int)v * sphere.texture.width];
	return (itoc(color));
}