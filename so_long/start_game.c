#include "so_long.h"

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
