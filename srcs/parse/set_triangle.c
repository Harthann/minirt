/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:02:19 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/10 16:17:12 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_triangle	*new_triangle(const char *str)
{
	t_triangle *triangle;

	if (!(triangle = (t_triangle*)malloc(sizeof(t_triangle))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&triangle->vertex1, str);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&triangle->vertex2, str);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&triangle->vertex3, str);
	get_color(&triangle->color, str);
	triangle->next = NULL;
	return (triangle);
}

void				set_triangle(t_scene *scene, const char *str)
{
	t_triangle *obj;

	obj = scene->obj.triangle;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
		obj->next = new_triangle(str);
	else
		scene->obj.triangle = new_triangle(str);
}
