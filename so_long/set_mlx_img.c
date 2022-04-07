#include "so_long.h"

t_game  *set_mlx(t_game *game, int img_px)
{
    int width;
    int height;

    if (!game)
        return (NULL);
    game->mlx = mlx_init();
    if (!(game->mlx))
        return (mlx_error("set_mlx()", "mlx init failed"));
    game->img_px = img_px;
    width = img_px * (game->map->col);
    height = img_px * (game->map->row);
    game->win = mlx_new_window(game->mlx, width, height, "so_long");
    if (!(game->win))
        return (mlx_error("set_mlx()", "can't create new mlx window"));
    return (game);
}

t_game  *set_img(t_game *game)
{
    int *px;
    void    *mlx;

    px = &(game->img_px);
    mlx = game->mlx;
    game->wall = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", px, px);
    game->space = mlx_xpm_file_to_image(mlx, "./img/void0.xpm", px, px);
    game->player = mlx_xpm_file_to_image(mlx, "./img/playerP.xpm", px, px);
    game->exit = mlx_xpm_file_to_image(mlx, "./img/exitE.xpm", px, px);
    game->item = mlx_xpm_file_to_image(mlx, "./img/itemC.xpm", px, px);
    if (!(game->wall) || !(game->space) || !(game->player) \
        || !(game->exit) || !(game->item))
        return (mlx_error("load_img()", "failed to load xpm image(s)"));
    return (game);
}