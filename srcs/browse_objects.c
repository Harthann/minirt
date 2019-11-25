/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:15:46 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/25 16:21:12 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

int		browse_sphere(t_cam cam, t_sphere *sphere, t_point dir, t_inter *i)
{
	double tmp;

	i->color.R = 0;
	i->color.G = 0;
	i->color.B = 0;
	while (sphere)
	{
		tmp = inter_sphere(cam, *sphere, dir);
		i->d = i->d == -1 && tmp != -1 ? tmp : i->d;
		if (tmp != -1 && tmp <= i->d)
		{
				i->d = tmp;
				i->color = sphere->color;
				i->N = shift_vec(shift_vec(cam.pos, dir, i->d, '+') , sphere->center, 1, '-');
				i->N = norm_vec(i->N);
		}
		sphere = sphere->next;
	}
	return (i->d);
}
