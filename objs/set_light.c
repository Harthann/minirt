/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:11:53 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:53:17 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_light	*new_light(const char *str)
{
	t_light *light;
	char	error;

	error = 0;
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&light->pos, str, &error);
	light->intensity = ft_atof(str, &error);
	while (*str && ((*str >= '0' && *str <= '9') || *str == '.'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_color(&light->color, str) < 0 ? error = 1 : 0;
	light->next = NULL;
	return (error ? NULL : light);
}

void			set_light(t_scene *scene, const char *str)
{
	t_light *obj;

	obj = scene->obj.light;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_light(str)))
			ft_error("Parsing error for light.\n", scene);
	}
	else
	{
		if (!(scene->obj.light = new_light(str)))
			ft_error("Parsing error for light.\n", scene);
	}
}
