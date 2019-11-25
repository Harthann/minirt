/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:11:53 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/24 19:04:50 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static t_light *new_light(const char *str)
{
	t_light *light;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&light->pos, str);
	light->intensity = ft_atof(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_color(&light->color, str);
	light->next = NULL;
	return (light);
}

void	set_light(t_scene *scene, const char *str)
{
	t_light *obj;
	
	obj = scene->obj.light;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
		obj->next = new_light(str);
	else
		scene->obj.light = new_light(str);
}
