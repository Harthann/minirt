/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:55:56 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 17:06:11 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		set_skybox(t_scene *scene, const char *str)
{
	str += 2;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	scene->skybox = get_texture((char*)str, *scene);
}