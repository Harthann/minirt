/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vec_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:23:54 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/11 00:58:28 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	length_vec(t_p vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double	dot_product(t_p vec1, t_p vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

int		comp_vec(t_p a, t_p b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z)
		return (1);
	return (0);
}

t_p		fill_vec(double x, double y, double z)
{
	t_p p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
