/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_inter_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:38:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/12 02:26:48 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double				inter_triangle(t_p pos, t_triangle triangle, t_p dir)
{
	t_p		vertex[7];
	t_plan	plan;
	double	det;

	vertex[1] = shift_vec(triangle.vertex3, triangle.vertex2, -1);
	vertex[0] = shift_vec(triangle.vertex2, triangle.vertex1, -1);
	plan.vector = norm_vec(cross_poduct(vertex[0], vertex[1]));
	plan.origin = triangle.vertex1;
	det = inter_plan(pos, plan, dir);
	vertex[6] = shift_vec(pos, dir, det);
	vertex[2] = shift_vec(triangle.vertex1, triangle.vertex3, -1);
	vertex[3] = shift_vec(vertex[6], triangle.vertex1, -1);
	vertex[4] = shift_vec(vertex[6], triangle.vertex2, -1);
	vertex[5] = shift_vec(vertex[6], triangle.vertex3, -1);
	if (det < 0)
		return (-1);
	if ((dot_product(plan.vector, cross_poduct(vertex[0], vertex[3])) > 0)
		&& (dot_product(plan.vector, cross_poduct(vertex[1], vertex[4])) > 0)
		&& (dot_product(plan.vector, cross_poduct(vertex[2], vertex[5])) > 0))
		return (det);
	return (-1);
}

static	double		check_plan(t_p pos, t_square square, t_p dir)
{
	t_plan	plan;

	plan.origin = square.pos;
	plan.vector = square.vector;
	return (inter_plan(pos, plan, dir));
}

double				inter_square(t_p pos, t_square square, t_p dir)
{
	double		d[4];
	t_p			vec[7];
	t_triangle	t[2];

	vec[5] = fill_vec(0, 1, 0);
	if ((d[0] = check_plan(pos, square, dir)) < 0)
		return (-1);
	vec[0] = shift_vec(pos, dir, d[0]);
	vec[5] = !comp_vec(square.vector, vec[5]) ? vec[5] : fill_vec(1, 0, 0);
	vec[1] = cross_poduct(vec[5], square.vector);
	vec[2] = cross_poduct(vec[1], square.vector);
	vec[3] = cross_poduct(vec[2], square.vector);
	vec[4] = cross_poduct(vec[3], square.vector);
	d[1] = sqrt(2 * (square.heigth * square.heigth)) / 2;
	t[1].vertex2 = shift_vec(square.pos, vec[1], d[1]);
	t[0].vertex3 = shift_vec(square.pos, vec[2], d[1]);
	t[0].vertex1 = shift_vec(square.pos, vec[3], d[1]);
	t[0].vertex2 = shift_vec(square.pos, vec[4], d[1]);
	t[1].vertex1 = t[0].vertex2;
	t[1].vertex3 = t[0].vertex3;
	d[2] = inter_triangle(pos, t[0], dir);
	d[3] = inter_triangle(pos, t[1], dir);
	return (d[2] < 0 ? d[3] : d[2]);
}
