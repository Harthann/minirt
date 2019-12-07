/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:57:39 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/27 18:01:14 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>
#include <math.h>

void	ft_swap(double *a, double *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

double fpart(double x)
{
	return (x - (int)x);
}

double rfpart(double x)
{
	return (1 - fpart(x));
}

void	draw_line(t_point start, t_point end, t_window data)
{
	// double x;
	// double y;
	// double dx;
	// double dy;
	// double e1;
	// double e2;
	// double e3;
	
	// dx = end.x - start.x;
	// dy = end.y - start.y;
	// y = start.y;
	// e1 = -0.5;
	// e2 = dy / dx;
	// e3 = -1;
	// x = start.x;
	// while (x < end.x)
	// {
	// 	mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xff0000);
	// 	printf("x\t:\t[%f]\ny\t:\t[%f]\n", x, y);
	// 	if ((e1 = e1 + e2) >= 0)
	// 	{
	// 		y++;
	// 		e1 = e1 + e3;
	// 	}
	// 	x++;
	// }

	/* WU algorithm test */
	double dx;
	double dy;
	double gradient;
	(void)data;
	dx = end.x - start.x;
	dy = end.y - start.y;
	if (fabs(dx) > fabs(dy))
	{
		if (end.x < start.x)
		{
			ft_swap(&end.x, &start.x);
			ft_swap(&end.y, &start.y);
		}
		gradient = dy / dx;
		double intery = (int)start.y + gradient;
		while (start.x <= end.x)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, start.x, (int)intery, 0xff0000);
			intery+=gradient;
			start.x++;
		}
	}
}
