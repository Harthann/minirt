/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:41:33 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/19 18:33:44 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

static void	parse_line(t_scene *scene, char *str)
{
	int	i;

	i = 0;
	if (*str == 'R')
		init_resolution(scene, str);
}

t_scene		parse_file(char *str)
{
	t_scene scene;
	int		success;
	char	*line;
	int		fd;

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
