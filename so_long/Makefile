# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 14:59:02 by hyunkkim          #+#    #+#              #
#    Updated: 2022/03/14 19:06:29 by hyunkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror
MLX_DIR=./minilibx_mms_20200219/
MLX_NAME=mlx
MLX=$(LIB_DIR)lib$(LIB_NAME).dylib
INCLUDE=-I $(MLX_DIR)
AR=ar
ARFLAGS=rcs
RM=rm -f
CP=cp
SRC= test_minilibx.c
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all

all : $(NAME)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ)

.PHONY: all clean