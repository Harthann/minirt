/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:24:43 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 00:46:52 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

int		ft_exit(int key, t_scene *scene)
{
	// printf("[%d]\n", key);
	if (key == 53)
	{
		mlx_destroy_window(scene->win.mlx_ptr, scene->win.mlx_win);
		exit(0);
	}
	if (key == 45)
	{
		scene->image = scene->image->next;
		mlx_put_image_to_window(scene->win.mlx_ptr, scene->win.mlx_win, scene->image->ptr, 0, 0);
	}
	// if (key == 69 || key == 78)
	// {
	// 	scene->win.fov += key == 69 ? 5 : -5;
	// 	draw_image(scene);
	// 	mlx_put_image_to_window(scene->win.mlx_ptr, scene->win.mlx_win, scene->image->ptr, 0, 0);
	// }
	// if (key >= 123 && key <= 126)
	// {
	// 	if (key == 123 || key == 124)
	// 		scene->cam->vector.x += key == 123 ? -0.1 : 0.1;
	// 	if (key == 125 || key == 126)
	// 		scene->cam->vector.y += key == 125 ? -0.1 : 0.1;
	// 	draw_image(scene);
	// 	mlx_put_image_to_window(scene->win.mlx_ptr, scene->win.mlx_win, scene->image->ptr, 0, 0);
	// }
	// if (key == 0 || key == 1 || key == 2 || key == 13)
	// {
	// 	if (key == 13 || key == 1)
	// 		scene->cam->pos.z += key == 1 ? -5 : 5;
	// 	if (key == 0 || key == 2)
	// 		scene->cam->pos.x += key == 2 ? 5 : -5;
	// 	draw_image(scene);
	// 	mlx_put_image_to_window(scene->win.mlx_ptr, scene->win.mlx_win, scene->image->ptr, 0, 0);
	// }
	return (1);
}

void	initiate(t_scene scene)
{
	t_cam	*cam;
	t_img	*img;

	cam = scene.cam;
	img = scene.image;

	while (cam)
	{
		draw_image(scene, *cam, &img->image);
		cam = cam->next;
		img = img->next;
	}
	mlx_put_image_to_window(scene.win.mlx_ptr, scene.win.mlx_win, scene.image->ptr, 0, 0);
	mlx_hook(scene.win.mlx_win, 2, 0, ft_exit, &scene);
	mlx_loop(scene.win.mlx_ptr);
}