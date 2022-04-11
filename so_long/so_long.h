/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:21:30 by hyunkkim          #+#    #+#             */
/*   Updated: 2022/04/08 12:05:31 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define UP      13
# define DOWN    1
# define RIGHT   2
# define LEFT    0
# define ESC     53

typedef struct s_map
{
	char	**map_arr;
	int		row;
	int		col;
	int		player_num;
	int		exit_num;
	int		item_num;
}	t_map;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		img_px;
	int		*wall;
	int		*space;
	int		*player;
	int		*exit;
	int		*item;
	t_coord	*player_coord;
	int		player_move;
	t_coord	*step_coord;
	t_map	*map;
}	t_game;

t_map	*parse_map(const char *dir);
int		open_map_file(const char *dir, int *fd);
t_map	*open_for_set_map_var(const char *dir, t_map *map, int *fd);
int		count_row_n_col(int map_fd, t_map *map);
t_map	*open_for_map_alloc(const char *dir, t_map *map, int *fd);
void	play_game(t_map *map);
t_game	*start_game(t_map *map);
t_game	*set_mlx(t_game *game, int img_px);
t_game	*set_img(t_game *game);
int		can_player_move(int keycode, t_game *game, t_map *map);
void	move_player(t_game *game, t_map *map);
void	draw_mlx_win(t_game *game, t_map *map);
void	re_draw_player_movement(t_game *game);
int		print_error(char *func, char *err_msg);
void	*malloc_error(char *func);
void	*mlx_error(char *func, char *err_msg);
void	ft_free(void *ptr);
void	*free_map(t_map *map);
void	*free_game(t_game *game);

#endif
