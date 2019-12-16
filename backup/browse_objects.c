/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:15:46 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/12 02:25:28 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

int		browse_cylindre(t_p pos, t_cyl *cyl, t_p dir, t_inter *i)
{
	double	tmp;
	t_cyl	*memo;
	t_p		plane;

	memo = NULL;
	while (cyl)
	{
		tmp = inter_cyl(pos, *cyl, dir);
		memo = (tmp > -1 && (tmp < i->d || i->d == -1)) ? cyl : memo;
		i->d = (tmp > -1 && (tmp < i->d || i->d == -1)) ? tmp : i->d;
		cyl = cyl->next;
	}
	if (memo)
	{
		i->color = memo->color;
		i->p = shift_vec(pos, dir, i->d);
		i->n = shift_vec(pos, memo->pos, -1);
		plane = mult_vec(i->n, dot_product(i->n, memo->pos));
		i->n = shift_vec(pos, shift_vec(plane, memo->pos, 1), -1);
		i->n = norm_vec(i->n);
		if (dot_product(i->n, dir) > 0)
			i->n = mult_vec(i->n, -1);
	}
	return (i->d);
}

int		browse_plan(t_p pos, t_plan *plan, t_p dir, t_inter *i)
{
	double tmp;
	t_plan *memo;

	memo = NULL;
	while (plan)
	{
		tmp = inter_plan(pos, *plan, dir);
		if (tmp > -1 && (tmp < i->d || i->d == -1))
		{
			i->d = tmp;
			memo = plan;
		}
		plan = plan->next;
	}
	if (memo)
	{
		i->color = memo->color;
		i->p = shift_vec(pos, dir, i->d);
		i->n = norm_vec(memo->vector);
		if (dot_product(i->n, dir) > 0)
			i->n = mult_vec(i->n, -1);
	}
	return (i->d);
}

int		browse_sphere(t_p pos, t_sphere *sphere, t_p dir, t_inter *i)
{
	double		tmp;
	t_sphere	*memo;

	memo = NULL;
	while (sphere)
	{
		tmp = inter_sphere(pos, *sphere, dir);
		if (tmp > -1 && (tmp < i->d || i->d == -1))
		{
			i->d = tmp;
			memo = sphere;
		}
		sphere = sphere->next;
	}
	if (memo)
	{
		i->color = memo->color;
		i->p = shift_vec(pos, dir, i->d);
		i->n = shift_vec(i->p, memo->center, -1);
		i->n = norm_vec(i->n);
		if (dot_product(i->n, dir) > 0)
			i->n = mult_vec(i->n, -1);
	}
	return (i->d);
}

int		browse_tri(t_p pos, t_triangle *tr, t_p dir, t_inter *i)
{
	double		tmp;
	t_p			vertex[2];
	t_triangle	*memo;

	memo = NULL;
	while (tr)
	{
		tmp = inter_triangle(pos, *tr, dir);
		if (tmp > -1 && (tmp < i->d || i->d == -1))
		{
			i->d = tmp;
			memo = tr;
		}
		tr = tr->next;
	}
	if (memo)
	{
		i->color = memo->color;
		i->p = shift_vec(pos, dir, i->d);
		vertex[0] = shift_vec(memo->vertex2, memo->vertex1, -1);
		vertex[1] = shift_vec(memo->vertex3, memo->vertex2, -1);
		i->n = norm_vec(cross_poduct(vertex[0], vertex[1]));
		i->n = dot_product(i->n, dir) >= 0 ? mult_vec(i->n, -1) : i->n;
	}
	return (i->d);
}

int		browse_square(t_p pos, t_square *square, t_p dir, t_inter *i)
{
	double		tmp;
	t_square	*memo;

	memo = NULL;
	while (square)
	{
		tmp = inter_square(pos, *square, dir);
		if (tmp > -1 && (tmp < i->d || i->d == -1))
		{
			i->d = tmp;
			memo = square;
		}
		square = square->next;
	}
	if (memo)
	{
		i->color = memo->color;
		i->p = shift_vec(pos, dir, i->d);
		i->n = memo->vector;
		if (dot_product(i->n, dir) > 0)
			i->n = mult_vec(i->n, -1);
	}
	return (i->d);
}
