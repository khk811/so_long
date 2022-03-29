#include <stdio.h>
#include "Libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"

// argv를 map main 함수 앞에서 거르는데 좋을듯.

int check_file_ext(const char *dir)
{
    char    *file_ext;
    unsigned int    start;
    int ret;

    ret = 1;
    start = (unsigned int)(ft_strlen(dir) - 4);
    file_ext = ft_substr(dir, start, 4);
    if (ft_strncmp(file_ext, ".ber", 4) != 0)
        ret = 0;
    free(file_ext);
    file_ext = NULL;
    return (ret);
}

int valid_map_open(const char *dir)
{
    int ret_fd;

    ret_fd = -1;
    if (!check_file_ext(dir))
        return (-1);
    ret_fd = open(dir, O_RDONLY);
    if (ret_fd < 0)
        return (-1);
    return (ret_fd);
}

t_map   *map_init(void)
{
    t_map   *ret;

    ret = (t_map *)malloc(sizeof(t_map));
    // ret 할당 실패시 return NULL;
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

int check_map_component(t_map *map)
{
    if (map->player_num != 1)
        return (0);
    else if (map->exit_num != 1)
        return (0);
    else if (map->item_num < 1)
        return (0);
    return (1);
}

int count_map_line(int map_fd, t_map *map)
{
    char    *map_line;

// fd 판별은 한번만 햇으면 좋겠음. 여기에서 판별하지 않았으면.
    if (map_fd < 0)
        return (0);
    map_line = get_next_line(map_fd);
    map->col = count_map_component(map_line, map);
    while (map_line)
    {
        (map->row)++;
        if (count_map_component(map_line, map) != map->col)
            return (0);
        free(map_line);
        map_line = get_next_line(map_fd);
    }
    free(map_line);
    map_line = NULL;
    if (!check_map_component(map))
        return (0);
    return (1);
}

char **alloc_map_arr(t_map *map)
{
    char **ret;
    int i;

    ret = (char **)malloc(sizeof(char *) * ((map->row) + 1));
    if (!ret)
        return (NULL);
    i = 0;
    while (i < map->row)
    {
        ret[i] = (char *)malloc(sizeof(char) * ((map->col) + 1));
        //if (!ret[i])
        //  return(ft_free_heap(ret)); 2d 배열 할당 해제
        i++;
    }
    // 2d arr 마지막에 0으로 끝냄;
    ret[i] = 0;
    return (ret);
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
        // free UTIL 만들기
        free((char *)gnl_buf);
        gnl_buf = NULL;
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
//실제 main 함수에 t_map을 넘길 루트 함수 만들기.
t_map   *map_parsing(const char *dir)
{
    t_map   *the_map;
    int map_fd;
    int is_ok;

    the_map = map_init();
    map_fd = valid_map_open(dir);
    if (map_fd < 0)
        return (NULL);
    is_ok = count_map_line(map_fd, the_map);
    if (is_ok != 1)
    {
        printf("error: the map isn't right\n");
        close(map_fd);
        return (NULL);
    }
    close(map_fd);
    map_fd = valid_map_open(dir);
    if (map_fd < 0)
        return (NULL);
    the_map->map_coord = alloc_map_arr(the_map);
    assign_map_arr(map_fd, the_map);
    close(map_fd);
    return (the_map);
}