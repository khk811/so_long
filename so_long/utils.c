/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:21:42 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/08 11:52:42 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

void	*free_map(t_map *map)
{
	int	row;

	row = 0;
	if (map->map_arr && (map->row != 0))
	{
		while (map->map_arr[row] && row < map->row)
		{
			ft_free(map->map_arr[row]);
			row++;
		}
		ft_free(map->map_arr);
	}
	ft_free(map);
	return (NULL);
}

static void	destroy_img(void *mlx, int *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx, img);
}

void	*free_game(t_game *game)
{
	destroy_img(game->mlx, game->wall);
	destroy_img(game->mlx, game->space);
	destroy_img(game->mlx, game->player);
	destroy_img(game->mlx, game->exit);
	destroy_img(game->mlx, game->item);
	ft_free(game->player_coord);
	ft_free(game->step_coord);
	free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_free(game);
	return (NULL);
}
