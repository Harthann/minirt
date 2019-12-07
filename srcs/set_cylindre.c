/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:32:06 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/30 11:03:36 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

static t_cyl *new_cylindre(const char *str)
{
	t_cyl *cyl;


	if (!(cyl = (t_cyl*)malloc(sizeof(t_cyl))))
		return (NULL);
	while (*str && !(*str >= '0' && *str <= '9') && *str != '-')
		str++;
	str += get_pos(&cyl->pos, str);
	str += get_pos(&cyl->vec, str);
	cyl->radius = ft_atof(str);
	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	cyl->heigth = ft_atof(str);
	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_color(&cyl->color, str);
	cyl->next = NULL;
	return (cyl);
}

void	set_cylindre(t_scene *scene, const char *str)
{
	t_cyl *obj;
	
	obj = scene->obj.cyl;
	while (obj && obj->next)
		obj = obj->next;
	if (obj)
		obj->next = new_cylindre(str);
	else
		scene->obj.cyl = new_cylindre(str);
}
