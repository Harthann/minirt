/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:02:09 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:07:01 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int		get_pos(t_p *vector, const char *str, char *error)
{
	int i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9') && *str != '-')
		*error = 1;
	vector->x = ft_atof(str, error);
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] != ',')
		*error = 1;
	i++;
	vector->y = ft_atof(str + i, error);
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] != ',')
		*error = 1;
	i++;
	vector->z = ft_atof(str + i, error);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}
