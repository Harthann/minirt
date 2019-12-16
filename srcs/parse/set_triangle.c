/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:02:19 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:08:27 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_triangle	*new_triangle(const char *str)
{
	t_triangle	*triangle;
	char		error;

	error = 0;
	if (!(triangle = (t_triangle*)malloc(sizeof(t_triangle))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&triangle->vertex1, str, &error);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&triangle->vertex2, str, &error);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&triangle->vertex3, str, &error);
	get_color(&triangle->color, str) < 0 ? error = 1 : 0;
	triangle->next = NULL;
	return (error ? NULL : triangle);
}

void				set_triangle(t_scene *scene, const char *str)
{
	t_triangle *obj;

	obj = scene->obj.triangle;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_triangle(str)))
			ft_error("Parsing error for triangle.\n", scene);
	}
	else
	{
		if (!(scene->obj.triangle = new_triangle(str)))
			ft_error("Parsing error for triangle.\n", scene);
	}
}
