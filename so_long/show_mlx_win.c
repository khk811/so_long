#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"


void    draw_fixed_component(char component, int i, int j, t_game *game)
{
    if (component == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->wall, game->img_px * j, game->img_px * i);
    else if (component == '0')
        mlx_put_image_to_window(game->mlx, game->win, game->space, game->img_px * j, game->img_px * i);
    else if (component == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->exit, game->img_px * j, game->img_px * i);
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

t_coord *calculate_next_step(int keycode, t_game *game)
{
    t_coord current_player_position;
    t_coord *next_step;

    next_step = game->step_coord;
    current_player_position = *(game->player_coord);
    if (keycode == UP)
        current_player_position.y -= 1;
    else if (keycode == DOWN)
        current_player_position.y += 1;
    else if (keycode == LEFT)
        current_player_position.x -= 1;
    else if (keycode == RIGHT)
        current_player_position.x += 1;
    next_step->x = current_player_position.x;
    next_step->y = current_player_position.y;
    return (next_step);
}

void    swap_coord(t_coord **coord1, t_coord **coord2)
{
    t_coord *tmp;

    tmp = *coord1;
    *coord1 = *coord2;
    *coord2 = tmp;
}

void    actual_move(t_game *game, t_map *map)
{
    t_coord *player;
    t_coord *step;

    swap_coord(&(game->player_coord), &(game->step_coord));
    player = game->player_coord;
    step = game->step_coord;
    map->map_coord[player->y][player->x] = 'P';
    map->map_coord[step->y][step->x] = '0';
    game->player_move++;
    printf("player move: %d\n", game->player_move);
}

int change_coord(int keycode, t_game *game, t_map *map)
{
    t_coord *player_pos;
    t_coord *next_step;
    char    next_component;

    player_pos = game->player_coord;
    next_step = calculate_next_step(keycode, game);
    next_component = map->map_coord[next_step->y][next_step->x];
    if (next_component != '1')
    {
        if (next_component == 'C')
            map->item_num--;
        else if (next_component == 'E')
        {
            if (map->item_num == 0)
                map->exit_num = 0;
            else
                return (0);
        }
        actual_move(game, game->map);
        return (1);
    }
    return (0);
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
    {
        if (change_coord(keycode, game, game->map))
        {
            draw_fixed_component('0', game->step_coord->y, game->step_coord->x, game);
            draw_mutable_component('P', game->player_coord->y, game->player_coord->x ,game);
        }
        if (game->map->exit_num == 0)
            exit(0);
    }
    if (keycode == ESC)
        window_close(game);
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