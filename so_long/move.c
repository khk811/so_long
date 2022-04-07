#include "so_long.h"

t_coord	*calculate_next_step(int keycode, t_game *game)
{
	t_coord	current_player_position;
	t_coord	*next_step;

	current_player_position = *(game->player_coord);
	next_step = game->step_coord;
	if (keycode == UP)
		current_player_position.y -= 1;
	else if (keycode == DOWN)
		current_player_position.y += 1;
	else if (keycode == LEFT)
		current_player_position.x -= 1;
	else if (keycode == RIGHT)
		current_player_position.x += 1;
	next_step->x = current_player_position.x;
	next_step->y = current_player_position.y;
	return (next_step);
}

void	move_forward(t_coord **to_go, t_coord **from)
{
	t_coord	*tmp;

	tmp = *to_go;
	*to_go = *from;
	*from = tmp;
}

void	move_player(t_game *game, t_map *map)
{
	t_coord	*player;
	t_coord	*step;

	move_forward(&(game->step_coord), &(game->player_coord));
	player = game->player_coord;
	step = game->step_coord;
	map->map_arr[player->y][player->x] = 'P';
	map->map_arr[step->y][step->x] = '0';
	game->player_move++;
	printf("player move: %d\n", game->player_move);
}

int	can_player_move(int keycode, t_game *game, t_map *map)
{
	t_coord	*next_step;
	char	next_step_component;

	next_step = calculate_next_step(keycode, game);
	next_step_component = map->map_arr[next_step->y][next_step->x];
	if (next_step_component != '1')
	{
		if (next_step_component == 'C')
			map->item_num--;
		else if (next_step_component == 'E')
		{
			if (map->item_num == 0)
				map->exit_num = 0;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
