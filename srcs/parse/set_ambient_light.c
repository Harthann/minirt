/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:18 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:53:06 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	set_ambient_light(t_scene *scene, const char *str)
{
	static char count = 0;
	char		error;

	error = 0;
	if (count)
		ft_error("Ambient light already set, please choose only one!\n", scene);
	while (*str && !(*str >= '0' && *str <= '9'))
		str++;
	scene->ambient.intensity = ft_atof(str, &error);
	while ((*str >= '0' && *str <= '9') || *str == '.')
		str++;
	while (*str && !(*str >= '0' && *str <= '9'))
		str++;
	get_color(&(scene->ambient.color), str) < 0 ? error = 1 : 0;
	scene->ambient.next = NULL;
	count++;
	if (error)
		ft_error("Parsing error for Ambient Light.\n", scene);
}
