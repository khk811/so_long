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