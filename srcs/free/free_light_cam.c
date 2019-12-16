/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light_cam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:37:32 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 12:56:34 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_cam(t_cam *cam)
{
	if (cam)
	{
		if (cam->next)
			free_cam(cam->next);
		free(cam);
	}
}

void	free_light(t_light *light)
{
	if (light)
	{
		if (light->next)
			free_light(light->next);
		free(light);
	}
}
