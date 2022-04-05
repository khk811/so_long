#include "so_long.h"

int *find_img_dir(char component, t_game *game)
{
    if (component == '1')
        return (game->wall);
    else if (component == '0')
        return (game->space);
    else if (component == 'E')
        return (game->exit);
    else if (component == 'C')
        return (game->item);
    else
        return (game->player);
}

void    draw_component(char component, int i, int j, t_game *game)
{
    int *img_dir;
    int x;
    int y;

    img_dir = find_img_dir(component, game);
    x = game->img_px * j;
    y = game->img_px * i;
    mlx_put_image_to_window(game->mlx, game->win, img_dir, x, y);
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
            component = map->map_arr[i][j];
            draw_component(component, i, j, game);
            if (component == 'P')
            {
                game->player_coord->x = j;
                game->player_coord->y = i;
            }
            j++;
        }
        i++;
    }
}

void    re_draw_player_movement(t_game *game)
{
    t_coord *player;
    t_coord *previous_step;

    player = game->player_coord;
    previous_step = game->step_coord;
    draw_component('P', player->y, player->x, game);
    draw_component('0', previous_step->y, previous_step->x, game);
}

t_coord *calculate_next_step(int keycode, t_game *game)
{
    t_coord current_player_position;
    t_coord *next_step;

    current_player_position = *(game->player_coord);
    next_step = game->step_coord;
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

void    move_forward(t_coord **to_go, t_coord **from)
{
    t_coord *tmp;

    tmp = *to_go;
    *to_go = *from;
    *from = tmp;
}

void    move_player(t_game *game, t_map *map)
{
    t_coord *player;
    t_coord *step;

    move_forward(&(game->step_coord), &(game->player_coord));
    player = game->player_coord;
    step = game->step_coord;
    map->map_arr[player->y][player->x] = 'P';
    map->map_arr[step->y][step->x] = '0';
    game->player_move++;
    printf("player move: %d\n", game->player_move);
}

int can_player_move(int keycode, t_game *game, t_map *map)
{
    t_coord *next_step;
    char    next_step_component;

    next_step = calculate_next_step(keycode, game);
    next_step_component = map->map_arr[next_step->y][next_step->x];
    if (next_step_component != '1')
    {
        if (next_step_component == 'C')
            map->item_num--;
        else if (next_step_component == 'E')
        {
            if (map->item_num == 0)
                map->exit_num = 0;
            else
                return (0);
        }
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
        if (can_player_move(keycode, game, game->map))
        {
            move_player(game, game->map);
            re_draw_player_movement(game);
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

    game = start_game(map);
    if (game)
        draw_mlx_win(game, map);
    mlx_hook(game->win, 2, 0, press_mov_key, game);
    mlx_hook(game->win, 17, 0, window_close, game);
    mlx_loop(game->mlx);
}