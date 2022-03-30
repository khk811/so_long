NAME=so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
MLX_DIR=./minilibx_mms_20210621/
MLX_NAME=mlx
MLX=$(MLX_DIR)lib$(MLX_NAME).dylib
LIB_NAME=ft
LIB_DIR=./Libft/
LIB=$(LIB_DIR)lib$(LIB_NAME).a
INCLUDE=-I ./Libft
AR=ar
ARFLAGS=rcs
RM=rm -f
CP=CP
SRC= main.c \
	 map.c \
	 show_mlx_win.c \
	 game_init.c \
	 error.c
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -L$(MLX_DIR) -l$(LIB_NAME) -l$(MLX_NAME) -framework OpenGL -framework Appkit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB) ./

$(MLX) :
	make -C $(MLX_DIR) all
	cp $(MLX) ./

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ)
	$(RM) $(NAME)

leaks : 
	$(CC) $(CFLAGS) $(SRC) -L$(LIB_DIR) -l$(LIB_NAME)

clear_leaks:
	rm a.out
	rm -rf a.out.dSYM

.PHONY: all clean leaks clear_leaks