/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:35:08 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 12:54:00 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

static void	init_win(t_window *win)
{
	win->mlx_ptr = NULL;
	win->mlx_win = NULL;
	win->heigth = 0;
	win->width = 0;
	win->fov = 90;
}

// static void	init_cam(t_cam *cam)
// {
// 	cam->pos.x = 0;
// 	cam->pos.y = 0;
// 	cam->pos.z = 0;
// 	cam->vector.x = 0;
// 	cam->vector.y = 0;
// 	cam->vector.z = 0;
// 	cam->next = NULL;
// }

static void	init_ambient(t_light *light)
{
	light->intensity = 0;
	light->color.R = 0;
	light->color.G = 0;
	light->color.B = 0;
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
}

static void init_objs(t_obj *obj)
{
	obj->sphere = NULL;
	obj->square = NULL;
	obj->cyl = NULL;
	obj->plan = NULL;
	obj->triangle = NULL;
	obj->light = NULL;
}

void	init_scene(t_scene *scene)
{
	init_win(&scene->win);
	// init_cam(scene->cam);
	init_ambient(&scene->ambient);
	init_objs(&scene->obj);

	scene->cam = NULL;
	scene->image = NULL;
}