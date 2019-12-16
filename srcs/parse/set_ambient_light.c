/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:40:18 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/14 18:22:03 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	set_ambient_light(t_scene *scene, const char *str)
{
	while (*str && !(*str >= '0' && *str <= '9'))
		str++;
	scene->ambient.intensity = ft_atof(str);
	while ((*str >= '0' && *str <= '9') || *str == '.')
		str++;
	while (*str && !(*str >= '0' && *str <= '9'))
		str++;
	get_color(&(scene->ambient.color), str);
	scene->ambient.next = NULL;
}
