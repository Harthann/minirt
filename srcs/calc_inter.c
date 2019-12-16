/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:20:20 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/12 02:24:37 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

int			test_inter(t_p pos, t_cyl cyl, t_p dir, double tmp)
{
	t_p q;
	t_p q2;
	t_p top;

	if (tmp == -1)
		return (0);
	top = shift_vec(cyl.pos, cyl.vec, cyl.heigth);
	q2 = shift_vec(shift_vec(pos, dir, tmp), top, -1);
	q = shift_vec(shift_vec(pos, dir, tmp), cyl.pos, -1);
	if (dot_product(cyl.vec, q) >= 0 && dot_product(cyl.vec, q2) <= 0)
		return (1);
	return (0);
}

double		inter_circle(t_p pos, t_cyl cyl, t_p dir)
{
	t_plan	plan;
	t_p		point;
	double	d[2];

	plan.origin = cyl.pos;
	plan.vector = mult_vec(cyl.vec, -1);
	d[0] = inter_plan(pos, plan, dir);
	point = shift_vec(pos, dir, d[0]);
	point = shift_vec(point, cyl.pos, -1);
	if (length_vec(point) > cyl.radius)
		d[0] = -1;
	plan.origin = shift_vec(cyl.pos, cyl.vec, cyl.heigth);
	plan.vector = cyl.vec;
	d[1] = inter_plan(pos, plan, dir);
	point = shift_vec(pos, dir, d[1]);
	point = shift_vec(point, plan.origin, -1);
	if (length_vec(point) > cyl.radius)
		d[1] = -1;
	if (d[0] < 0)
		d[0] = d[1];
	if (d[0] < 0 && d[1] > 0)
		d[0] = d[1];
	if (d[1] > 0 && d[0] > d[1])
		d[0] = d[1];
	return (d[0]);
}

double		inter_cyl(t_p pos, t_cyl cyl, t_p dir)
{
	double	d[7];
	t_p		p[3];

	p[2] = shift_vec(pos, cyl.pos, -1);
	p[0] = shift_vec(dir, mult_vec(cyl.vec, dot_product(dir, cyl.vec)), -1);
	p[1] = shift_vec(p[2], mult_vec(cyl.vec, dot_product(p[2], cyl.vec)), -1);
	d[0] = dot_product(p[0], p[0]);
	d[1] = 2 * dot_product(p[0], p[1]);
	d[2] = dot_product(p[1], p[1]) - cyl.radius * cyl.radius;
	d[5] = d[1] * d[1] - 4.0 * d[0] * d[2];
	d[6] = inter_circle(pos, cyl, dir);
	if (d[5] > 0)
	{
		d[2] = sqrt(d[5]);
		d[3] = (-d[1] + d[2]) / (2 * d[0]);
		d[4] = (-d[1] - d[2]) / (2 * d[0]);
		d[3] = test_inter(pos, cyl, dir, d[3]) ? d[3] : -1;
		d[4] = test_inter(pos, cyl, dir, d[4]) ? d[4] : -1;
		if (d[3] < 0 || (d[4] < d[3] && d[4] > 0))
			d[3] = d[4];
		if (d[3] < 0 || (d[6] < d[3] && d[6] > 0))
			d[3] = d[6];
		return (d[3]);
	}
	return (d[5] == 0 ? (-d[1] / (2 * d[0])) : d[6]);
}

double		inter_plan(t_p pos, t_plan plan, t_p dir)
{
	double a;
	double b;

	plan.vector = norm_vec(plan.vector);
	if (!(b = dot_product(dir, plan.vector)))
		return (-1);
	a = dot_product(plan.origin, plan.vector);
	b = (a - dot_product(pos, plan.vector)) / b;
	if (b < 0)
		return (-1);
	return (b);
}

double		inter_sphere(t_p pos, t_sphere sphere, t_p dir)
{
	double d[6];

	d[0] = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
	d[1] = 2 * (dir.x * (pos.x - sphere.center.x)
		+ dir.y * (pos.y - sphere.center.y)
		+ dir.z * (pos.z - sphere.center.z));
	d[2] = (pos.x - sphere.center.x) * (pos.x - sphere.center.x)
		+ (pos.y - sphere.center.y) * (pos.y - sphere.center.y)
		+ (pos.z - sphere.center.z) * (pos.z - sphere.center.z)
		- sphere.radius * sphere.radius;
	if (d[0] == 0)
		return (-d[2] / d[1]);
	d[3] = d[1] * d[1] - 4 * d[0] * d[2];
	if (d[3] > 0)
	{
		d[2] = sqrt(d[3]);
		d[4] = (-d[1] + d[2]) / (2 * d[0]);
		d[5] = (-d[1] - d[2]) / (2 * d[0]);
		if (d[4] > 0 && (d[4] < d[5] || d[5] < 0))
			return (d[4]);
		if (d[5] > 0 && (d[5] < d[4] || d[4] < 0))
			return (d[5]);
		return (d[4] > d[5] ? d[5] : d[4]);
	}
	return (d[3] == 0 ? (-d[1] / (2 * d[0])) : -1);
}
