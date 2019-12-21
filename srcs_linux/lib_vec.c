/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:39:08 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/12 02:29:15 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_p	mult_vec(t_p a, double b)
{
	a.x = a.x * b;
	a.y = a.y * b;
	a.z = a.z * b;
	return (a);
}

t_p	norm_vec(t_p vec)
{
	double length;

	length = length_vec(vec);
	vec.x = vec.x / length;
	vec.y = vec.y / length;
	vec.z = vec.z / length;
	return (vec);
}

t_p	cross_poduct(t_p a, t_p b)
{
	t_p c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_p	shift_vec(t_p origin, t_p vec, int d)
{
	origin.x = origin.x + d * vec.x;
	origin.y = origin.y + d * vec.y;
	origin.z = origin.z + d * vec.z;
	return (origin);
}
