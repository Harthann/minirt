/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:49:29 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/07 21:30:44 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

# define BLINN 1

static double	diffuse_light(t_light light, t_inter inter, t_scene scene)
{
	double dot;
	t_point vec;
	double	length;
	double ip;

	ip = 0;
	vec = shift_vec(light.pos, inter.P, 1, '-');
	length = length_vec(vec);
	vec = norm_vec(vec);
	(void)scene;
	dot = dot_product(inter.N, vec);
	ip += light.intensity * dot * 15 / (0.1 + 0.05 * length + 0);
	ip = ip < 0 ? 0 : ip;
	return (ip);
}

static double	specular_light(t_light light, t_inter inter, t_point V)
{
	double ip;
	double dot;
	t_point vec;
	t_point R;
	
	vec = shift_vec(light.pos, inter.P, 1, '-');
	ip = length_vec(vec);
	vec = norm_vec(vec); /* Point vers lumiere : L */
	dot = dot_product(inter.N, vec);
	R.x = 2 * dot * inter.N.x;
	R.y = 2 * dot * inter.N.y;
	R.z = 2 * dot * inter.N.z;
	// R = norm_vec(R);
	R = shift_vec(R, vec, 1, '-');
	V = shift_vec(V, inter.P, 1,'-');
	V = norm_vec(V); /* DU point vers la camera : V */
	/* BLINN-PHONG */
	if (BLINN == 1)
	{
		V = shift_vec(vec, V, 1 , '+');
		V = norm_vec(V);
		V.x /= 2;
		V.y /= 2;
		V.z /= 2;
		dot = dot_product(V, inter.N);
	}
	else	/* PHONG */
		dot = dot_product(R, V);
	
	/* GLOBAL */
	dot = dot < 0 ? 0 : dot;
	// ip = light.intensity * 0.8 * pow(dot, 100) / (0.1 + 0.05 * ip + 0);
	ip = light.intensity * 20 * pow(dot, 100) / (0.1 + 0.05 * ip + 0);
	ip = ip < 0 ? 0: ip;
	return (ip);
}

t_color		pixel_intensity(t_inter inter, t_light *lights, t_cam cam, t_scene scene)
{
	double intensite_R;
	double intensite_G;
	double intensite_B;
	t_inter it;
	t_point vec;

	(void)cam;
	intensite_R = scene.ambient.intensity * 0.15 * (double)scene.ambient.color.R / 255;
	intensite_G = scene.ambient.intensity * 0.15 * (double)scene.ambient.color.G / 255;
	intensite_B = scene.ambient.intensity * 0.15 * (double)scene.ambient.color.B / 255;
	while (lights)
	{
		vec = norm_vec(shift_vec(lights->pos, inter.P, 1, '-'));
		check_intersection(&scene, vec, inter.P, &it);
		if (it.d == -1 || (it.d > length_vec(shift_vec(lights->pos, inter.P, 1, '-'))))
		{
			intensite_R += diffuse_light(*lights, inter, scene) * ((double)lights->color.R / 255);
			intensite_R += specular_light(*lights, inter, cam.pos) * ((double)lights->color.R / 255);
			intensite_G += diffuse_light(*lights, inter, scene) * ((double)lights->color.G / 255);
			intensite_G += specular_light(*lights, inter, cam.pos) * ((double)lights->color.G / 255);
			intensite_B += diffuse_light(*lights, inter, scene) * ((double)lights->color.B / 255);
			intensite_B += specular_light(*lights, inter, cam.pos) * ((double)lights->color.B / 255);
		}
		lights = lights->next;
	}
	inter.color.R = inter.color.R * intensite_R;
	inter.color.R = inter.color.R > 255 ? 255 : inter.color.R;
	inter.color.G = inter.color.G * intensite_G;
	inter.color.G = inter.color.G > 255 ? 255 : inter.color.G;
	inter.color.B = inter.color.B * intensite_B;
	inter.color.B = inter.color.B > 255 ? 255 : inter.color.B;
	return (inter.color);
}
