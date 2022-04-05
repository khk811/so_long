#include "so_long.h"

int is_file_extension_ber(const char *dir)
{
    char    *file_ext;
    unsigned int    start;

    start = (unsigned int)(ft_strlen(dir) - 4);
    file_ext = ft_substr(dir, start, 4);
    if (ft_strncmp(file_ext, ".ber", 4) != 0)
    {
        free_ptr(file_ext);
        print_error("is_file_extension_ber()", \
        "Wrong filename extension");
        return (0);
    }
    free_ptr(file_ext);
    return (1);
}

int open_map_file(const char *dir, int *fd)
{
    *fd = -1;
    if (!is_file_extension_ber(dir))
        return (0);
    *fd = open(dir, O_RDONLY);
    if (*fd < 0)
        return (print_error("open_map_file()", strerror(errno)));
    return (1);
}

t_map   *map_init(void)
{
    t_map   *ret;

    ret = (t_map *)malloc(sizeof(t_map));
    if (!ret)
        return (malloc_error("map_init()"));
    ret->row = 0;
    ret->col = 0;
    ret->player_num = 0;
    ret->exit_num = 0;
    ret->item_num = 0;
    ret->map_coord = NULL;
    return (ret);
}

int is_char_map_component(char c)
{
    if (c == '1' || c == 'E' || c == '0' \
    || c == 'P' || c == 'C')
        return (1);
    return (0);
}

int count_map_component(char *s, t_map *map)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!is_char_map_component(s[i]))
            break;
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

int are_map_components_enough(t_map *map)
{
    char    *func;

    func = "are_map_components_enough()";
    if (map->player_num != 1 || map->exit_num != 1 || \
    map->item_num < 1)
    {
        if (map->player_num != 1)
            print_error(func, "Too many/few player(s)");
        if (map->exit_num != 1)
            print_error(func, "Too many/few exit(s)");
        if (map->item_num < 1)
            print_error(func, "Not enough item");
        return (0);
    }
    return (1);
}

int is_map_rectangular(t_map *map)
{
    if (map->col < 0 || map->row <= 1)
    {
        print_error("is_map_rectangular()", "No");
        return (0);
    }
    return (1);
}

int count_row_n_col(int map_fd, t_map *map)
{
    char    *map_line;
    char    *func;

    func = "count_row_n_col()";    
    map_line = get_next_line(map_fd);
    map->col = count_map_component(map_line, map);
    while (map_line)
    {
        (map->row)++;
        if (count_map_component(map_line, map) != map->col)
            map->col = -42;
        free_ptr(map_line);
        map_line = get_next_line(map_fd);
    }
    free_ptr(map_line);
    return (1);
}

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
    map->map_coord = ret;
    return (map);
}

void    assign_map_arr(int map_fd, t_map *map)
{
    int i;
    const char    *gnl_buf;

    i = 0;
    gnl_buf = NULL;
    while (i < map->row)
    {
        gnl_buf = (const char *)get_next_line(map_fd);
        ft_strlcpy(map->map_coord[i], gnl_buf, map->col + 1);
        free_ptr((char *)gnl_buf);
        i++;
    }
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
                if (map->map_coord[i][j] != '1')
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

t_map   *open_for_set_map_var(const char *dir, t_map *map, int *fd)
{
    if (!open_map_file(dir, fd))
        return (free_map(map));
    count_row_n_col(*fd, map);
    if (!is_map_rectangular(map) || !are_map_components_enough(map))
    {
        close(*fd);
        return (free_map(map));
    }
    close(*fd);
    return (map);
}

t_map   *open_for_map_alloc(const char *dir, t_map *map, int *fd)
{
    if (!open_map_file(dir, fd))
        return (free_map(map));
    if (!alloc_map_arr(map))
        return (free_map(map));
    assign_map_arr(*fd, map);
    close(*fd);
    return (map);
}

//실제 main 함수에 t_map을 넘길 루트 함수 만들기.
t_map   *map_parsing(const char *dir)
{
    t_map   *the_map;
    int map_fd;

    the_map = map_init();
    if (!the_map)
        return (NULL);
    if (!open_for_set_map_var(dir, the_map, &map_fd))
        return (NULL);
    if (!open_for_map_alloc(dir, the_map, &map_fd))
        return (NULL);
    if (!is_map_wall_covered(the_map))
    {
        print_error("map_parsing()", "The map isn't wall-covered");
        return (free_map(the_map));
    }
    return (the_map);
}