/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_for_set_map_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:21:09 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/08 12:32:32 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	are_map_components_enough(t_map *map)
{
	char	*func;

	func = "are_map_components_enough()";
	if (map->player_num != 1 || map->exit_num != 1 || \
			map->item_num < 1)
	{
		if (map->player_num != 1)
			print_error(func, "Too many/few player(s)");
		if (map->exit_num != 1)
			print_error(func, "Too many/few exit(s)");
		if (map->item_num < 1)
			print_error(func, "Not enough item");
		return (0);
	}
	return (1);
}

static int	is_map_rectangular(t_map *map)
{
	char	*func;

	func = "is_map_rectangular()";
	if (map->col <= 1 || map->row <= 1)
	{
		if (map->col <= 1)
			print_error(func, "Something wrong with map width");
		if (map->row <= 1)
			print_error(func, "Something wrong with map row");
		return (0);
	}
	return (1);
}

t_map	*open_for_set_map_var(const char *dir, t_map *map, int *fd)
{
	if (!open_map_file(dir, fd))
		return (free_map(map));
	count_row_n_col(*fd, map);
	if (!is_map_rectangular(map) || !are_map_components_enough(map))
	{
		close(*fd);
		return (free_map(map));
	}
	close(*fd);
	return (map);
}
