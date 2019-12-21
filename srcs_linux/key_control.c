/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:18:55 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 17:29:19 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

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

static void	print_vec(t_p vec)
{
	double	ipart;
	double	dpart;

	ipart = (int)vec.x;
	dpart = vec.x - ipart;
	dpart *= dpart < 0 ? -1 : 1;
	ft_putnbr_fd((int)ipart, 1);
	write(1, ".", 1);
	ft_putnbr_fd(dpart * 100000, 1);
	write(1, " ", 1);
	ipart = (int)vec.y;
	dpart = vec.y - ipart;
	dpart *= dpart < 0 ? -1 : 1;
	ft_putnbr_fd((int)ipart, 1);
	write(1, ".", 1);
	ft_putnbr_fd(dpart * 100000, 1);
	write(1, " ", 1);
	ipart = (int)vec.z;
	dpart = vec.z - ipart;
	dpart *= dpart < 0 ? -1 : 1;
	ft_putnbr_fd((int)ipart, 1);
	write(1, ".", 1);
	ft_putnbr_fd(dpart * 100000, 1);
	write(1, "\n", 1);
}

int			key_control(int key, t_scene *scene)
{
//	printf("[%d]\n", key);
	if (key == 65307)
		close_win(scene);
	if (key == 45)
		next_image(scene);
	if (key == 69 || key == 78 || key == 67)
		fov_control(scene, key);
	if (key == 122 || key == 113 || key == 115 || key == 100)
		cam_control(scene, key);
	if (key == 65362 || key == 65361 || key == 65364 || key == 65363 || key == 32 || key == 49)
		cam_control(scene, key);
	if (key == 112)
		scene->rotation = !scene->rotation;
	if (key == 17)
		screenshot(*scene, scene->name);
	if (key == 9)
		print_vec(scene->image->cam.vector);
	if (key == 7)
		print_vec(scene->image->cam.pos);
	return (1);
}
