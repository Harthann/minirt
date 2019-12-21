/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:24:43 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 12:56:01 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

int		initiate(t_scene scene)
{
	t_cam	*cam;
	t_img	*img;
	int		i;

	cam = scene.cam;
	img = scene.image;
	i = 0;
	while (cam)
	{
		if (!(draw_image(scene, img->cam, &img->image)))
			return (-1);
		cam = cam->next;
		img = img->next;
	}
	mlx_put_image_to_window(scene.win.mlx_ptr,
	scene.win.mlx_win, scene.image->ptr, 0, 0);
	return (0);
}
