/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:41:33 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 00:40:20 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

static void	parse_line(t_scene *scene, const char *str)
{
	int	i;

	i = 0;
	if (*str == 'R')
		set_resolution(scene, str);
	else if(*str == 'A')
		set_ambient_light(scene, str);
	else if(*str == 'l')
		set_light(scene, str);
	else if(*str == 'c' && *(str + 1) == 'y')
		set_cylindre(scene, str);
	else if(*str == 'c')
		set_cam(scene, str);
	else if(*str == 's' && *(str + 1) == 'p')
		set_sphere(scene, str);
	else if(*str == 'p' && *(str + 1) == 'l')
		set_plan(scene, str);
}

t_scene		parse_file(char *str)
{
	t_scene scene;
	int		success;
	char	*line;
	int		fd;

	init_scene(&scene);
	success = 1;
	fd = open(str, O_RDONLY);
	while (success > 0)
	{
		success = get_next_line(fd, &line);
		parse_line(&scene, line);
		free(line);
	}
	return (scene);
}
