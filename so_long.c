/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:40 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/24 11:48:20 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_info *infos)
{
	int	height;
	int	width;

	infos->hero.img = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/pac_man_0.xpm", &width, &height);
	infos->floor = mlx_xpm_file_to_image(infos->mlx,
			"./assets/floor.xpm", &width, &height);
	infos->wall = mlx_xpm_file_to_image(infos->mlx,
			"./assets/wall.xpm", &width, &height);
	infos->collect = mlx_xpm_file_to_image(infos->mlx,
			"./assets/coin.xpm", &width, &height);
	infos->door = mlx_xpm_file_to_image(infos->mlx,
			"./assets/door.xpm", &width, &height);
	infos->door_op = mlx_xpm_file_to_image(infos->mlx,
			"./assets/doorop.xpm", &width, &height);
	infos->enemy.img = mlx_xpm_file_to_image(infos->mlx,
			"./assets/ghost/ghost.xpm", &width, &height);
}

void	enemy_map(t_info *infos)
{
	int	i;
	int	j;

	i = -1;
	if (!infos->enemy.map.map)
	{
		infos->enemy.map.map = malloc(sizeof(char *) * infos->map.size.y);
		if (!infos->enemy.map.map)
			exit (-1);
		while (++i < infos->map.size.y)
			infos->enemy.map.map[i] = (char *)malloc(infos->map.size.x + 1);
	}
	while (++i < infos->map.size.y)
	{
		j = -1;
		while (++j < infos->map.size.x)
		{
			infos->enemy.map.map[i][j] = infos->map.map[i][j];
			if (infos->map.map[i][j] == '1')
				infos->enemy.map.map[i][j] = 'W';
			if (infos->map.map[i][j] == 'C')
				infos->enemy.map.map[i][j] = '0';
		}
		infos->enemy.map.map[i][j] = 0;
	}
}

void	enemy_map_destroy(t_info *infos)
{
	int i;

	i = -1;
	while (++i < infos->map.size.y)
		free(infos->enemy.map.map[i]);
	free(infos->enemy.map.map);
}

void	exit_game(t_info *infos)
{
	enemy_map_destroy(infos);
	mlx_destroy_window(infos->mlx, infos->win);
	exit (0);
}

int	move(int key, t_info *infos)
{
	if (key == 2 || key == 1 || key == 13 || key == 0)
	{
		enemy_map(infos);
		infos->enemy.road_len = floodmap(infos->enemy.map.map, infos->hero.pos, infos->map.size, infos->enemy.pos);
		infos->enemy.moves = 2;
	}
	if (key == 2 && infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32 + 1] != '1')
		put_img_right(infos, 0);
	if (key == 0 && infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32 - 1] != '1')
		put_img_left(infos, 0);
	if (key == 1 && infos->map.map[infos->hero.pos.y / 32 + 1][infos->hero.pos.x / 32] != '1')
		put_img_bottom(infos, 0);
	if (key == 13 && infos->map.map[infos->hero.pos.y / 32 - 1][infos->hero.pos.x / 32] != '1')
		put_img_top(infos, 0);
	if (key == 53)
		exit_game(infos);
	return (0);
}

void	draw_map(t_info *ifs)
{
	int i = -1;
	int j = 0;

	while (++i < ifs->map.size.y)
	{
		j = -1;
		while (++j < ifs->map.size.x)
		{
			if (ifs->map.map[i][j] != 'P')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->floor, j * 32, i * 32);
			if (ifs->map.map[i][j] == '1')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->wall, j * 32, i * 32);
			if (ifs->map.map[i][j] == 'C')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->collect, j * 32, i * 32);
			if (ifs->map.map[i][j] == 'E')
			{
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->door, j * 32, i * 32);
				if (ifs->collected == ifs->collectible)
					mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->door_op, j * 32, i * 32);
			}
		}
	}
}

int	replay(t_info *info)
{
	static int door_opened = 0;
	static size_t i = 0;
	if (i == 3000)
	{
		info->hero.anime += 1;
		if (info->hero.anime == 5)
			info->hero.anime = 0;
		if (info->hero.posi == 'r')
			put_img_right(info, 1);
		if (info->hero.posi == 'l')
			put_img_left(info, 1);
		if (info->hero.posi == 't')
			put_img_top(info, 1);
		if (info->hero.posi == 'b')
			put_img_bottom(info, 1);
		draw_map(info);
		info->enemy.road = get_road(info->enemy.map.map, info->map.size, info->enemy.pos, info->enemy.road_len);
		info->enemy.pos.x = info->enemy.road[info->enemy.moves].x;
		info->enemy.pos.y = info->enemy.road[info->enemy.moves].y;
		mlx_put_image_to_window(info->mlx, info->win, info->enemy.img, info->enemy.road[info->enemy.moves].x * 32, info->enemy.road[info->enemy.moves].y * 32);
		info->enemy.moves++;
		if (info->enemy.moves - 2 == info->enemy.road_len)
			exit_game(info);
		printf("%d-%d\n", info->enemy.road_len, info->enemy.moves);
		free(info->enemy.road);
		i = 0;
	}
	i++;
	if (info->collected == info->collectible && !door_opened)
		door_opened = 1;
	if (info->collected == info->collectible && info->hero.pos.x == info->door_pos.x && info->hero.pos.y == info->door_pos.y)
		exit_game(info);
	return (0);
}

void	get_player_pos(t_info *infos)
{
	int i = 0;
	int j = 0;

	while (i < infos->map.size.y)
	{
		j = 0;
		while (j < infos->map.size.x)
		{
			if (infos->map.map[i][j] == 'P')
			{
				infos->hero.pos.x = j * 32;
				infos->hero.pos.y = i * 32;
			}
			if (infos->map.map[i][j] == 'E')
			{
				infos->door_pos.x = j * 32;
				infos->door_pos.y = i * 32;
			}
			if (infos->map.map[i][j] == 'C')
				infos->collectible++;
			j++;
		}
		i++;
	}
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
