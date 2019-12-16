/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:11:53 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 19:08:56 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_sphere	*new_sphere(const char *str)
{
	t_sphere	*sphere;
	char		error;
	int			count;

	error = 0;
	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&sphere->center, str, &error);
	sphere->radius = ft_atof(str, &error);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	count = get_color(&sphere->color, str);
	(count < 0) ? error = 1 : 0;
	str += count;
	sphere->speed = ft_atoi(str);
	sphere->next = NULL;
	return (error ? NULL : sphere);
}

void				set_sphere(t_scene *scene, const char *str)
{
	t_sphere *obj;

	obj = scene->obj.sphere;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_sphere(str)))
			ft_error("Parsing error for sphere.\n", scene);
	}
	else
	{
		if (!(scene->obj.sphere = new_sphere(str)))
			ft_error("Parsing error for sphere.\n", scene);
	}
}
