/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:40 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/27 17:09:50 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key, t_info *infos)
{
	if (key == 2 || key == 1 || key == 13 || key == 0)
	{
		enemy_map(infos);
		infos->enemy.road_len = floodmap(infos->enemy.map.map, infos->hero.pos,
				infos->map.size, infos->enemy.pos);
		infos->enemy.moves = 2;
	}
	if (key == 2 && !is_wall(infos, infos->hero.pos.x + 32, infos->hero.pos.y))
		put_img_right(infos, 0);
	if (key == 0 && !is_wall(infos, infos->hero.pos.x - 32, infos->hero.pos.y))
		put_img_left(infos, 0);
	if (key == 1 && !is_wall(infos, infos->hero.pos.x, infos->hero.pos.y + 32))
		put_img_bottom(infos, 0);
	if (key == 13 && !is_wall(infos, infos->hero.pos.x, infos->hero.pos.y - 32))
		put_img_top(infos, 0);
	if (key == 53)
		exit_game(infos);
	return (0);
}

void	draw_map(t_info *ifs)
{
	t_point	pos;

	pos.y = -1;
	while (++(pos.y) < ifs->map.size.y)
	{
		pos.x = -1;
		while (++(pos.x) < ifs->map.size.x)
		{
			if (ifs->map.map[pos.y][pos.x] != 'P')
				img_win(ifs->mlx, ifs->win, ifs->floor, pos);
			if (ifs->map.map[pos.y][pos.x] == '1')
				img_win(ifs->mlx, ifs->win, ifs->wall, pos);
			if (ifs->map.map[pos.y][pos.x] == 'C')
				img_win(ifs->mlx, ifs->win, ifs->collect, pos);
			if (ifs->map.map[pos.y][pos.x] == 'E')
			{
				img_win(ifs->mlx, ifs->win, ifs->door, pos);
				if (ifs->collected == ifs->collectible)
					img_win(ifs->mlx, ifs->win, ifs->door_op, pos);
			}
		}
	}
}

int	replay(t_info *info)
{
	static int		door_opened = 0;
	static size_t	i = 0;

	if (i == 2500)
	{
		animation_manage(info);
		draw_map(info);
		info->enemy.road = get_road(info->enemy.map.map, info->map.size,
				info->enemy.pos, info->enemy.road_len);
		info->enemy.pos = info->enemy.road[info->enemy.moves];
		img_win(info->mlx, info->win, info->enemy.img,
			info->enemy.road[info->enemy.moves]);
		info->enemy.moves++;
		if (info->enemy.moves - 2 == info->enemy.road_len)
			exit_game(info);
		free(info->enemy.road);
		i = 0;
	}
	i++;
	if (info->collected == info->collectible && !door_opened)
		door_opened = 1;
	if (info->collected == info->collectible && info->hero.pos.x
		== info->door_pos.x && info->hero.pos.y == info->door_pos.y)
		exit_game(info);
	return (0);
}

void	mapp_checker(t_info *infos, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0 || read(fd, 0, 0) < 0)
		exit(-1);
	get_map(infos, fd);
	if (!infos->map.valid)
		return ;
	close(fd);
	fd = open(file, O_RDONLY);
	map_to_array(fd, infos);
	close(fd);
	check_map(infos);
	if (!infos->map.valid)
		return ;
	get_player_pos(infos);
	enemy_map(infos);
}

int	main(int argc, char **argv)
{
	t_info	infos;
	int		fd;

	if (argc != 2)
		return (-1);
	mapp_checker(&infos, argv[1]);
	if (!infos.map.valid)
		exit (-1);
	infos.mlx = mlx_init();
	infos.hero.posi = 'r';
	infos.hero.anime = 0;
	infos.enemy.pos.x = 1;
	infos.enemy.pos.y = 1;
	xpm_to_img(&infos);
	infos.win = mlx_new_window(infos.mlx, (infos.map.size.x - 1) * 32,
			infos.map.size.y * 32, "so_long");
	draw_map(&infos);
	mlx_put_image_to_window(infos.mlx, infos.win, infos.enemy.img, 32, 32);
	enemy_map(&infos);
	infos.enemy.road_len = floodmap(infos.enemy.map.map,
			infos.hero.pos, infos.map.size, infos.enemy.pos);
	infos.enemy.moves = 0;
	mlx_hook(infos.win, 2, 0, move, &infos);
	mlx_loop_hook(infos.mlx, replay, &infos);
	mlx_loop(infos.mlx);
}
