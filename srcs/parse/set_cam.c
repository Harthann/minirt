/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:57:54 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 16:21:44 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>

static	t_cam	*new_cam(const char *str)
{
	t_cam	*cam;
	int		count;

	count = 0;
	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	while (*str && (!((*str >= '0' && *str <= '9') || *str == '-')))
		str++;
	if ((count = get_pos(&cam->pos, str) < 0))
		return (NULL);
	str += count;
	if ((get_pos(&cam->vector, str)) < 0)
		return (NULL);
	str += count;
	cam->next = NULL;
	return (cam);
}

void			set_cam(t_scene *scene, const char *str)
{
	t_cam *obj;

	obj = scene->cam;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_cam(str)))
			ft_error("Parsing error for camera\n", scene);
	}
	else
	{
		if (!(scene->cam = new_cam(str)))
			ft_error("Parsing error for camera\n", scene);
	}
}
