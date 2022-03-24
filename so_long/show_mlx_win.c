#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

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
    mlx_loop(data->mlx);
}

void    show_mlx_win(t_map *map)
{
    t_data  *mlx1;

    mlx1 = t_data_init(map);
    if (mlx1)
        draw_mlx_win(mlx1, map);
}