#include "so_long.h"


void    free_ptr(void *ptr)
{
    if (!ptr)
        return ;
    free(ptr);
    ptr = NULL;
}

void    *free_map(t_map *map)
{
    int i;

    i = 0;
    if (map->map_coord && (map->row != 0))
    {
        while (map->map_coord[i] && i < map->row)
        {
            free_ptr(map->map_coord[i]);
            i++;
        }
        free_ptr(map->map_coord);
    }
    free_ptr(map);
    return (NULL);
}

void    destroy_img(void *mlx, int *img)
{
    if (!img)
        return ;
    mlx_destroy_image(mlx, img);
}

void    *free_game(t_game *game)
{
    destroy_img(game->mlx, game->wall);
    destroy_img(game->mlx, game->space);
    destroy_img(game->mlx, game->player);
    destroy_img(game->mlx, game->exit);
    destroy_img(game->mlx, game->item);
    free_ptr(game->player_coord);
    free_ptr(game->step_coord);
    free_map(game->map);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free_ptr(game);
    return (NULL);
}