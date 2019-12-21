/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_speed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:04:22 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/17 16:13:12 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int		get_speed(int *speed, const char *str, char *error)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	*speed = ft_atoi(str);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		*error = 1;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	return (i);
}
