# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 16:28:15 by nieyraud          #+#    #+#              #
#    Updated: 2019/12/07 17:29:59 by nieyraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRC_FILE =	get_next_line.c \
			get_next_line_utils.c \
			ft_atof.c \
			init_scene.c \
			get_color.c \
			get_pos.c \
			parse_file.c \
			set_resolution.c \
			set_ambient_light.c \
			set_cam.c \
			set_light.c \
			set_sphere.c \
			calc_inter.c \
			browse_objects.c \
			main.c \
			draw_image.c \
			draw_circle.c \
			lib_vec.c \
			raytrace.c \
			pixel_intensity.c \
			set_plane.c \
			set_cylindre.c \
			intersection.c \
			initiate_calc.c \
			set_triangle.c \
			calc_inter_2.c 
			
PATH = srcs/

SRCS		= $(addprefix ${PATH}, ${SRC_FILE})
OBJS		= ${SRCS:%.c=%.o}
INCLUDE		= 	include/minirt.h \
				include/libft.h

FLAGS = -Wall -Werror -Wextra -O2 -march=native
OPT_FLAGS = -flto
THREAD = -lpthread

MINILIB = libmlx.a
LIBFT	= libft.a

LIB = lib/
LIBS = ${addprefix $(LIB), ${LIBFT}}
FRAMEWORK = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : ${OBJS} ${INCLUDE} ${LIBS}
	@echo Creating ${NAME}
	@gcc ${FLAGS} ${OPT_FLAGS} ${THREAD} -I include -g -L ${LIB} -l mlx ${FRAMEWORK} ${OBJS} lib/${LIBFT} -o ${NAME}

${LIBS} : lib1

lib1 :
	@echo Checking update for libft.a
	@${MAKE} -C libft/

%.o: %.c
	@echo Compiling $<
	gcc $(FLAGS) -c -I include/ $< -o $@

clean :
	@echo Removing objects files
	@rm -f ${OBJS}
	@make clean -C libft

run : ${NAME}
	@./${NAME} scenes/square.rt

fclean : clean
	@echo Removing ${NAME}
	@rm -f $(NAME) ${LIBS}
	

re : fclean all

.PHONY : all clean fclean re