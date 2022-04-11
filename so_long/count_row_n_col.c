/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row_n_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:20:22 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/08 11:50:00 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_char_map_component(char c)
{
	if (c == '1' || c == 'E' || c == '0' \
			|| c == 'P' || c == 'C')
		return (1);
	return (0);
}

static int	count_map_component(char *s, t_map *map)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_char_map_component(s[i]))
			break ;
		if (s[i] == 'P')
			map->player_num++;
		else if (s[i] == 'E')
			map->exit_num++;
		else if (s[i] == 'C')
			map->item_num++;
		i++;
	}
	return (i);
}

int	count_row_n_col(int map_fd, t_map *map)
{
	char	*map_line;

	map_line = get_next_line(map_fd);
	map->col = count_map_component(map_line, map);
	while (map_line)
	{
		(map->row)++;
		if (count_map_component(map_line, map) != map->col)
			map->col = -42;
		ft_free(map_line);
		map_line = get_next_line(map_fd);
	}
	ft_free(map_line);
	return (1);
}
