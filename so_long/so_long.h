#ifndef SO_LONG_H
# define SO_LONG_H

#define UP      13
#define DOWN    1
#define RIGHT   2
#define LEFT    0
#define ESC     53

typedef struct s_map
{
    char    **map_coord;
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
int open_map_file(const char *dir, int *fd);
t_map   *map_init(void);
int is_char_map_component(char c);
int count_map_component(char *s, t_map *map);
int are_map_components_enough(t_map *map);
int count_row_n_col(int map_fd, t_map *map);
t_map    *alloc_map_arr(t_map *map);
void    assign_map_arr(int map_fd, t_map *map);
int is_map_wall_covered(t_map *map);
t_map   *map_parsing(const char *dir);

// rendering??
void    show_mlx_win(t_map *map);

// game_init;
//t_game  *game_init(t_map *map);
t_game  *start_game(t_map *map);

// error handling function
int error_handling(int error_code);

//utils - free, destroy
void    free_ptr(void *ptr);
void    *free_map(t_map *map);

#endif