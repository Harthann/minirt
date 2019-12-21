/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:34:51 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:00:09 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_plan	*new_plan(const char *str)
{
	t_plan	*plan;
	char	error;

	error = 0;
	if (!(plan = (t_plan*)malloc(sizeof(t_plan))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&plan->origin, str, &error);
	str += get_pos(&plan->vector, str, &error);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_color(&plan->color, str) < 0 ? error = 1 : 0;
	plan->next = NULL;
	return (error ? NULL : plan);
}

void			set_plan(t_scene *scene, const char *str)
{
	t_plan *obj;

	obj = scene->obj.plan;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_plan(str)))
			ft_error("Parsing error for plan.\n", scene);
	}
	else
	{
		if (!(scene->obj.plan = new_plan(str)))
			ft_error("Parsing error for plan.\n", scene);
	}
}
