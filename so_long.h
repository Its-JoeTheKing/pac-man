/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:49 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/24 14:06:04 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ff/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_map
{
	char	**map;
	t_point	size;
	char	valid;
}	t_map;

typedef struct s_hero
{
	void	*img;
	t_point	pos;
	int		anime;
	char	posi;
}	t_hero;

typedef struct s_enemy
{
	void	*img;
	t_map	map;
	t_point	*road;
	int		moves;
	int		road_len;
	t_point	pos;
	int		anime;
}	t_enemy;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_hero	hero;
	t_enemy	enemy;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*door;
	void	*door_op;
	int		collectible;
	int		collected;
	t_point	door_pos;
	t_map	map;
}	t_info;

void	put_img_right(t_info *infos, int isIdle);
void	put_img_left(t_info *infos, int isIdle);
void	put_img_top(t_info *infos, int isIdle);
void	put_img_bottom(t_info *infos, int isIdle);
void	animation_manage(t_info *infos);
int		get_map(t_info *map, int fd);
int		map_to_array(int fd, t_info *infs);
void	check_map(t_info *infs);
char	*ft_strdup(const char *s1);
int		floodmap(char **map, t_point player, t_point size, t_point enemy);
t_point	*get_road(char **map, t_point size, t_point pos, int vals);
void	animation_manage(t_info *infos);
void	enemy_map(t_info *infos);
void	enemy_map_destroy(t_info *infos);
void	get_player_pos(t_info *infos);
void	xpm_to_img(t_info *infos);
void	img_win(void *mlx, void	*win, void *img, t_point pos);
void	exit_game(t_info *infos);
int		is_wall(t_info *infos, int x, int y);

#endif