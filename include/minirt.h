/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:44:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/25 16:21:41 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

/*			STRUCTURE USUELLES		*/

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

/*			STRUCTURE OBJETS		*/

typedef struct		s_sphere
{
	t_point			center;
	double			radius;
	t_color			color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_square
{
	t_point			pos;
	t_point			vector;
	double			heigth;
	t_color			color;
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
	t_color			color;
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
	t_point pos;
	t_color color;
	struct s_light *next;
}					t_light;

/*			STRUCTURE GENERALES			*/

typedef struct		s_cam
{
	t_point pos;
	t_point vector;
	double	v_plane_w;
	double	v_plane_h;
}					t_cam;

typedef struct		s_obj
{
	t_sphere	*sphere;
	t_square	*square;
	t_cyl		*cyl;
	t_plan		*plan;
	t_triangle	*triangle;
	t_light		*light;
}					t_obj;

typedef struct		s_image
{
	void	*ptr;
	int		bpp;
	int		size;
	int		endian;
	int		*image;
}					t_img;

typedef struct		s_inter
{
	double	d;
	t_point N;
	t_point P;
	t_color color;
}					t_inter;

typedef struct		s_scene
{
	t_window	win;
	t_light		ambient;
	t_cam		cam;
	t_obj		obj;
	t_img		image;
}					t_scene;

/*			FONCTIONS UTILS			*/

int			get_next_line(int fd, char **line);
double		ft_atof(const char *str);

/*			LIB VECTEUR				*/

t_point		norm_vec(t_point vec);
t_point		cross_poduct(t_point a, t_point b);
double		dot_product(t_point vec1, t_point vec2);
t_point 	shift_vec(t_point O, t_point vec, int d, char op);
t_point		norm_vec(t_point vec);

/*			FONCTIONS DESSIN		*/

void		draw_line(t_point start, t_point end, t_window data);
int			browse_sphere(t_cam cam, t_sphere *sphere, t_point dir, t_inter *i);
double		inter_sphere(t_cam cam, t_sphere sphere, t_point dir);

/*			INITIALISATION ET PARSE	*/
void		init_scene(t_scene *scene);
t_scene		parse_file(char *str);
void		get_color(t_color *color, const char *str);
int			get_pos(t_point *vector, const char *str);
void		set_resolution(t_scene *scene, const char *str);
void		set_ambient_light(t_scene *scene, const char *str);
void		set_cam(t_scene *scene, const char *str);
void		set_sphere(t_scene *scene, const char *str);
void		set_light(t_scene *scene, const char *str);

/*			GLOBAL					*/

void		draw_image(t_scene *scene);
int			raytrace(t_scene *scene, int i, int j);
int			check_intersection(t_scene *scene, t_point dir);
#endif