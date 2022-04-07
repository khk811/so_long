#include "so_long.h"

int window_close(t_game *game)
{
    game->player_move = 0;
    printf("window closed\n");
    exit(0);
    return (0);
}

int press_mov_key(int keycode, t_game *game)
{
    if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
    {
        if (can_player_move(keycode, game, game->map))
        {
            move_player(game, game->map);
            re_draw_player_movement(game);
        }
        if (game->map->exit_num == 0)
            exit(0);
    }
    if (keycode == ESC)
        window_close(game);
    return (0);
}

void    play_game(t_map *map)
{
    t_game  *game;

    game = start_game(map);
    if (game)
        draw_mlx_win(game, map);
    mlx_hook(game->win, 2, 0, press_mov_key, game);
    mlx_hook(game->win, 17, 0, window_close, game);
    mlx_loop(game->mlx);
}