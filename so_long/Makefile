# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 21:20:54 by hyunkkim          #+#    #+#              #
#    Updated: 2022/04/07 21:32:25 by hyunkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror
MLX_DIR= ./mlx/
MLX_NAME=mlx
MLX=$(MLX_DIR)lib$(MLX_NAME).dylib
LIBMLX=lib$(MLX_NAME).dylib
LIB_NAME=ft
LIB_DIR= ./Libft/
LIB=$(LIB_DIR)lib$(LIB_NAME).a
LIBFT=lib$(LIB_NAME).a
FRAMEWORK= -framework OpenGL -framework Appkit
INCLUDE=-I ./Libft -I ./mlx
RM=rm -f
CP=cp
SRC= main.c \
	 parse_map.c \
	 open_for_set_map_var.c \
	 count_row_n_col.c \
	 open_map_file.c \
	 open_for_map_alloc.c \
	 play_game.c \
	 start_game.c \
	 set_mlx_img.c \
	 draw.c \
	 move.c \
	 error.c \
	 utils.c
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -L$(MLX_DIR) -l$(LIB_NAME) -l$(MLX_NAME) $(FRAMEWORK) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all
	$(CP) $(LIB) ./

$(MLX) :
	make -C $(MLX_DIR) all
	$(CP) $(MLX) ./

all : $(NAME)

leaks: $(LIB) $(MLX)
	$(CC) $(CFLAGS) -g $(SRC) $(INCLUDE) -L$(LIB_DIR) -L$(MLX_DIR) -l$(LIB_NAME) -l$(MLX_NAME) -framework OpenGL -framework Appkit

clean_leaks :
	$(RM) a.out
	$(RM) a.out.dSYM

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(LIBMLX)
	$(RM) $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
