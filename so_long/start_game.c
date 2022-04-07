#include "so_long.h"

t_game  *set_mlx(t_game *game, int img_px)
{
    int width;
    int height;

    if (!game)
        return (NULL);
    game->mlx = mlx_init();
    if (!(game->mlx))
        return (mlx_error("set_mlx()", "mlx init failed"));
    game->img_px = img_px;
    width = img_px * (game->map->col);
    height = img_px * (game->map->row);
    game->win = mlx_new_window(game->mlx, width, height, "so_long");
    if (!(game->win))
        return (mlx_error("set_mlx()", "can't create new mlx window"));
    return (game);
}

t_game  *set_img(t_game *game)
{
    int *img_px;

    img_px = &(game->img_px);
    game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall1.xpm", img_px, img_px);
    game->space = mlx_xpm_file_to_image(game->mlx, "./img/void0.xpm", img_px, img_px);
    game->player = mlx_xpm_file_to_image(game->mlx, "./img/playerP.xpm", img_px, img_px);
    game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exitE.xpm", img_px, img_px);
    game->item = mlx_xpm_file_to_image(game->mlx, "./img/itemC.xpm", img_px, img_px);
    if (!(game->wall) || !(game->space) || !(game->player) || !(game->exit) || !(game->item))
        return (mlx_error("load_img()", "failed to load xpm image(s)"));
    return (game);
}

t_game  *player_init(t_game *game)
{
    game->player_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(game->player_coord))
        return(malloc_error("player_init()"));
    game->player_move = 0;
    game->player_coord->x = 0;
    game->player_coord->y = 0;
    return (game);
}

t_game  *step_init(t_game *game)
{
    game->step_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(game->step_coord))
        return (malloc_error("step_init()"));
    game->step_coord->x = 0;
    game->step_coord->y = 0;
    return (game);
}

t_game  *game_init(t_map *map)
{
    t_game  *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        return (malloc_error("game_init()"));
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
    if (!set_img(game))
        return (free_game(game));
    if (!player_init(game))
        return (free_game(game));
    if (!step_init(game))
        return (free_game(game));
    return (game);
}
