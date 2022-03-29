#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

t_game  *game_init(t_map *map)
{
    t_game  *ret;

    ret = (t_game *)malloc(sizeof(t_game));
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
