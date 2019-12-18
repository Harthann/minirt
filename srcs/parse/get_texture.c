/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:09:59 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/18 15:00:18 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include <mlx.h>

t_tex	get_texture(char *str, t_scene scene)
{
	t_tex	texture;
	int		tmp;

	texture.ptr = mlx_xpm_file_to_image(scene.win.mlx_ptr,
	str, &texture.width, &texture.heigth);
	if (texture.ptr)
	{
		texture.texture = (int*)mlx_get_data_addr(texture.ptr, &tmp, &texture.width, &tmp);
		texture.width = texture.width / 4;
	}
	return (texture);
}
