#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
    char    **map_coord;
    int row;
    int col;
    int player_num;
    int exit_num;
    int item_num;
}   t_map;

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

#endif