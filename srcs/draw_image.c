/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:25:10 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/24 19:14:22 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <math.h>

// static void	print_vec(t_point a, char *name)
// {
// 	printf("%-9s\t:\t[%f]\t[%f]\t[%f]\n",name, a.x,a.y,a.z);
// }

void	draw_image(t_scene *scene)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < scene->win.width)
	{
		j = 0;
		while (j < scene->win.heigth)
		{
			scene->image.image[j + i * scene->win.heigth] = raytrace(scene, i, j);
			j++;
		}
		i++;
	}
}
