/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_for_map_alloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:21:04 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/08 11:51:09 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*alloc_map_arr(t_map *map)
{
	char	**ret;
	int		row;

	ret = (char **)malloc(sizeof(char *) * ((map->row) + 1));
	if (!ret)
		return (malloc_error("alloc_map_arr()"));
	row = 0;
	while (row < map->row)
	{
		ret[row] = (char *)malloc(sizeof(char) * ((map->col) + 1));
		if (!ret[row])
			return (malloc_error("alloc_map_arr()"));
		row++;
	}
	ret[row] = 0;
	map->map_arr = ret;
	return (map);
}

static void	assign_map_arr(int fd, t_map *map)
{
	int			row;
	const char	*map_line;

	row = 0;
	while (row < map->row)
	{
		map_line = (const char *)get_next_line(fd);
		ft_strlcpy(map->map_arr[row], map_line, map->col + 1);
		ft_free((char *)map_line);
		row++;
	}
}

t_map	*open_for_map_alloc(const char *dir, t_map *map, int *fd)
{
	if (!open_map_file(dir, fd))
		return (free_map(map));
	if (!alloc_map_arr(map))
	{
		close(*fd);
		return (free_map(map));
	}
	assign_map_arr(*fd, map);
	close(*fd);
	return (map);
}
