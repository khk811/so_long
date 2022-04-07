#include "so_long.h"

static int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

static int	key_down_event(int keycode, t_game *game)
{
	if (keycode == UP || keycode == DOWN \
			|| keycode == RIGHT || keycode == LEFT)
	{
		if (can_player_move(keycode, game, game->map))
		{
			move_player(game, game->map);
			re_draw_player_movement(game);
			if (game->map->exit_num == 0)
				close_window(game);
		}
	}
	if (keycode == ESC)
		close_window(game);
	return (0);
}

void	play_game(t_map *map)
{
	t_game	*game;

	game = start_game(map);
	if (game)
	{
		draw_mlx_win(game, map);
		mlx_hook(game->win, 2, 0, key_down_event, game);
		mlx_hook(game->win, 17, 0, close_window, game);
		mlx_loop(game->mlx);
	}
}
