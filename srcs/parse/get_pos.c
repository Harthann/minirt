/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:02:09 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 17:26:42 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int		get_pos(t_p *vector, const char *str)
{
	int i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9') && *str != '-')
		ft_error("Wrong position setting\n", NULL);
	vector->x = ft_atof(str);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	vector->y = ft_atof(str + i);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	vector->z = ft_atof(str + i);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}
