/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:11:53 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 14:22:09 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_sphere	*new_sphere(const char *str)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&sphere->center, str);
	sphere->radius = ft_atof(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	str += get_color(&sphere->color, str);
	sphere->speed = ft_atoi(str);
	sphere->next = NULL;
	return (sphere);
}

void				set_sphere(t_scene *scene, const char *str)
{
	t_sphere *obj;

	obj = scene->obj.sphere;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
		obj->next = new_sphere(str);
	else
		scene->obj.sphere = new_sphere(str);
}
