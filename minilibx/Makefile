#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
AR = /usr/bin/ar
RANLIB = /usr/bin/ranlib
RM = /bin/rm
ECHO = /bin/echo
CC = /usr/bin/gcc

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@${ECHO} Creating ${NOM}
	@$(AR) -r ../lib/$(NOM) $(OBJ)
	@${RANLIB} ../lib/$(NOM)

%.o: %.c
	@${ECHO} Compiling $<
	@${CC} $(FLAGS) -c -I include/ $< -o $@

clean:
	@${ECHO} Removing Object of minilibx
	@${RM} -f $(NOM) $(OBJ) *~
	@${RM} -f mlx_app

re: clean all
