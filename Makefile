# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 16:28:15 by nieyraud          #+#    #+#              #
#    Updated: 2019/12/18 11:10:14 by nieyraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################
#		COLOR		#
#####################

rose=\033[1;31m
violetfonce=\033[0;35m
violetclair=\033[1;35m
neutre=\033[0m
cyanfonce=\033[0;36m
cyanclair=\033[1;36m
vertfonce=\033[0;32m
vertclair=\033[1;32m
rouge=\033[31m

#####################
#		SOURCES		#
#####################
NAME = minirt

SRC_FILE =	calc_inter.c browse_objects.c main.c draw_image.c \
			lib_vec.c raytrace.c pixel_intensity.c intersection.c \
			initiate_calc.c	calc_inter_2.c get_next_line.c \
			ft_atof.c init_scene.c get_color.c get_pos.c \
			parse_file.c set_resolution.c set_ambient_light.c \
			set_cam.c set_light.c set_sphere.c set_plane.c set_cylindre.c \
			set_triangle.c set_square.c lib_vec_2.c cam_control.c \
			key_control.c screenshot.c specular.c rotate_obj.c \
			free_light_cam.c free_obj.c ft_free.c free_image.c \
			ft_error.c get_texture.c get_speed.c texture_mapping.c \
			skybox.c \

#############################
#		DIRCTORIES PATH		#
#############################

PATH = ${shell find srcs -type d}
OBJ_PATH = objs
vpath %.c $(foreach dir, $(PATH), $(dir))

#################################
#		FILES	VARIABLE		#
#################################

SRC		= ${SRC_FILE}
SRCS	= $(addprefix ${PATH}, ${SRC_FILE})
OBJ		= ${addprefix ${OBJ_PATH}/, ${SRC_FILE:%.c=%.o}}
INCLUDE	= 	include/minirt.h \
			include/libft.h \

#########################
#			FLAGS		#
#########################

FLAGS = -Wall -Werror -Wextra -O2 -march=native
SAN = -g3 -fsanitize=address
OPT_FLAGS = -flto
THREAD = -lpthread

#########################
#		LIBRARIES		#
#########################

LIBFT	= libft.a
LIB = lib/
LIBS = ${addprefix $(LIB), ${LIBFT}}
FRAMEWORK = -framework OpenGL -framework AppKit

#############################
#			RULES			#
#############################

all : $(NAME)

$(NAME) : ${LIBS} ${OBJ} ${INCLUDE} 
	@echo "${vertclair}Creating ${NAME}"
	@gcc ${FLAGS} ${OPT_FLAGS} ${THREAD} -I include -g -L ${LIB} -l mlx ${FRAMEWORK} ${OBJ} lib/${LIBFT} -o ${NAME}
	@echo "${vertclair}[Minirt ready to use]"

sanitize : ${LIBS} ${OBJ} ${INCLUDE} 
	@echo "${vertclair}Creating ${NAME}"
	@gcc ${FLAGS} ${SAN} ${OPT_FLAGS} ${THREAD} -I include -g -L ${LIB} -l mlx ${FRAMEWORK} ${OBJ} lib/${LIBFT} -o ${NAME}
	@echo "${vertclair}[Minirt ready to use]"

${LIBS} : lib1

lib1 :
	@echo "${violetclair}Checking update for libft.a"
	@${MAKE} -C libft/ > /dev/null
	@echo "${violetclair}Libft [${vertclair}OK${violetclair}]"

${OBJ_PATH}/%.o: %.c ${INCLUDE}
	@mkdir -p ${OBJ_PATH}
	@echo "${cyanfonce}Compiling ${notdir $(basename $@)}"
	@gcc $(FLAGS) -c -o $@ -I include/ $<

clean :
	@echo "${rouge}Removing objects files"
	@rm -rf ${OBJ_PATH}
	@make clean -C libft

run : ${NAME}
	@./${NAME} scenes/square.rt

fclean : clean
	@echo "${rose}Removing ${NAME}"
	@rm -f $(NAME) ${LIBS}
	

re : fclean all

.PHONY : all clean fclean re