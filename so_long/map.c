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

int is_char_map_component(char c)
{
    if (c == '1' || c == 'E' || c == '0' \
    || c == 'P' || c == 'C')
        return (1);
    return (0);
}

int count_map_component(char *s, t_map **map)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!is_char_map_component(s[i]))
            break ;
        if (s[i] == 'P')
            (*map)->player_num++;
        else if (s[i] == 'E')
            (*map)->exit_num++;
        else if (s[i] == 'C')
            (*map)->item_num++;
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
    // 맵 구조체 init을 함수에서 빼서 따로 만들어야 함 (왜 여기서 init을 하는거니;;).
    map_line = get_next_line(map_fd);
    map_row = 0;
    map_col = count_map_component(map_line, map);
    (*map)->player_num = 0;
    (*map)->exit_num = 0;
    (*map)->item_num = 0;
    while (map_line)
    {
        map_row++;
        if (count_map_component(map_line, map) != map_col)
            return (0);
        map_line = get_next_line(map_fd);
    }
    free(map_line);
    map_line = NULL;
    // 밑 부분을 따로 빼는게 좋을까? 아니면 그냥 둘까?
    if ((*map)->player_num != 1 || (*map)->exit_num != 1 || (*map)->item_num < 1)
        return (0);
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
    if (map_fd < 0)
        return (0);
    ret_flag = count_map_line(map_fd, &the_map);
    if (ret_flag == 1)
    {
        printf("the row of the map: %d\n", the_map->row);
        printf("the col of the map: %d\n", the_map->col);
        close(map_fd);
    }
    else
    {
        printf("error: the map isn't right\n");
        close(map_fd);
        return (0);
    }
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
    printf("total player num: %d\n", the_map->player_num);
    printf("total exit num: %d\n", the_map->exit_num);
    printf("wall covered?: %d\n", is_map_wall_covered(the_map));
    close(map_fd);
    return (0);
}