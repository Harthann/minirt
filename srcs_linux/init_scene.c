/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:35:08 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 18:49:13 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

static	void	init_win(t_window *win)
{
	win->mlx_ptr = NULL;
	win->mlx_win = NULL;
	win->heigth = 600;
	win->width = 600;
	win->fov = 90;
}

static	void	init_ambient(t_light *light)
{
	light->intensity = 0;
	light->color.r = 0;
	light->color.g = 0;
	light->color.b = 0;
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
}

static	void	init_objs(t_obj *obj)
{
	obj->sphere = NULL;
	obj->square = NULL;
	obj->cyl = NULL;
	obj->plan = NULL;
	obj->triangle = NULL;
	obj->light = NULL;
}

void			init_scene(t_scene *scene)
{
	init_win(&scene->win);
	init_ambient(&scene->ambient);
	init_objs(&scene->obj);
	scene->cam = NULL;
	scene->image = NULL;
	scene->rotation = 0;
}
