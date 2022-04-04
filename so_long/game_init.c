#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

t_game  *set_mlx(t_game *game, int img_px)
{
    int win_width;
    int win_height;

    if (!game)
        return (NULL);
    game->mlx = mlx_init();
    if (!(game->mlx))
        return (NULL);
    game->img_px = img_px;
    win_width = img_px * (game->map->col);
    win_height = img_px * (game->map->row);
    game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
    if (!(game->win))
        return (NULL);
    return (game);
}

t_game  *load_img(t_game *game)
{
    int *img_px;

    img_px = &(game->img_px);
    game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall1.xpm", img_px, img_px);
    game->space = mlx_xpm_file_to_image(game->mlx, "./img/void0.xpm", img_px, img_px);
    game->player = mlx_xpm_file_to_image(game->mlx, "./img/playerP.xpm", img_px, img_px);
    game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exitE.xpm", img_px, img_px);
    game->item = mlx_xpm_file_to_image(game->mlx, "./img/itemC.xpm", img_px, img_px);
    if (!(game->wall) || !(game->space) || !(game->player) || !(game->exit) || !(game->item))
        return (NULL);
    return (game);
}

t_game  *player_init(t_game *game)
{
    game->player_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(game->player_coord))
        return(NULL);
    game->player_move = 0;
    game->player_coord->x = 0;
    game->player_coord->y = 0;
    return (game);
}

t_game  *step_init(t_game *game)
{
    game->step_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(game->step_coord))
        return (NULL);
    game->step_coord->x = 0;
    game->step_coord->y = 0;
    return (game);
}

t_game  *game_init(t_map *map)
{
    t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    game->mlx = NULL;
    game->win = NULL;
    game->img_px = 0;
    game->wall = NULL;
    game->space = NULL;
    game->player = NULL;
    game->exit = NULL;
    game->item = NULL;
    game->player_coord = NULL;
    game->player_move = 0;
    game->step_coord = NULL;
    game->map = map;
    return (game);
}

t_game  *start_game(t_map *map)
{
    t_game  *game;

    game = game_init(map);
    if (!game)
        return (free_map(map));
    if (!set_mlx(game, 60))
        return (free_game(game));
    if (!load_img(game))
        return (free_game(game));
    if (!player_init(game))
        return (free_game(game));
    if (!step_init(game))
        return (free_game(game));
    return (game);
}
