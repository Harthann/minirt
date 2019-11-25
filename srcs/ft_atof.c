/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:45:58 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/24 15:32:01 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
double	ft_atof(const char *str)
{
	double	nb;
	int		count;
	int		sign;

	nb = ft_atoi(str);
	count = 10;
	sign = nb < 0 ? -1 : 1;
	nb = sign * nb;
	while (*str && *str != '.' && *str != ',' && *str != ' ' && *str != '\t')
		str++;
	while (*str && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
		if (*str >= '0' && *str <= '9')
		{
			nb = nb + ((double)(*str - '0') / count);
			count *= 10;
		}
		str++;
	}
	return (nb * sign);
}
