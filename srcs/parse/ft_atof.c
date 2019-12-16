/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:45:58 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 15:02:50 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdio.h>

int		integer_part(const char *str, int *sign)
{
	int		nb;

	nb = 0;
	*sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	if (*str != '.' && *str != ',' && *str != ' '
		&& *str != '\t' && *str != '\0')
		ft_error("Wrong number setting\n", NULL);
	return (nb);
}

double	ft_atof(const char *str)
{
	double	nb;
	int		count;
	int		sign;

	nb = integer_part(str, &sign);
	count = 10;
	while (*str && *str != '.' && *str != ',' && *str != ' ' && *str != '\t')
		str++;
	if (*str == ',')
		return (nb * sign);
	str++;
	while (*str && ((*str >= '0' && *str <= '9')))
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
