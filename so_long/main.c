#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_map   *the_map;

    if (argc != 2)
    {
        printf("Error\n: (main) Not enough argument\n");
        return (1);
    }
    the_map = map_parsing((const char*)argv[1]);
    if (the_map)
        show_mlx_win(the_map);
    return (0);
}