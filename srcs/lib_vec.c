/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:39:08 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/24 16:50:16 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length_vec(t_point vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_point norm_vec(t_point vec)
{
	double length;

	length = length_vec(vec);
	vec.x = vec.x / length;
	vec.y = vec.y / length;
	vec.z = vec.z / length;
	return (vec);
}

double	dot_product(t_point vec1, t_point vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_point	cross_poduct(t_point a, t_point b)
{
	t_point c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_point shift_vec(t_point O, t_point vec, int d, char op)
{
	if (op == '+')
	{
		O.x = O.x + d * vec.x;
		O.y = O.y + d * vec.y;
		O.z = O.z + d * vec.z;
	}
	else if (op == '-')
	{
		O.x = O.x - d * vec.x;
		O.y = O.y - d * vec.y;
		O.z = O.z - d * vec.z;
	}
	return (O);
}
