#include "so_long.h"

t_map   *map_init(void)
{
    t_map   *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (malloc_error("map_init()"));
    map->row = 0;
    map->col = 0;
    map->player_num = 0;
    map->exit_num = 0;
    map->item_num = 0;
    map->map_arr = NULL;
    return (map);
}

int is_map_wall_covered(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->row)
    {
        j = 0;
        while (j < map->col)
        {
            if ((i == 0 || i == (map->row) - 1) \
            || (j == 0 || j == (map->col) - 1))
            {
                if (map->map_arr[i][j] != '1')
                {
                    print_error("is_map_wall_covered()", \
                    "The map isn't wall-covered");
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    return (1);
}

t_map   *parse_map(const char *dir)
{
    t_map   *map;
    int map_fd;

    map = map_init();
    if (!map)
        return (NULL);
    if (!open_for_set_map_var(dir, map, &map_fd))
        return (NULL);
    if (!open_for_map_alloc(dir, map, &map_fd))
        return (NULL);
    if (!is_map_wall_covered(map))
        return (free_map(map));
    return (map);
}
