// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:32:26 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/22 17:02:38 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <unistd.h>

int		ft_exit(int key, t_scene *scene)
{
	// printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(scene->win.mlx_ptr, scene->win.mlx_win);
		exit(0);
	}
	return (1);
}

static t_img		*create_image(t_window win)
{
	t_img	*i;

	if (!(i = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(i->ptr = mlx_new_image(win.mlx_ptr, win.width, win.heigth)))
		return (NULL);
	if (!(i->image = (int*)mlx_get_data_addr(i->ptr, &i->bpp, &i->size, &i->endian)))
		return (NULL);
	return (i);
}

static int		browse_image(t_scene *scene)
{
	scene->image = *create_image(scene->win);
	return (0);	
}

int main(int ac, char **av)
{
    t_scene scene;

	init_scene(&scene);
	if (ac == 2 || ac == 3)
	{
		scene = parse_file(av[1]);
	}
	else
	{
		write(1, "No input file\n", 14);
		return (-1);
	}
    if ((scene.win.mlx_ptr = mlx_init()) == NULL)
        return (-1);
    if ((scene.win.mlx_win = mlx_new_window(scene.win.mlx_ptr, scene.win.width, scene.win.heigth, "miniRT")) == NULL)
        return (-1);
	browse_image(&scene);
	draw_image(&scene);
	mlx_put_image_to_window(scene.win.mlx_ptr, scene.win.mlx_win, scene.image.ptr, 0, 0);
	mlx_key_hook(scene.win.mlx_win, ft_exit, &scene);
	mlx_loop(scene.win.mlx_ptr);
    return (0);
} 
