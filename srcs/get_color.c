/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:21:52 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/27 18:01:16 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	get_color(t_color *color, const char *str)
{
	color->R = (*str >= '0' && *str <= '9') ? ft_atoi(str) : -1;
	while (*str >= '0' && *str <= '9')
		str++;
	str++;
	color->G = (*str >= '0' && *str <= '9') ? ft_atoi(str) : -1;
	while (*str >= '0' && *str <= '9')
		str++;
	str++;
	color->B = (*str >= '0' && *str <= '9') ? ft_atoi(str) : -1;
	while (*str >= '0' && *str <= '9')
		str++;
	str++;
}