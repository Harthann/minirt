/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:57:54 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 00:38:39 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include<unistd.h>

static t_cam *new_cam(const char *str)
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);

	while (*str && (!((*str >= '0' && *str <= '9') || *str == '-')))
		str++;
	str += get_pos(&cam->pos, str);
	// while (*str && *str != ' ')
		// str++;
	get_pos(&cam->vector, str);
	cam->next = NULL;
	return (cam);
}

void	set_cam(t_scene *scene, const char *str)
{
	t_cam *obj;
	
	obj = scene->cam;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
		obj->next = new_cam(str);
	else
		scene->cam = new_cam(str);
}