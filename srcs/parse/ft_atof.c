/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:45:58 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/17 04:07:08 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdio.h>

static	int	integer_part(const char *str, int *sign, char *error)
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
		*error = 1;
	return (nb);
}

static	int	ft_int_length(int nb)
{
	int count;

	count = 1;
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

double		ft_atof(const char *str, char *error)
{
	double	nb;
	int		count;
	int		sign;

	nb = integer_part(str, &sign, error);
	count = 10;
	str += ft_int_length(nb);
	if (*str == ',' || *str == ' ')
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
