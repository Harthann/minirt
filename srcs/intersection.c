/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:33:27 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/25 20:07:46 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "libft.h"

int		rgb_conv(t_color color)
{
	int col;

	col = color.R << 16;
	col = col | (color.G << 8);
	col = col | color.B;
	return (col);
}

double		check_light(t_light *light, t_point N, t_point P)
{
	double dot;
	t_point vec;
	double ip;

	ip = 0;
	vec = shift_vec(light->pos, P, 1, '-');
	vec = norm_vec(vec);
	dot = dot_product(N, vec);
	ip += light->intensity * dot / dot_product(vec, vec);
	return (ip);
}

double		amb_light(double intensity, double light)
{
	double coef;

	coef = intensity * light / 255;
	return (coef);
}



int		check_intersection(t_scene *scene, t_point dir)
{
	double	d;
	t_inter inter;
	double	intensite;
	t_light *light;

	light = scene->obj.light;
	inter.d = -1;
	d = browse_sphere(scene->cam, scene->obj.sphere, dir, &inter);
	while (light)
	{
		intensite = check_light(light, norm_vec(inter.N), shift_vec(scene->cam.pos, dir, inter.d, '+'));
		inter.color.R = inter.color.R * intensite * amb_light(scene->ambient.intensity, scene->ambient.color.R);
		inter.color.R = inter.color.R > 255 ? 255 : inter.color.R;
		inter.color.G = inter.color.G * intensite * amb_light(scene->ambient.intensity, scene->ambient.color.G);
		inter.color.G = inter.color.G > 255 ? 255 : inter.color.G;
		inter.color.B = inter.color.B * intensite * amb_light(scene->ambient.intensity, scene->ambient.color.B);
		inter.color.B = inter.color.B > 255 ? 255 : inter.color.B;
		light = light->next;
	}
	return (rgb_conv(inter.color));
}
