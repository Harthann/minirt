/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:42:14 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/27 18:01:15 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_draw_square(t_window data, int x, int y, int length, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= length)
	{
		j = 0;
		while (j <= length)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i + y, j + x, color);
			j++;
		}
		i++;
	}
}