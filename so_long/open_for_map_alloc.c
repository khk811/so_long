#include "so_long.h"

t_map   *alloc_map_arr(t_map *map)
{
    char **ret;
    int i;

    ret = (char **)malloc(sizeof(char *) * ((map->row) + 1));
    if (!ret)
        return (malloc_error("alloc_map_arr()"));
    i = 0;
    while (i < map->row)
    {
        ret[i] = (char *)malloc(sizeof(char) * ((map->col) + 1));
        if (!ret[i])
            return(malloc_error("alloc_map_arr()"));
        i++;
    }
    ret[i] = 0;
    map->map_arr = ret;
    return (map);
}

void    assign_map_arr(int fd, t_map *map)
{
    int i;
    const char    *map_line;

    i = 0;
    while (i < map->row)
    {
        map_line = (const char *)get_next_line(fd);
        ft_strlcpy(map->map_arr[i], map_line, map->col + 1);
        ft_free((char *)map_line);
        i++;
    }
}

t_map   *open_for_map_alloc(const char *dir, t_map *map, int *fd)
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