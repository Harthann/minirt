/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:49:29 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 21:27:51 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "libft.h"

double	diffuse_light(t_light light, t_inter inter)
{
	double	dot;
	t_p		vec;
	double	length;
	double	ip;

	ip = 0;
	vec = shift_vec(light.pos, inter.p, -1);
	length = length_vec(vec);
	vec = norm_vec(vec);
	dot = dot_product(inter.n, vec);
	ip += light.intensity * dot * 15 / (0.1 + 0.05 * length);
	ip = ip < 0 ? 0 : ip;
	return (ip);
}

void	adjust_color(t_color *color, double i_r, double i_g, double i_b)
{
	color->r = color->r * i_r;
	if (color->r > 255)
		color->r = 255;
	color->g = color->g * i_g;
	if (color->g > 255)
		color->g = 255;
	color->b = color->b * i_b;
	if (color->b > 255)
		color->b = 255;
}

double	adjust_intensity(t_light *lights, t_inter i, int color, t_p pos)
{
	double intensity;

	intensity = diffuse_light(*lights, i) * ((double)color / 255);
	intensity += specular_light(*lights, i, pos) * ((double)color / 255);
	return (intensity);
}

t_color	pixel_intens(t_inter i, t_light *lights, t_scene scene)
{
	double	i_r;
	double	i_g;
	double	i_b;
	t_inter it;
	t_p		vec;

	i_r = scene.ambient.intensity * 0.15 * (double)scene.ambient.color.r / 255;
	i_g = scene.ambient.intensity * 0.15 * (double)scene.ambient.color.g / 255;
	i_b = scene.ambient.intensity * 0.15 * (double)scene.ambient.color.b / 255;
	while (lights)
	{
		vec = norm_vec(shift_vec(lights->pos, i.p, -1));
		check_inter(&scene, vec, i.p, &it);
		if (it.d == -1 || (it.d > length_vec(shift_vec(lights->pos, i.p, -1))))
		{
			vec = scene.image->cam.pos;
			i_r += adjust_intensity(lights, i, lights->color.r, vec);
			i_g += adjust_intensity(lights, i, lights->color.g, vec);
			i_b += adjust_intensity(lights, i, lights->color.b, vec);
		}
		lights = lights->next;
	}
	adjust_color(&i.color, i_r, i_g, i_b);
	return (i.color);
}
