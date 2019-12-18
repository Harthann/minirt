/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:55:56 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 18:35:02 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		set_skybox(t_scene *scene, const char *str)
{
	static char count = 0;

	if (count)
		ft_error("Only one skybox allowed, sorry!\n", scene);
	str += 2;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	scene->skybox = get_texture((char*)str, *scene);
	count++;
}
