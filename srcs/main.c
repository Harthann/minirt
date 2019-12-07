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

// __attribute__((destructor)) void no_end(void);



static t_img		*create_image(t_window win, t_cam *cam)
{
	t_img	*i;

	if (!(i = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(i->ptr = mlx_new_image(win.mlx_ptr, win.width, win.heigth)))
		return (NULL);
	if (!(i->image = (int*)mlx_get_data_addr(i->ptr, &i->bpp, &i->size, &i->endian)))
		return (NULL);
	(void)cam;

	if (cam)
		i->cam = *cam;
	else
		ft_bzero(&i->cam, sizeof(t_cam));
	i->next = NULL;
	i->end = 0;
	return (i);
}

void		add_back(t_img **images, t_img *new)
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

static int		browse_image(t_scene *scene)
{
	t_cam	*tmp;
	t_img	*memo;

	tmp = scene->cam;
	// while (scene->cam)
	// {
	// 	scene->cam = scene->cam->next;
	// }
	while (tmp)
	{
		memo = create_image(scene->win, tmp);
		add_back(&scene->image, memo);
		tmp = tmp->next;
	}
	// if (!count)
	// 	ft_error(scene, "No Camera found");
	memo->next = scene->image;
	memo->end = 1;
	// while (memo)
	// {
	// 	printf("[%p]\n", memo);
	// 	memo = memo->next;
	// }
	return (0);	
}

int main(int ac, char **av)
{
    t_scene scene;

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
	initiate(scene);
    return (0);
} 

// void no_end(){
// 	while (1);
// }