/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:31:56 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 12:57:00 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_cyl(t_cyl *obj)
{
	if (obj)
	{
		if (obj->next)
			free_cyl(obj->next);
		free(obj);
	}
}

void	free_sphere(t_sphere *obj)
{
	if (obj)
	{
		if (obj->next)
			free_sphere(obj->next);
		free(obj);
	}
}

void	free_plan(t_plan *obj)
{
	if (obj)
	{
		if (obj->next)
			free_plan(obj->next);
		free(obj);
	}
}

void	free_triangle(t_triangle *obj)
{
	if (obj)
	{
		if (obj->next)
			free_triangle(obj->next);
		free(obj);
	}
}

void	free_square(t_square *obj)
{
	if (obj)
	{
		if (obj->next)
			free_square(obj->next);
		free(obj);
	}
}
