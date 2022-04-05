NAME=so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror
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
	 parse_map.c \
	 play_game.c \
	 start_game.c \
	 error.c \
	 utils.c
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

leaks: $(LIB) $(MLX)
	$(CC) $(CFLAGS) -g $(SRC) -L$(LIB_DIR) -L$(MLX_DIR) -l$(LIB_NAME) -l$(MLX_NAME) -framework OpenGL -framework Appkit

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ)
	$(RM) $(NAME)

.PHONY: all clean
