/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:21:52 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:16:03 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	get_color(t_color *color, const char *str)
{
	int i;

	i = 0;
	color->r = (str[i] >= '0' && str[i] <= '9') ? ft_atoi(str + i) : -1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != ',')
		return (-1);
	i++;
	color->g = (str[i] >= '0' && str[i] <= '9') ? ft_atoi(str + i) : -1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != ',')
		return (-1);
	i++;
	color->b = (str[i] >= '0' && str[i] <= '9') ? ft_atoi(str + i) : -1;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	if (color->r <= -1 || color->g <= -1 || color->b <= -1)
		i = -1;
	if (color->r > 255 || color->g > 255 || color->b > 255)
		i = -1;
	return (i);
}
