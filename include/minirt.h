/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:44:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 23:58:04 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <pthread.h>

/*
** STRUCTURE USUELLES
*/

typedef struct		s_window
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		heigth;
	int		fov;
}					t_window;

typedef struct		s_color
{
	int	r;
	int g;
	int b;
}					t_color;

typedef struct		s_point
{
	double	x;
	double	y;
	double	z;
}					t_p;

/*
** STRUCTURE OBJETS
*/

typedef struct		s_sphere
{
	t_p				center;
	double			radius;
	t_color			color;
	int				speed;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_square
{
	t_p				pos;
	t_p				vector;
	double			heigth;
	t_color			color;
	struct s_square	*next;
}					t_square;

typedef struct		s_cyl
{
	t_p				pos;
	t_p				vec;
	double			radius;
	double			heigth;
	t_color			color;
	struct s_cyl	*next;
}					t_cyl;

typedef struct		s_plan
{
	t_p				origin;
	t_p				vector;
	t_color			color;
	struct s_plan	*next;
}					t_plan;

typedef struct		s_triangle
{
	t_p					vertex1;
	t_p					vertex2;
	t_p					vertex3;
	t_color				color;
	struct s_triangle	*next;
}					t_triangle;

typedef struct		s_light
{
	double			intensity;
	t_p				pos;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_cam
{
	t_p				pos;
	t_p				vector;
	double			v_plane_w;
	double			v_plane_h;
	struct s_cam	*next;
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

/*
** STRUCTURE GENERALES
*/

typedef struct		s_image
{
	void			*ptr;
	int				bpp;
	int				size;
	int				endian;
	int				*image;
	int				end;
	t_cam			cam;
	struct s_image	*next;
}					t_img;

typedef struct		s_inter
{
	double	d;
	t_p		n;
	t_p		p;
	t_color color;
}					t_inter;

typedef struct		s_scene
{
	t_window	win;
	t_light		ambient;
	t_cam		*cam;
	char		*name;
	t_obj		obj;
	t_img		*image;
	char		rotation : 1;
}					t_scene;

typedef struct		s_thread
{
	pthread_t	thread[4];
	t_scene		*scene;
	int			**img;
	t_cam		cam;
}					t_thread;

typedef struct		s_glob
{
	t_scene scene;
	int		i;
	int		j;
	t_cam	cam;
}					t_glob;

typedef struct		s_header
{
	short	type;
	int		size;
	int		start;
	int		header_size;
	short	planes;
	short	bpp;
	int		raw_size;
	int		res;
}					t_header;

/*
** FONCTIONS UTILS
*/

int					get_next_line(int fd, char **line);
double				ft_atof(const char *str, char *error);

/*
**  LIB VECTEUR
*/

double				length_vec(t_p vec);
t_p					norm_vec(t_p vec);
t_p					cross_poduct(t_p a, t_p b);
double				dot_product(t_p vec1, t_p vec2);
t_p					shift_vec(t_p origin, t_p vec, int d);
t_p					norm_vec(t_p vec);
t_p					mult_vec(t_p a, double b);
int					comp_vec(t_p a, t_p b);
t_p					fill_vec(double x, double y, double z);

/*
** FONCTIONS DESSIN
*/

int					browse_sphere(t_p pos, t_sphere *sp, t_p dir, t_inter *i);
int					browse_cylindre(t_p pos, t_cyl *cyl, t_p dir, t_inter *i);
int					browse_plan(t_p pos, t_plan *plan, t_p dir, t_inter *i);
int					browse_tri(t_p pos, t_triangle *tr, t_p dir, t_inter *i);
int					browse_square(t_p pos, t_square *sq, t_p dir, t_inter *i);
double				inter_sphere(t_p pos, t_sphere sphere, t_p dir);
double				inter_plan(t_p pos, t_plan plan, t_p dir);
double				inter_cyl(t_p pos, t_cyl cyl, t_p dir);
double				inter_triangle(t_p pos, t_triangle triangle, t_p dir);
double				inter_square(t_p pos, t_square square, t_p dir);

/*
** INITIALISATION ET PARSE
*/

void				init_scene(t_scene *scene);
t_scene				parse_file(char *str);
int					get_color(t_color *color, const char *str);
int					get_pos(t_p *vector, const char *str, char *error);
void				set_resolution(t_scene *scene, const char *str);
void				set_ambient_light(t_scene *scene, const char *str);
void				set_cam(t_scene *scene, const char *str);
void				set_sphere(t_scene *scene, const char *str);
void				set_light(t_scene *scene, const char *str);
void				set_plan(t_scene *scene, const char *str);
void				set_cylindre(t_scene *scene, const char *str);
void				set_triangle(t_scene *scene, const char *str);
void				set_square(t_scene *scene, const char *str);

/*
**	FREE ################################################################
*/

void				ft_error(char *str, t_scene *scene);
void				ft_free(t_scene *scene);
void				free_obj(t_obj obj);
void				free_square(t_square *obj);
void				free_triangle(t_triangle *obj);
void				free_plan(t_plan *obj);
void				free_sphere(t_sphere *obj);
void				free_cyl(t_cyl *obj);
void				free_cam(t_cam *cam);
void				free_light(t_light *light);
void				free_image(t_img *img);

/*
**	KEY CONTOL
*/

int					close_win(t_scene *scene);
void				next_image(t_scene *scene);
void				cam_control(t_scene *scene, int key);
void				fov_control(t_scene *scene, int key);
int					rotation(t_scene *scene);
t_p					find_top_vec(t_p vec);

/*
** GLOBAL
*/

int					draw_image(t_scene scene, t_cam cam, int **img);
int					initiate(t_scene scene);
int					key_control(int key, t_scene *scene);
int					raytrace(t_scene *scene, int i, int j, t_cam cam);
double				check_inter(t_scene *sc, t_p dir, t_p pos, t_inter *i);
t_color				pixel_intens(t_inter i, t_light *l, t_scene sc);
double				specular_light(t_light light, t_inter inter, t_p v);
void				screenshot(t_scene scene, char *name);

#endif
