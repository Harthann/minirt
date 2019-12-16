/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:32:26 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 15:53:08 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <unistd.h>

void __attribute__((destructor)) no_end();

void	no_end(void)
{
	while (1)
		;
}

static t_img		*create_image(t_window win, t_cam *cam)
{
	t_img	*i;

	if (!(i = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(i->ptr = mlx_new_image(win.mlx_ptr, win.width, win.heigth)))
		return (NULL);
	if (!(i->image = (int*)mlx_get_data_addr(i->ptr, &i->bpp,
		&i->size, &i->endian)))
		return (NULL);
	if (cam)
		i->cam = *cam;
	else
		ft_bzero(&i->cam, sizeof(t_cam));
	i->next = NULL;
	i->end = 0;
	return (i);
}

void				add_back(t_img **images, t_img *new)
{
	t_img *tmp;

	if (!*images)
		*images = new;
	else
	{
		tmp = *images;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static int			browse_image(t_scene *scene)
{
	t_cam	*tmp;
	t_img	*memo;

	tmp = scene->cam;
	while (tmp)
	{
		memo = create_image(scene->win, tmp);
		add_back(&scene->image, memo);
		tmp = tmp->next;
	}
	memo->next = scene->image;
	memo->end = 1;
	return (0);
}

int					main(int ac, char **av)
{
	t_scene scene;

	if (ac == 2 || ac == 3)
		scene = parse_file(av[1]);
	else
	{
		write(1, "No input file\n", 14);
		return (-1);
	}

	browse_image(&scene);
	initiate(scene);
	if (ac == 3 && !ft_strncmp(av[2], "-save", 5))
		screenshot(scene, av[1]);
	else
	{
		mlx_hook(scene.win.mlx_win, 17, 0, close_win, &scene);
		mlx_hook(scene.win.mlx_win, 2, 0, key_control, &scene);
		mlx_loop_hook(scene.win.mlx_ptr, rotation, &scene);
		mlx_loop(scene.win.mlx_ptr);
	}
	ft_free(&scene);
	mlx_destroy_window(scene.win.mlx_ptr, scene.win.mlx_win);
	return (0);
}
