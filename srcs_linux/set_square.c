/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:07:30 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 18:51:28 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_square	*new_square(const char *str)
{
	t_square	*square;
	char		error;

	error = 0;
	if (!(square = (t_square*)malloc(sizeof(t_square))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&square->pos, str, &error);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&square->vector, str, &error);
	square->vector = norm_vec(square->vector);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	square->heigth = ft_atof(str, &error);
	while (*str && ((*str >= '0' && *str <= '9') || *str == '-'))
		str++;
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	get_color(&square->color, str);
	square->next = NULL;
	return (square);
}

void				set_square(t_scene *scene, const char *str)
{
	t_square *obj;

	obj = scene->obj.square;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_square(str)))
			ft_error("Parsing error for square.\n", scene);
	}
	else
	{
		if (!(scene->obj.square = new_square(str)))
			ft_error("Parsing error for square.\n", scene);
	}
}
