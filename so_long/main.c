#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_map   *the_map;

    if (argc != 2)
    {
        printf("Error\n: Not enough argument\n");
        return (1);
    }
    the_map = map_parsing((const char*)argv[1]);
    if (!the_map)
    {
        printf("Error\n: Map parsing failed\n");
        return (1);
    }
    /*
    int i = 0;
    while (i < the_map->row)
    {
        printf("%s|\n", the_map->map_coord[i]);
        i++;
    }
    printf("coord(3, 1): %c\n", the_map->map_coord[3][1]);
    printf("coord(1, 1): %c\n", the_map->map_coord[1][1]);
    printf("total player num: %d\n", the_map->player_num);
    printf("total exit num: %d\n", the_map->exit_num);
    */
    if (is_map_wall_covered(the_map))
        show_mlx_win(the_map);
    else
    {
        printf("Error\n: map isn't covered by walls\n");
        return (1);
    }
    return (0);
}