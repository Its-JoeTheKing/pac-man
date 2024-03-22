/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:49 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/22 12:26:16 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>

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

typedef struct s_mov
{
	void	*hero_top_0;
	void	*hero_top_1;
	void	*hero_top_2;
	void	*hero_top_3;
	void	*hero_top_4;
	void	*hero_bottom_0;
	void	*hero_bottom_1;
	void	*hero_bottom_2;
	void	*hero_bottom_3;
	void	*hero_bottom_4;
	void	*hero_left_0;
	void	*hero_left_1;
	void	*hero_left_2;
	void	*hero_left_3;
	void	*hero_left_4;
	void	*hero_right_0;
	void	*hero_right_1;
	void	*hero_right_2;
	void	*hero_right_3;
	void	*hero_right_4;
}	t_mov;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		count;
	t_map	tmp_map;
	t_mov	movs;
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

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	put_img_right(t_info *infos, int isIdle);
void	put_img_left(t_info *infos);
void	put_img_top(t_info *infos);
void	put_img_bottom(t_info *infos);
void	animation_manage(t_info *infos);
int		map_to_array(int fd, t_info *infs);
void	check_map(t_info *infs);
char	*ft_strdup(const char *s1);
void	animation_manage(t_info *infos);
void	destroy_maps(t_info *infos);
void	get_player_pos(t_info *infos);
void	xpm_to_img(t_info *infos);
void	img_win(void *mlx, void	*win, void *img, t_point pos);
void	exit_game(t_info *infos, int status);
int		is_wall(t_info *infos, int x, int y);
void	config_movs(t_info *infos);
void	create_tmp_map(t_info *infos);
void	bloodfill(t_info *infs, t_point pos, t_point size);
void	verify_map(t_info *infos);
void	check_assets(t_info *infos);
void	free_assets(t_info *infos);
int		is_clean_line(char *str);
void	ft_putnbr(int nb);
void	map_infos_valid(int fd, t_info *infs);
int		close_win(t_info *infos);

#endif