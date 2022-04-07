#include "so_long.h"

int	*find_img_name(char component, t_game *game)
{
	if (component == '1')
		return (game->wall);
	else if (component == '0')
		return (game->space);
	else if (component == 'E')
		return (game->exit);
	else if (component == 'C')
		return (game->item);
	else
		return (game->player);
}

void	draw_component(char component, int row, int col, t_game *game)
{
	int	*img_name;
	int	x;
	int	y;

	img_name = find_img_name(component, game);
	x = game->img_px * col;
	y = game->img_px * row;
	mlx_put_image_to_window(game->mlx, game->win, img_name, x, y);
}

void	draw_mlx_win(t_game *game, t_map *map)
{
	int		row;
	int		col;
	char	component;

	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			component = map->map_arr[row][col];
			draw_component(component, row, col, game);
			if (component == 'P')
			{
				game->player_coord->x = col;
				game->player_coord->y = row;
			}
			col++;
		}
		row++;
	}
}

void	re_draw_player_movement(t_game *game)
{
	t_coord	*player;
	t_coord	*previous_step;

	player = game->player_coord;
	previous_step = game->step_coord;
	draw_component('P', player->y, player->x, game);
	draw_component('0', previous_step->y, previous_step->x, game);
}
