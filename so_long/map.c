#include <stdio.h>
#include "Libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"

// argv를 map main 함수 앞에서 거르는데 좋을듯.
// valid_map_open 이거 하지 말고 그냥 open, close 이렇게.

int valid_map_open(const char *dir)
{
    int ret_fd;

    ret_fd = -1;
    //check ext. -> .ber
    if (!ft_strnstr(dir, ".ber", ft_strlen(dir)))
        return (-1);
    ret_fd = open(dir, O_RDONLY);
    if (ret_fd < 0)
        return (-1);
    return (ret_fd);
}

int is_char_map_compo(char c)
{
    if (c == '1' || c == 'E' || c == '0' \
    || c == 'P' || c == 'C')
        return (1);
    return (0);
}

int is_str_map_compo(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!is_char_map_compo(s[i]))
            break ;
        i++;
    }
    return (i);
}

int count_map_line(int map_fd, t_map **map)
{
    int map_row;
    int map_col;
    char    *map_line;

// fd 판별은 한번만 햇으면 좋겠음. 여기에서 판별하지 않았으면.
    if (map_fd < 0)
        return (0);
    map_line = get_next_line(map_fd);
    map_row = 0;
    map_col = is_str_map_compo(map_line);
    while (map_line)
    {
        map_row++;
        if (is_str_map_compo(map_line) != map_col)
            return (0);
        map_line = get_next_line(map_fd);
    }
    (*map)->row = map_row;
    (*map)->col = map_col;
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

void    assign_map_arr(int map_fd, t_map **map)
{
    int i;
    const char    *gnl_buf;

    i = 0;
    gnl_buf = NULL;
    while (i < (*map)->row)
    {
        gnl_buf = (const char *)get_next_line(map_fd);
        ft_strlcpy((*map)->map_coord[i], gnl_buf, (*map)->col + 1);
        free((char *)gnl_buf);
        gnl_buf = NULL;
        i++;
    }
}

int main(int argc, char **argv)
{
    int map_fd;
    t_map   *the_map;
    int ret_flag;

    ret_flag = 0;
    if (argc != 2)
        return (0);
    the_map = malloc(sizeof(t_map));
    map_fd = valid_map_open((const char *)argv[1]);
    ret_flag = count_map_line(map_fd, &the_map);
    if (ret_flag == 1)
    {
        printf("the row of the map: %d\n", the_map->row);
        printf("the col of the map: %d\n", the_map->col);
    }
    else
        printf("error: the map isn't right\n");
    close(map_fd);
    map_fd = valid_map_open((const char *)argv[1]);
    the_map->map_coord = alloc_map_arr(the_map);
    assign_map_arr(map_fd, &the_map);
    int i = 0;
    while (i < the_map->row)
    {
        printf("%s|\n", the_map->map_coord[i]);
        i++;
    }
    printf("coord(2, 3): %c\n", the_map->map_coord[2][3]);
    printf("coord(1, 1): %c\n", the_map->map_coord[1][1]);
    close(map_fd);
    return (0);
}