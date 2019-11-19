/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:44:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/19 18:34:23 by nieyraud         ###   ########.fr       */
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

typedef struct		s_color
{
	int	R;
	int G;
	int B;
}					t_color;

typedef struct		s_point
{
	double	x;
	double	y;
	double	z;
}					t_point;

typedef struct		s_sphere
{
	t_point			center;
	double			radius;
	t_color			colour;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_square
{
	t_point			pos;
	t_point			vector;
	double			heigth;
	t_color			colour;
	struct s_square	*next;
}					t_square;

typedef struct		s_cyl
{
	t_point			pos;
	double			radius;
	double			heigth;
	t_color			color;
	struct s_cyl	*cyl;
}					t_cyl;

typedef struct		s_plan
{
	t_point			origin;
	t_point			vector;
	t_color			colour;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_triangle
{
	t_point				vertex1;
	t_point				vertex2;
	t_point				vertex3;
	t_color				color;
	struct s_triangle	*next;
}					t_triangle;

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

typedef struct		s_obj
{
	t_sphere	*sphere;
	t_square	*square;
	t_cyl		*cyl;
	t_plan		*plan;
	t_triangle	*triangle;
}					t_obj;

typedef struct		s_scene
{
	t_window	win;
	t_light		ambient;
	t_cam		cam;
	t_obj		*obj;
}					t_scene;

// typedef	struct		s_functions
// {
	
// }					t_functions;


int			get_next_line(int fd, char **line);
void		ft_draw_square(t_window data, int x, int y, int length, int color);
void		ft_draw_circle(t_window data, t_sphere sphere);
void		draw_line(t_point start, t_point end, t_window data);
void		init_resolution(t_scene *scene, char *str);
t_scene		parse_file(char *str);
#endif