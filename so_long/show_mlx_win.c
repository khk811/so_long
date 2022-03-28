#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

t_game  *game_init(t_map *map)
{
    t_game  *ret;

    ret = (t_game *)malloc(sizeof(t_game));
    if (!ret)
        return (NULL);
    ret->mlx = mlx_init();
    ret->img_px = 60;
    ret->win = mlx_new_window(ret->mlx, (ret->img_px * map->col), (ret->img_px * map->row), "so_long");
    ret->wall = mlx_xpm_file_to_image(ret->mlx, "./img/wall1.xpm", &(ret->img_px), &(ret->img_px));
    ret->space = mlx_xpm_file_to_image(ret->mlx, "./img/void0.xpm", &(ret->img_px), &(ret->img_px));
    ret->player = mlx_xpm_file_to_image(ret->mlx, "./img/playerP.xpm", &(ret->img_px), &(ret->img_px));
    ret->exit = mlx_xpm_file_to_image(ret->mlx, "./img/exitE.xpm", &(ret->img_px), &(ret->img_px));
    ret->item = mlx_xpm_file_to_image(ret->mlx, "./img/itemC.xpm", &(ret->img_px), &(ret->img_px));
    ret->player_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(ret->player_coord))
    {
        free(ret);
        ret = NULL;
        return(NULL);
    }
    ret->player_move = 0;
    ret->exit_coord = (t_coord *)malloc(sizeof(t_coord));
    if (!(ret->exit_coord))
    {
        free(ret->player_coord);
        free(ret);
        ret->player_coord = NULL;
        ret = NULL;
        return (NULL);
    }
    ret->player_coord->x = 0;
    ret->player_coord->y = 0;
    ret->map = map;
    return (ret);
}

void    draw_fixed_component(char component, int i, int j, t_game *game)
{
    if (component == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->wall, game->img_px * j, game->img_px * i);
    else if (component == '0')
        mlx_put_image_to_window(game->mlx, game->win, game->space, game->img_px * j, game->img_px * i);
    else if (component == 'E')
    {
        game->exit_coord->x = j;
        game->exit_coord->y = i;
        mlx_put_image_to_window(game->mlx, game->win, game->exit, game->img_px * j, game->img_px * i);
    }
}

void    draw_mutable_component(char component, int i, int j, t_game *game)
{
    if (component == 'P')
    {
        game->player_coord->x = j;
        game->player_coord->y = i;
        mlx_put_image_to_window(game->mlx, game->win, game->player, game->img_px * j, game->img_px * i);
    }
    else if (component == 'C')
    {
        mlx_put_image_to_window(game->mlx, game->win, game->item, game->img_px * j, game->img_px * i);
    }
}

void    draw_mlx_win(t_game *game, t_map *map)
{
    int i;
    int j;
    char    component;

    i = 0;
    while (i < map->row)
    {
        j = 0;
        while (j < map->col)
        {
            component = map->map_coord[i][j];
            if (component == '1' || component== '0' || component== 'E')
                draw_fixed_component(component, i, j, game);
            else if (component== 'P' || component == 'C')
                draw_mutable_component(component, i, j, game);
            j++;
        }
        i++;
    }
}

t_game  *change_coord(int keycode, t_game *game)
{
    int curr_x;
    int curr_y;
    int add_x;
    int add_y;

    curr_x = game->player_coord->x;
    curr_y = game->player_coord->y;
    add_x = 0;
    add_y = 0;
    if (keycode == UP)
        add_y = -1;
    else if (keycode == DOWN)
        add_y = 1;
    else if (keycode == RIGHT)
        add_x = 1;
    else if (keycode == LEFT)
        add_x = -1;
    if (game->map->map_coord[curr_y + add_y][curr_x + add_x] != '1')
    {
        if (game->map->map_coord[curr_y + add_y][curr_x + add_x] == 'C')
        {
            game->map->item_num--;
            printf("item collected\n");
        }
        if (game->map->map_coord[curr_y + add_y][curr_x + add_x] == 'E')
        {
            if (game->map->item_num == 0)
            {
                game->map->map_coord[curr_y + add_y][curr_x + add_x] = 'P';
                game->map->map_coord[curr_y][curr_x] = '0';
                game->player_coord->x += add_x;
                game->player_coord->y += add_y;
                game->player_move++;
                printf("player_move: %d\n", game->player_move);
                printf("player exit\n");
                // exit 후에는 더이상 메모리 걱정안해도 됨. 프로세스 중에 leak만 안생기면 됨!
                exit(0);
            }
            else
            {
                // 구조체에 exit coord를 할당햇지만 일단 안쓰고 못 들어가게만 했음.
                return (game);
            }
        }
        game->map->map_coord[curr_y + add_y][curr_x + add_x] = 'P';
        game->map->map_coord[curr_y][curr_x] = '0';
        game->player_coord->x += add_x;
        game->player_coord->y += add_y;
        game->player_move++;
        printf("player_move: %d\n", game->player_move);
    }
    return (game);
}

int window_close(t_game *game)
{
    // 이 전에 free를 해줘야 할지도 모름.
    game->player_move = 0;
    printf("window closed\n");
    exit(0);
    return (0);
}

// (*f)(int keycode, void *param); **param이면 segfault.
int press_mov_key(int keycode, t_game *game)
{
    if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
        game = change_coord(keycode, game);
    if (keycode == ESC)
        window_close(game);
    mlx_clear_window(game->mlx, game->win);
    draw_mlx_win(game, game->map);
    return (0);
}

void    show_mlx_win(t_map *map)
{
    t_game  *game;

    game = game_init(map);
    if (game)
        draw_mlx_win(game, map);
    mlx_hook(game->win, 2, 0, press_mov_key, game);
    mlx_hook(game->win, 17, 0, window_close, game);
    mlx_loop(game->mlx);
}