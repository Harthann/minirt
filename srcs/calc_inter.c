/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:20:20 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/06 03:23:37 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

int		test_inter(t_point pos, t_cyl cyl, t_point dir, double tmp)
{
	t_point Q;
	t_point Q2;
	
	if (tmp == -1)
		return (0);
	Q2 = shift_vec(shift_vec(pos, dir, tmp, '+'), shift_vec(cyl.pos, cyl.vec, cyl.heigth, '+'), 1, '-');
	Q = shift_vec(shift_vec(pos, dir, tmp, '+'), cyl.pos, 1, '-');
	if (dot_product(cyl.vec, Q) >= 0 && dot_product(cyl.vec, Q2) <= 0)
		return (1);
	return (0);
}

double		inter_circle(t_point pos, t_cyl cyl, t_point dir)
{
	t_plan plan;
	t_point point;
	double d[2];

	plan.origin = cyl.pos;
	plan.vector = mult_vec(cyl.vec, -1);
	plan.color	= cyl.color;
	plan.next = NULL;
	d[0] = inter_plan(pos, plan, dir);
	point = shift_vec(pos, dir, d[0], '+');
	point = shift_vec(point, cyl.pos, 1, '-');
	if (length_vec(point) > cyl.radius)
		d[0] = -1;
	plan.origin = shift_vec(cyl.pos, cyl.vec, cyl.heigth, '+');
	plan.vector = cyl.vec;
	d[1] = inter_plan(pos, plan, dir);
	point = shift_vec(pos, dir, d[1], '+');
	point = shift_vec(point, plan.origin, 1, '-');
	if (length_vec(point) > cyl.radius)
		d[1] = -1;
	if (d[0] < 0)
		d[0] = d[1];
	if (d[0] < 0 && d[1] > 0)
		d[0] = d[1];
	if (d[1] > 0 && d[0] > d[1])
		d[0] = d[1];
	return(d[0]);
}

double		inter_cyl(t_point pos, t_cyl cyl, t_point dir)
{
	double d[7];
	/* MY SOLUTION */
	t_point X;
	t_point Y;
	t_point deltap;
	
	deltap = shift_vec(pos, cyl.pos, 1, '-');
	X = shift_vec(dir, mult_vec(cyl.vec, dot_product(dir, cyl.vec)) , 1, '-');
	Y = shift_vec(deltap, mult_vec(cyl.vec, dot_product(deltap, cyl.vec)) , 1, '-');
	d[0] = dot_product(X,X);
	d[1] = 2 * dot_product(X, Y);
	d[2] = dot_product(Y, Y) - cyl.radius * cyl.radius;
	
	/* LOMASSE */
	// t_point os = cross_poduct(cyl.vec, dir);
	// t_point tmp = cross_poduct(cyl.vec, shift_vec(pos, cyl.pos, 1, '-'));
    // d[0] = dot_product(os, os);
    // d[1] = dot_product(os, cross_poduct(cyl.vec, shift_vec(pos, cyl.pos, 1, '-'))) * 2.0;
    // d[2] = dot_product(tmp, tmp) - cyl.radius * cyl.radius;
	/*				*/
	d[5] = d[1] * d[1] - 4.0 * d[0] * d[2];
	d[6] = inter_circle(pos, cyl, dir);
	if (d[5] > 0)
	{
		d[2] = sqrt(d[5]);
		d[3] = (-d[1] + d[2]) / (2 * d[0]);
		d[4] = (-d[1] - d[2]) / (2 * d[0]);
		d[3] = test_inter(pos, cyl, dir, d[3]) ? d[3] : -1;
		d[4] = test_inter(pos, cyl, dir, d[4]) ? d[4] : -1;
		// d[6] = test_inter(pos, cyl, dir, d[6]) ? d[6] : -1;
		if (d[3] < 0 && d[4] < 0)
			return (d[6] < 0 ? -1 : d[6]);
		if (d[3] < 0 || (d[4] < d[3]&& d[4] > 0))
			d[3] = d[4];
		if (d[3] < 0 || (d[6] < d[3] && d[6] > 0))
			d[3] = d[6];
		return (d[3]);
	}
	else if (d[5] == 0)
		return (-d[1] / (2 * d[0]));
	// d[6] = test_inter(pos, cyl, dir, d[6]) ? d[6] : -1;
	return (d[6]);
}

double	inter_plan(t_point pos, t_plan plan, t_point dir)
{
	double a;
	double b;

	plan.vector = norm_vec(plan.vector);
	a = dot_product(plan.origin, plan.vector);
	if (!(b = dot_product(dir, plan.vector)))
		return (-1);
	b = (a - dot_product(pos, plan.vector)) / b;
	if (b < 0)
		return (-1);
	return (b);
}

double	inter_sphere(t_point pos, t_sphere sphere, t_point dir)
{
	double a;
	double b;
	double c;
	double det;

	a = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
	b = 2 * (dir.x * (pos.x - sphere.center.x)
		+ dir.y * (pos.y - sphere.center.y)
		+ dir.z * (pos.z - sphere.center.z));
	c = (pos.x - sphere.center.x) * (pos.x - sphere.center.x)
		+ (pos.y - sphere.center.y) * (pos.y - sphere.center.y)
		+ (pos.z - sphere.center.z) * (pos.z - sphere.center.z)
		- sphere.radius * sphere.radius;
	if (a == 0)
		return (- c / b);
	det = b * b - 4 * a * c;
	if (det > 0)
	{
		c = sqrt(det);
		double t1 = (-b + c) / (2 * a);
		double t2 = (-b - c) / (2 * a);
		if (t1 > 0 && (t1 < t2 || t2 < 0))
			return (t1);
		if (t2 > 0 && (t2 < t1 || t1 < 0))
			return (t2);		
		return (t1 > t2 ? t2 : t1);
	}
	else if (det == 0)
		return (-b / (2 * a));
	return (-1);
}