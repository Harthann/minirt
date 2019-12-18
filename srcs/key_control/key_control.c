/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:18:55 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 15:49:08 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			close_win(t_scene *scene)
{
	mlx_destroy_window(scene->win.mlx_ptr, scene->win.mlx_win);
	ft_free(scene);
	exit(0);
}

void		next_image(t_scene *scene)
{
	scene->image = scene->image->next;
	mlx_put_image_to_window(scene->win.mlx_ptr,
	scene->win.mlx_win, scene->image->ptr, 0, 0);
}

void		fov_control(t_scene *scene, int key)
{
	if (key == 67)
		scene->win.fov = 90;
	else
		scene->win.fov += key == 69 ? 5 : -5;
	draw_image(*scene, scene->image->cam, &scene->image->image);
	mlx_put_image_to_window(scene->win.mlx_ptr,
	scene->win.mlx_win, scene->image->ptr, 0, 0);
}

int			key_control(int key, t_scene *scene)
{
	if (key == 53)
		close_win(scene);
	if (key == 45)
		next_image(scene);
	if (key == 69 || key == 78 || key == 67)
		fov_control(scene, key);
	if (key >= 123 && key <= 126)
		cam_control(scene, key);
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 8 || key == 49)
		cam_control(scene, key);
	if (key == 35)
		scene->rotation = !scene->rotation;
	if (key == 17)
		screenshot(*scene, scene->name);
	if (key == 9)
		printf("[%f] [%f] [%f]\n", scene->cam->vector.x, scene->cam->vector.y, scene->cam->vector.z);
	return (1);
}
