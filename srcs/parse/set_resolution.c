/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:09:58 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/10 16:18:39 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	set_resolution(t_scene *scene, const char *str)
{
	while (*str && !(*str >= '0' && *str <= '9'))
		str++;
	scene->win.width = ft_atoi(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	scene->win.heigth = ft_atoi(str);
}