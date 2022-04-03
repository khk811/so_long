#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "so_long.h"
#include "Libft/libft.h"

int error_handling(int error_code)
{
    int ret;

    ret = 0;
    if (error_code == 1)
    {
        // fd error
        printf("Error\n : (open) %s\n", strerror(errno));
        ret = 0;
    }
    else if (error_code == 2)
    {
        // check_file_ext error
        printf("Error\n : (chech_file_ext) Wrong filename extension\n");
        ret = 0;
    }
    else if (error_code == 3)
    {
        // wrong map component error
        printf("Error\n : (count_map_component) Detect wrong map component\n");
        ret = 0;
    }
    else if (error_code == 4)
    {
        // not enough elements
        printf("Error\n : (check_map_componenet) Not enough component\n");
        ret = 0;
    }
    else if (error_code == 5)
    {
        // map is not a rectangular (or square)
        printf("Error\n : (count_map_line) The map is not a rectangular\n");
        ret = 0;
    }
    
    return (ret);
}