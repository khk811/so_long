/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:20:50 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/07 21:20:51 by hyunkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*game_map;

	if (argc != 2)
	{
		print_error("main()", "Not enough arguments");
		exit(1);
	}
	game_map = parse_map((const char *)argv[1]);
	if (game_map)
		play_game(game_map);
	else
		exit(1);
	return (0);
}
