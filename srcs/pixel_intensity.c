/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:49:29 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 15:42:52 by nieyraud         ###   ########.fr       */
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
	// ft_bzero(&it, sizeof(t_inter));
	while (lights)
	{
		vec = norm_vec(shift_vec(lights->pos, i.p, -1));
		check_inter(&scene, vec, i.p, &it);
		if (it.d == -1 ||
		(it.d > length_vec(shift_vec(lights->pos, i.p, -1))))
		{
			i_r += diffuse_light(*lights, i) * ((double)lights->color.r / 255);
			i_r += specular_light(*lights, i, scene.image->cam.pos) * ((double)lights->color.r / 255);
			i_g += diffuse_light(*lights, i) * ((double)lights->color.g / 255);
			i_g += specular_light(*lights, i, scene.image->cam.pos) * ((double)lights->color.g / 255);
			i_b += diffuse_light(*lights, i) * ((double)lights->color.b / 255);
			i_b += specular_light(*lights, i, scene.image->cam.pos) * ((double)lights->color.b / 255);
		}
		lights = lights->next;
	}
	adjust_color(&i.color, i_r, i_g, i_b);
	return (i.color);
}
