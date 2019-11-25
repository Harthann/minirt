/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:57:54 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/25 09:26:30 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include<unistd.h>

void	set_cam(t_scene *scene, const char *str)
{
	while (*str && (!((*str >= '0' && *str <= '9') || *str == '-')))
		str++;
	str += get_pos(&scene->cam.pos, str);
	// while (*str && *str != ' ')
		// str++;
	get_pos(&scene->cam.vector, str);
}