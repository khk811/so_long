#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

#define UP      13
#define DOWN    1
#define RIGHT   2
#define LEFT    0

typedef struct s_coord
{
    int x;
    int y;
}   t_coord;

typedef struct s_data
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
    t_map   *map;
}   t_data;

t_data  *t_data_init(t_map *map)
{
    t_data  *ret;

    ret = (t_data *)malloc(sizeof(t_data));
    if (!ret)
        return (NULL);
    ret->mlx = mlx_init();
    ret->img_px = 60;
    ret->win = mlx_new_window(ret->mlx, (ret->img_px * map->col), (ret->img_px * map->row), "so_long");
    ret->wall = mlx_xpm_file_to_image(ret->mlx, "./img/wall1.xpm", &(ret->img_px), &(ret->img_px));
    ret->space = mlx_xpm_file_to_image(ret->mlx, "./img/void0.xpm", &(ret->img_px), &(ret->img_px));
    ret->player = mlx_xpm_file_to_image(ret->mlx, "./img/playerP.xpm", &(ret->img_px), &(ret->img_px));
    ret->exit = mlx_xpm_file_to_image(ret->mlx, "./img/exitE.xpm", &(ret->img_px), &(ret->img_px));
    ret->item = mlx_xpm_file_to_image(ret->mlx, "./img/itemC.xpm", &(ret->img_px), &(ret->img_px));
    ret->player_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(ret->player_coord))
    {
        free(ret);
        ret = NULL;
        return(NULL);
    }
    ret->player_coord->x = 0;
    ret->player_coord->y = 0;
    ret->map = map;
    return (ret);
}

void    draw_fixed_component(char component, int i, int j, t_data *data)
{
    if (component == '1')
        mlx_put_image_to_window(data->mlx, data->win, data->wall, data->img_px * j, data->img_px * i);
    else if (component == '0')
        mlx_put_image_to_window(data->mlx, data->win, data->space, data->img_px * j, data->img_px * i);
    else if (component == 'E')
        mlx_put_image_to_window(data->mlx, data->win, data->exit, data->img_px * j, data->img_px * i);
}

void    draw_mutable_component(char component, int i, int j, t_data *data)
{
    if (component == 'P')
    {
        data->player_coord->x = j;
        data->player_coord->y = i;
        mlx_put_image_to_window(data->mlx, data->win, data->player, data->img_px * j, data->img_px * i);
    }
    else if (component == 'C')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->item, data->img_px * j, data->img_px * i);
    }
}

void    draw_mlx_win(t_data *data, t_map *map)
{
    int i;
    int j;
    char    component;

    i = 0;
    while (i < map->row)
    {
        j = 0;
        while (j < map->col)
        {
            component = map->map_coord[i][j];
            if (component == '1' || component== '0' || component== 'E')
                draw_fixed_component(component, i, j, data);
            else if (component== 'P' || component == 'C')
                draw_mutable_component(component, i, j, data);
            j++;
        }
        i++;
    }
}

t_data  *change_coord(int keycode, t_data *data)
{
    int curr_x;
    int curr_y;

    curr_x = data->player_coord->x;
    curr_y = data->player_coord->y;
    if (keycode == UP)
    {
        if (data->map->map_coord[curr_y - 1][curr_x] != '1')
        {
            data->map->map_coord[curr_y - 1][curr_x] = 'P';
            data->map->map_coord[curr_y][curr_x] = '0';
            data->player_coord->y--;
        }
    }
    return (data);
}

// (*f)(int keycode, void *param); **param이면 segfault.
int press_mov_key(int keycode, t_data *data)
{
    if (keycode == UP)
    {
        printf("curr player coord: %d, %d\n", data->player_coord->x, data->player_coord->y);
        printf("UP W key pressed\n");
        data = change_coord(keycode, data);
        printf("move to-> %d, %d\n", data->player_coord->x, data->player_coord->y);
    }
    mlx_clear_window(data->mlx, data->win);
    draw_mlx_win(data, data->map);
    return (0);
}

void    show_mlx_win(t_map *map)
{
    t_data  *mlx1;

    mlx1 = t_data_init(map);
    if (mlx1)
        draw_mlx_win(mlx1, map);
    mlx_hook(mlx1->win, 2, 0, press_mov_key, mlx1);
    mlx_loop(mlx1->mlx);
}