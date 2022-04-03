#include "so_long.h"
#include "stdlib.h"

void    ft_free(void *ptr)
{
    if (!ptr)
        return ;
    free(ptr);
    ptr = NULL;
}

char    *free_map_arr(t_map *map)
{
    int i;

    i = 0;
    while (map->map_coord[i])
        ft_free(map->map_coord[i++]);
    return (NULL);
}