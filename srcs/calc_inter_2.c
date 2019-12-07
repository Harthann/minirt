/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_inter_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:38:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 20:36:54 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double		inter_triangle(t_point pos, t_triangle triangle, t_point dir)
{
	t_point vertex[7];
	t_plan plan;
	double det;

	vertex[0] = shift_vec(triangle.vertex2, triangle.vertex1, 1, '-');
	vertex[1] = shift_vec(triangle.vertex3, triangle.vertex2, 1, '-');
	plan.vector = norm_vec(cross_poduct(vertex[0], vertex[1]));
	plan.origin = triangle.vertex1;
	det = inter_plan(pos, plan, dir);
	vertex[6] = shift_vec(pos, dir, det, '+');
	vertex[2] = shift_vec(triangle.vertex1, triangle.vertex3, 1, '-');
	vertex[3] = shift_vec(vertex[6], triangle.vertex1, 1 , '-');
	vertex[4] = shift_vec(vertex[6], triangle.vertex2, 1 , '-');
	vertex[5] = shift_vec(vertex[6], triangle.vertex3, 1 , '-');
	if (det < 0)
		return (-1);
	if ((dot_product(plan.vector, cross_poduct(vertex[0], vertex[3])) > 0)
		&& (dot_product(plan.vector, cross_poduct(vertex[1], vertex[4])) > 0)
		&& (dot_product(plan.vector, cross_poduct(vertex[2], vertex[5])) > 0))
		return (det);
	// if ((dot_product(plan.vector, cross_poduct(vertex[0], vertex[3])) < 0)
	// 	&& (dot_product(plan.vector, cross_poduct(vertex[1], vertex[4])) < 0)
	// 	&& (dot_product(plan.vector, cross_poduct(vertex[2], vertex[5])) < 0))
	// 	return (det);
	return (-1);
}