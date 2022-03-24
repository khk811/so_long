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

void    show_mlx_win(t_map *map)
{
    t_data  mlx1;

    mlx1.mlx = mlx_init();
    mlx1.img_px = 60;
    mlx1.win = mlx_new_window(mlx1.mlx, (mlx1.img_px * map->col), (mlx1.img_px * map->row), "so_long");
    mlx1.wall = mlx_xpm_file_to_image(mlx1.mlx, "./img/wall1.xpm", &(mlx1.img_px), &(mlx1.img_px));
    mlx1.space = mlx_xpm_file_to_image(mlx1.mlx, "./img/void0.xpm", &(mlx1.img_px), &(mlx1.img_px));
    mlx1.player = mlx_xpm_file_to_image(mlx1.mlx, "./img/playerP.xpm", &(mlx1.img_px), &(mlx1.img_px));
    mlx1.exit = mlx_xpm_file_to_image(mlx1.mlx, "./img/exitE.xpm", &(mlx1.img_px), &(mlx1.img_px));
    mlx1.item = mlx_xpm_file_to_image(mlx1.mlx, "./img/itemC.xpm", &(mlx1.img_px), &(mlx1.img_px));
    int i;
    int j;
    i = 0;
    while (i < map->row)
    {
        j = 0;
        while (j < map->col)
        {
            if (map->map_coord[i][j] == '1')
                mlx_put_image_to_window(mlx1.mlx, mlx1.win, mlx1.wall, mlx1.img_px * j, mlx1.img_px * i);
            else if (map->map_coord[i][j] == '0')
                mlx_put_image_to_window(mlx1.mlx, mlx1.win, mlx1.space, mlx1.img_px * j, mlx1.img_px * i);
            else if (map->map_coord[i][j] == 'P')
                mlx_put_image_to_window(mlx1.mlx, mlx1.win, mlx1.player, mlx1.img_px * j, mlx1.img_px * i);
            else if (map->map_coord[i][j] == 'E')
                mlx_put_image_to_window(mlx1.mlx, mlx1.win, mlx1.exit, mlx1.img_px * j, mlx1.img_px * i);
            else if (map->map_coord[i][j] == 'C')
                mlx_put_image_to_window(mlx1.mlx, mlx1.win, mlx1.item, mlx1.img_px * j, mlx1.img_px * i);
            j++;
        }
        i++;
    }
    mlx_loop(mlx1.mlx);
}