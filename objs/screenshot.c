/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:04:30 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 12:51:28 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <sys/stat.h>

static void	init_header(t_scene scene, t_header *header)
{
	header->type = 0x4d42;
	header->size = 54 + 4 * scene.win.heigth * scene.win.width;
	header->start = 54;
	header->header_size = 40;
	header->planes = 1;
	header->bpp = 32;
	header->raw_size = 4 * scene.win.heigth * scene.win.width;
	header->res = 2835;
}

static void	create_header(t_scene scene, char *header)
{
	t_header head;

	ft_bzero(header, 54);
	init_header(scene, &head);
	ft_memcpy(&header[0], &head.type, 2);
	ft_memcpy(&header[2], &head.size, 4);
	ft_memcpy(&header[10], &head.start, 4);
	ft_memcpy(&header[14], &head.header_size, 4);
	ft_memcpy(&header[18], &scene.win.width, 4);
	ft_memcpy(&header[22], &scene.win.heigth, 4);
	ft_memcpy(&header[26], &head.planes, 2);
	ft_memcpy(&header[28], &head.bpp, 2);
	ft_memcpy(&header[34], &head.raw_size, 4);
	ft_memcpy(&header[38], &head.res, 4);
	ft_memcpy(&header[42], &head.res, 4);
}

static	int	*fill_file(t_scene scene)
{
	int *file;
	int	i;
	int	j;
	int k;

	if (!(file = ft_calloc(scene.win.heigth * scene.win.width, sizeof(int))))
		return (NULL);
	j = 0;
	while (j < scene.win.heigth)
	{
		i = 0;
		while (i < scene.win.width)
		{
			k = (scene.win.heigth - 1 - j) * scene.image->size / 4 + i;
			file[k] = scene.image->image[i + (j * scene.image->size / 4)];
			i++;
		}
		j++;
	}
	return (file);
}

void		screenshot(t_scene scene, char *name)
{
	int		fd;
	char	*file;
	char	header[54];
	void	*to_free;

	fd = ft_strlen(name);
	name[fd - 3] = '\0';
	while (*name && *name != '/')
		name++;
	name++;
	name = ft_strjoin("screenshot/", name);
	to_free = name;
	name = ft_strjoin(name, ".bmp");
	free(to_free);
	fd = open(name, O_CREAT | O_WRONLY, 0666);
	create_header(scene, &header[0]);
	file = (char*)fill_file(scene);
	write(fd, header, 54);
	write(fd, file, 4 * scene.win.heigth * scene.win.width);
	free(file);
	free(name);
	close(fd);
}
