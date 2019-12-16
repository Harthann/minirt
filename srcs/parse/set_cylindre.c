/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:32:06 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 18:59:43 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static	t_cyl	*new_cylindre(const char *str)
{
	t_cyl	*cyl;
	char	error;

	error = 0;
	if (!(cyl = (t_cyl*)malloc(sizeof(t_cyl))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&cyl->pos, str, &error);
	str += get_pos(&cyl->vec, str, &error);
	cyl->vec = norm_vec(cyl->vec);
	cyl->radius = ft_atof(str, &error);
	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	cyl->heigth = ft_atof(str, &error);
	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_color(&cyl->color, str) < 0 ? error = 1 : 0;
	cyl->next = NULL;
	return (error ? NULL : cyl);
}

void			set_cylindre(t_scene *scene, const char *str)
{
	t_cyl *obj;

	obj = scene->obj.cyl;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
	{
		if (!(obj->next = new_cylindre(str)))
			ft_error("Parsing error for cylindre.\n", scene);
	}
	else
	{
		if (!(scene->obj.cyl = new_cylindre(str)))
			ft_error("Parsing error for cylindre.\n", scene);
	}
}
