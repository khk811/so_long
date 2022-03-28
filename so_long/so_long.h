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
    t_coord *exit_coord;
    t_map   *map;
}   t_game;

// map related funcs.
int valid_map_open(const char *dir);
t_map   *map_init(void);
int is_char_map_component(char c);
int count_map_component(char *s, t_map **map);
int check_map_component(t_map *map);
int count_map_line(int map_fd, t_map **map);
char    **alloc_map_arr(t_map *map);
void    assign_map_arr(int map_fd, t_map **map);
int is_map_wall_covered(t_map *map);
t_map   *map_parsing(const char *dir);

// rendering??
void    show_mlx_win(t_map *map);
#endif