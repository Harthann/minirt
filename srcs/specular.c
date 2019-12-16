/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:50:01 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 13:02:37 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

double	specular_light(t_light light, t_inter inter, t_p v)
{
	double	ip;
	double	dot;
	t_p		vec;
	t_p		r;

	vec = shift_vec(light.pos, inter.p, -1);
	ip = length_vec(vec);
	vec = norm_vec(vec);
	dot = dot_product(inter.n, vec);
	r.x = 2 * dot * inter.n.x;
	r.y = 2 * dot * inter.n.y;
	r.z = 2 * dot * inter.n.z;
	// R = norm_vec(R);
	r = shift_vec(r, vec, -1);
	v = shift_vec(v, inter.p, -1);
	v = norm_vec(v);
	dot = dot_product(r, v);
	dot = dot < 0 ? 0 : dot;
	ip = light.intensity * 15 * pow(dot, 100) / (0.1 + 0.05 * ip);
	ip = ip < 0 ? 0 : ip;
	return (ip);
}
