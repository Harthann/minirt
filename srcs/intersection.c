/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:33:27 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/30 11:05:15 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "libft.h"


double		check_intersection(t_scene *scene, t_point dir, t_point pos, t_inter *i)
{
	double	d;

	i->d = -1;
	d = -1;
	d = browse_sphere(pos, scene->obj.sphere, dir, i);
	d = browse_plan(pos, scene->obj.plan, dir, i);
	d = browse_cylindre(pos, scene->obj.cyl, dir, i);
	return (d);
}
