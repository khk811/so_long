#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

#define UP      13
#define DOWN    1
#define RIGHT   2
#define LEFT    0
#define ESC     53

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
    int player_move;
    t_coord *exit_coord;
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
    ret->player_move = 0;
    ret->exit_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(ret->exit_coord))
    {
        free(ret->player_coord);
        free(ret);
        ret->player_coord = NULL;
        ret = NULL;
        return (NULL);
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
    {
        data->exit_coord->x = j;
        data->exit_coord->y = i;
        mlx_put_image_to_window(data->mlx, data->win, data->exit, data->img_px * j, data->img_px * i);
    }
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
    int add_x;
    int add_y;

    curr_x = data->player_coord->x;
    curr_y = data->player_coord->y;
    add_x = 0;
    add_y = 0;
    if (keycode == UP)
        add_y = -1;
    else if (keycode == DOWN)
        add_y = 1;
    else if (keycode == RIGHT)
        add_x = 1;
    else if (keycode == LEFT)
        add_x = -1;
    if (data->map->map_coord[curr_y + add_y][curr_x + add_x] != '1')
    {
        if (data->map->map_coord[curr_y + add_y][curr_x + add_x] == 'C')
        {
            data->map->item_num--;
            printf("item collected\n");
        }
        if (data->map->map_coord[curr_y + add_y][curr_x + add_x] == 'E')
        {
            if (data->map->item_num == 0)
            {
                data->map->map_coord[curr_y + add_y][curr_x + add_x] = 'P';
                data->map->map_coord[curr_y][curr_x] = '0';
                data->player_coord->x += add_x;
                data->player_coord->y += add_y;
                data->player_move++;
                printf("player_move: %d\n", data->player_move);
                // exit 후에는 더이상 메모리 걱정안해도 됨. 프로세스 중에 leak만 안생기면 됨!
                exit(0);
            }
            else
            {
                // 구조체에 exit coord를 할당햇지만 일단 안쓰고 못 들어가게만 했음.
                return (data);
            }
        }
        data->map->map_coord[curr_y + add_y][curr_x + add_x] = 'P';
        data->map->map_coord[curr_y][curr_x] = '0';
        data->player_coord->x += add_x;
        data->player_coord->y += add_y;
        data->player_move++;
        printf("player_move: %d\n", data->player_move);
    }
    return (data);
}

int window_close(t_data *data)
{
    // 이 전에 free를 해줘야 할지도 모름.
    data->player_move = 0;
    printf("window closed\n");
    exit(0);
    return (0);
}

// (*f)(int keycode, void *param); **param이면 segfault.
int press_mov_key(int keycode, t_data *data)
{
    if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
        data = change_coord(keycode, data);
    if (keycode == ESC)
        window_close(data);
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
    mlx_hook(mlx1->win, 17, 0, window_close, mlx1);
    mlx_loop(mlx1->mlx);
}