/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:09:58 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 20:03:56 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	set_resolution(t_scene *scene, const char *str)
{
	static char count = 0;

	if (count)
		ft_error("Resolution already set, please choose only one!\n", scene);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	scene->win.width = ft_atoi(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	while (*str && (*str >= '0' && *str <= '9') && *str != '-')
		str++;
	scene->win.heigth = ft_atoi(str);
	printf("[%d] [%d]\n", scene->win.heigth, scene->win.width);
	if (scene->win.heigth <= 0 || scene->win.width <= 0)
		ft_error("Incorrect resolution number\n", scene);
	if (scene->win.heigth != scene->win.width)
		ft_error("Resolution numbers not equal.\n", scene);
	count++;
}
