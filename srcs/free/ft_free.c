/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:19:05 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 17:13:34 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_obj(t_obj obj)
{
	obj.cyl ? free_cyl(obj.cyl) : 0;
	obj.plan ? free_plan(obj.plan) : 0;
	obj.sphere ? free_sphere(obj.sphere) : 0;
	obj.square ? free_square(obj.square) : 0;
	obj.triangle ? free_triangle(obj.triangle) : 0;
	obj.light ? free_light(obj.light) : 0;
}

void	ft_free(t_scene *scene)
{
	if (scene)
	{
		free_obj(scene->obj);
		free_cam(scene->cam);
		free_image(scene->image);
	}
}
