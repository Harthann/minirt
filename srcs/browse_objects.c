/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:15:46 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/06 20:35:25 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

int		browse_cylindre(t_point pos, t_cyl *cyl, t_point dir, t_inter *i)
{
	double tmp;
	t_cyl	*memo;
	t_point P;
	t_point plane;

	memo = NULL;
	while (cyl)
	{
		tmp = inter_cyl(pos, *cyl, dir);
		if (tmp > -1 && (tmp < i->d || i->d == -1))
		{
			memo = cyl;
			i->d = tmp;
		}
		cyl = cyl->next;
	}
	if (memo)
	{
		P = shift_vec(pos, dir, tmp, '+');
		i->color = memo->color;
		memo->vec = norm_vec(memo->vec);
		// i->N = mult_vec(cyl->vec, -1);
		i->P = shift_vec(pos, dir, i->d, '+');
		i->N = shift_vec(pos, memo->pos, 1, '-');
    	plane = mult_vec(i->N, dot_product(i->N, memo->pos));
    	i->N = shift_vec(pos ,shift_vec(plane, memo->pos, 1, '+'), 1, '-');
    	// i->N = cross_poduct(pos , shift_vec(plane, cyl->pos, 1, '+'));
		i->N = norm_vec(i->N);
		if (dot_product(i->N, dir) > 0)
				i->N = mult_vec(i->N, -1);
	}
	return (i->d);
}

int		browse_plan(t_point pos, t_plan *plan, t_point dir, t_inter *i)
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
		i->P = shift_vec(pos, dir, i->d, '+');
		i->N = norm_vec(memo->vector);
		if (dot_product(i->N, dir) > 0)
			i->N = mult_vec(i->N, -1);
	}
	return (i->d);
}

int		browse_sphere(t_point pos, t_sphere *sphere, t_point dir, t_inter *i)
{
	double tmp;
	t_sphere *memo;

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
		i->P = shift_vec(pos, dir, i->d, '+');
		i->N = shift_vec(i->P , memo->center, 1, '-');
		i->N = norm_vec(i->N);
		if (dot_product(i->N, dir) > 0)
			i->N = mult_vec(i->N, -1);
	}
	return (i->d);
}
