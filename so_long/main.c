#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*game_map;

	if (argc != 2)
	{
		print_error("main()", "Not enough arguments");
		return (1);
	}
	game_map = parse_map((const char *)argv[1]);
	if (game_map)
		play_game(game_map);
	return (0);
}
