/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:49 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/06 18:08:15 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define	SO_LONG_H

typedef	struct s_hero
{
	void	*img;
	int		x;
	int		y;
	int		anime;
	char	pos;
}	t_hero;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	valid;
} t_map;

typedef	struct s_info
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_hero	hero;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*door;
	void	*door_op;
	int		collectible;
	int		collected;
	int		door_x;
	int		door_y;
	t_map	map;
}	t_info;

typedef	struct s_point
{
	int		x;
	int		y;
}	t_point;

#include "ff/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>

void	put_img_right(t_info *infos, int isIdle);
void	put_img_left(t_info *infos, int isIdle);
void	put_img_top(t_info *infos, int isIdle);
void	put_img_bottom(t_info *infos, int isIdle);
void	animation_manage(t_info *infos);
int		get_map(t_info *map, int fd);
int		map_to_array(int fd, t_info *infs);
void	check_map(t_info *infs);
void	aff_map(char **map, t_point size);
char	*ft_strdup(const char *s1);
void	floodmap(char **map, t_point player, t_point size, t_point enemy);

#endif