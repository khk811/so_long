NAME=so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIB_NAME=ft
LIB_DIR=./Libft/
LIB=$(LIB_DIR)lib$(LIB_NAME).a
INCLUDE=-I ./Libft
AR=ar
ARFLAGS=rcs
RM=rm -f
CP=CP
SRC= map.c
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -L$(LIB_DIR) -l$(LIB_NAME) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB) :
	make -C $(LIB_DIR) all

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(OBJ)

.PHONY: all clean