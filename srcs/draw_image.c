/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:25:10 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 00:42:46 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>
#include <pthread.h>

void	*draw_thread1(void *ptr)
{
	t_thread *scene;
	int i;
	int j;

	scene = (t_thread*)ptr;
	i = 0;
	j = 0;
	while (i < scene->scene->win.width / 2)
	{
		j = 0;
		while (j < scene->scene->win.heigth / 2)
		{
			scene->img[0][j + i * scene->scene->win.heigth] = raytrace(scene->scene, i, j, scene->cam);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*draw_thread2(void *ptr)
{
	t_thread *scene;
	int i;
	int j;

	scene = (t_thread*)ptr;
	i = scene->scene->win.width / 2;
	while (i < scene->scene->win.width)
	{
		j = 0;
		while (j < scene->scene->win.heigth / 2)
		{
			scene->img[0][j + i * scene->scene->win.heigth] = raytrace(scene->scene, i, j, scene->cam);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*draw_thread3(void *ptr)
{
	t_thread *scene;
	int i;
	int j;

	scene = (t_thread*)ptr;
	i = 0;
	while (i < scene->scene->win.width / 2)
	{
		j = scene->scene->win.heigth / 2;
		while (j < scene->scene->win.heigth)
		{
			scene->img[0][j + i * scene->scene->win.heigth] = raytrace(scene->scene, i, j, scene->cam);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*draw_thread4(void *ptr)
{
	t_thread *scene;
	int i;
	int j;

	scene = (t_thread*)ptr;
	i = scene->scene->win.width / 2;
	while (i < scene->scene->win.width)
	{
		j = scene->scene->win.heigth / 2;
		while (j < scene->scene->win.heigth)
		{
			scene->img[0][j + i * scene->scene->win.heigth] = raytrace(scene->scene, i, j, scene->cam);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	draw_image(t_scene scene, t_cam cam, int **img)
{
	t_thread thread;
	
	thread.cam = cam;
	thread.img = img;
	thread.scene = &scene;
	pthread_create(&thread.thread[0], NULL, draw_thread1, &thread);
	pthread_create(&thread.thread[1], NULL, draw_thread3, &thread);
	pthread_create(&thread.thread[2], NULL, draw_thread2, &thread);
	pthread_create(&thread.thread[3], NULL, draw_thread4, &thread);
	
	pthread_join (thread.thread[0], NULL);
	pthread_join (thread.thread[1], NULL);
	pthread_join (thread.thread[2], NULL);
	pthread_join (thread.thread[3], NULL);
}
