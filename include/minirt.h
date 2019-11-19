/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:44:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/19 13:20:03 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct		s_window
{
    void	*mlx_ptr;
    void	*mlx_win;
	int		width;
	int		heigth;
}					t_window;

typedef struct		s_point
{
	double	x;
	double	y;
	double	z;
}					t_point;

typedef struct		s_sphere
{
	double	x;
	double	y;
	double	z;
	double	radius;
	int		colour;
}					t_sphere;

typedef struct		s_color
{
	int	R;
	int G;
	int B;
}					t_color;

typedef struct		s_light
{
	double intensity;
	t_point vertex;
	t_color color;
}					t_light;

typedef struct		s_cam
{
	t_point pos;
	t_point vector;
}					t_cam;

typedef struct		s_scene
{
	t_light ambient;
	t_cam	cam;

}					t_scene;

void	ft_draw_square(t_window data, int x, int y, int length, int color);
void	ft_draw_circle(t_window data, t_sphere sphere);
void	draw_line(t_point start, t_point end, t_window data);

#endif