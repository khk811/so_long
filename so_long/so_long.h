#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include "Libft/libft.h"


#define UP      13
#define DOWN    1
#define RIGHT   2
#define LEFT    0
#define ESC     53

typedef struct s_map
{
    char    **map_arr;
    int row;
    int col;
    int player_num;
    int exit_num;
    int item_num;
}   t_map;

typedef struct s_coord
{
    int x;
    int y;
}   t_coord;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    int img_px;
    int *wall;
    int *space;
    int *player;
    int *exit;
    int *item;
    t_coord *player_coord;
    int player_move;
    t_coord *step_coord;
    t_map   *map;
}   t_game;

// map related funcs.
t_map   *parse_map(const char *dir);

// rendering??
void    play_game(t_map *map);

// game_init;
//t_game  *game_init(t_map *map);
t_game  *start_game(t_map *map);

// error handling function
int print_error(char *func, char *err_msg);
void    *malloc_error(char *func);

//utils - free, destroy
void    ft_free(void *ptr);
void    *free_map(t_map *map);
void    *free_game(t_game *game);

#endif