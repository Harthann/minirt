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
static double d_grande = 1540;
static double d_petit = 831;

double		ft_color(t_sphere sphere, t_point p)
{
	double d;
	int color;
	// int red, blue, green;

	p.z = sphere.center.z - sqrt(pow(sphere.radius, 2) + pow(fabs(p.y - sphere.center.y), 2));
	d = sqrt(p.z * p.z + p.y * p.y + p.x * p.x);
	// if (d > d_grande)
	// 	d_grande = d;
	// if (d < d_petit)
	// 	d_petit = d;
	if (sphere.color.R > 0)
		color = (sphere.color.R - (int)(0.36 * (d - 831))) << 16;
	if (sphere.color.G > 0)
		color = color | (sphere.color.G - (int)(0.36 * (d - 831))) << 8;
	if(sphere.color.B > 0)
		color = color | (sphere.color.B - (int)(0.36 * (d - 831)));
	// red = sphere.color.R + (int)(255 / (0.36 * (d - 831)));
	// green = sphere.color.G + (int)(255 / (0.36 * (d - 831)));
	// blue = sphere.color.B + (int)(255 / (0.36 * (d - 831)));

	// blue = blue < 0 ? 0 : blue;
	// blue = blue > 255 ? 255 : blue;
	// green = green < 0 ? 0 : green;
	// green = green > 255 ? 255 : green;
	// red = red < 0 ? 0 : red;
	// red = red > 255 ? 255 : red;
	// color = red << 16;
	// color = color | green << 8;
	// color = color | blue;
	// color = (int)(sphere.color.R * 0.5) << 16;
	return (color);
}

void	ft_draw_circle(t_window data, t_sphere sphere)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.x <= data.width)
	{
		p.y = 0;
		while (p.y <= data.heigth)
		{
			if (pow(p.x - sphere.center.x, 2) + pow(p.y - sphere.center.y, 2) <= pow(sphere.radius, 2))
				mlx_pixel_put(data.mlx_ptr, data.mlx_win, p.x, p.y, ft_color(sphere, p));
			p.y++;
		}
		p.x++;
	}
	printf("d_petit : [%f]\nd_grande : [%f]\n", d_petit, d_grande);
}
