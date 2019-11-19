/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:44:57 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/10 16:44:57 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
static double d_grande = 1255;
static double d_petit = 871;
double		ft_color(t_sphere sphere, t_point p)
{
	double d;

	p.z = sphere.z - sqrt(pow(sphere.radius, 2) + pow(fabs(p.y - sphere.y), 2));
	d = sqrt(p.z * p.z + p.y * p.y + p.x * p.x);
	// printf("%f\n", d);
	// if (d < d_petit)
	// 	d_petit = d;
	// else if (d > d_grande)
	// 	d_grande = d;
	// int taux_g = 0x00ff00 - (0.71 * (d - 360));
	// int taux_b = 0x0000ff - (0.71 * (d - 360));
	// printf("%f\n",d);
	return ((0xffffff - sphere.colour) * (sphere.colour / d));
}

void	ft_draw_circle(t_window data, t_sphere sphere)
{
	t_point p;

	p.x = 0;
	p.y = 0;
			int color = 0xffffff;
	while (p.x <= data.width)
	{
		p.y = 0;
		
		while (p.y <= data.heigth)
		{
			if (pow(p.x - sphere.x, 2) + pow(p.y - sphere.y, 2) <= pow(sphere.radius, 2))
				mlx_pixel_put(data.mlx_ptr, data.mlx_win, p.x, p.y, 0xff0000 + ft_color(sphere, p));
			p.y++;
		}
		p.x++;
		ft_draw_square(data, p.x, p.y * 100, 50, color);
	}
	printf("d_petit : [%f]\nd_grande : [%f]\n", d_petit, d_grande);
}
