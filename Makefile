# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 16:28:15 by nieyraud          #+#    #+#              #
#    Updated: 2019/11/19 13:28:38 by nieyraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRC_FILE =	draw_square.c \
			draw_circle.c \
			draw_line.c \
			get_next_line.c \
			get_next_line_utils.c \
			main.c

PATH = srcs/

SRCS		= $(addprefix ${PATH}, ${SRC_FILE})
OBJS		= ${SRCS:%.c=%.o}
INCLUDE		= include/minirt.h

FLAGS = -Wall -Werror -Wextra

MINILIB = libmlx.a
LIBFT	= libft.a

LIB = lib/
LIBS = ${addprefix $(LIB), ${LIBFT}} ${addprefix $(LIB), ${MINILIB}}
FRAMEWORK = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : ${OBJS} ${INCLUDE} ${LIBS}
	@echo Creating ${NAME}
	@gcc ${FLAGS} -I include -g -L ${LIB} -l mlx ${FRAMEWORK} ${OBJS}  -o ${NAME}

${LIBS} : 
	${MAKE} -C libft/
	mv libft/${LIBFT} lib/.
	${MAKE} -C minilibx_opengl_20191021/
	mv minilibx_opengl_20191021/${MINILIB} lib/.

%.o: %.c
	@echo Compiling $<
	gcc $(FLAGS) -c -I include/ $< -o $@

clean :
	@echo Removing objects files
	@rm -f ${OBJS}
	@make fclean -C libft
	@make clean -C minilibx_opengl_20191021
fclean : clean
	@echo Removing ${NAME}
	@rm -f $(NAME) ${LIBS}
	

re : fclean all

.PHONY : all clean fclean re