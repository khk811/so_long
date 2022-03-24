#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_map   *the_map;

    if (argc != 2)
        return (1);
    the_map = map_parsing((const char*)argv[1]);
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
    printf("is map wall-covered?: %d\n", is_map_wall_covered(the_map));
    return (0);
}