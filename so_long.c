/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:40 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/17 16:04:54 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	xpm_to_img(t_info *infos)
{
	int	height;
	int	width;

	infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/pac_man_0.xpm", &width, &height);
	infos->floor = mlx_xpm_file_to_image(infos->mlx, "./assets/floor.xpm", &width, &height);
	infos->wall = mlx_xpm_file_to_image(infos->mlx, "./assets/wall.xpm", &width, &height);
	infos->collect = mlx_xpm_file_to_image(infos->mlx, "./assets/coin.xpm", &width, &height);
	infos->door = mlx_xpm_file_to_image(infos->mlx, "./assets/door.xpm", &width, &height);
	infos->door_op = mlx_xpm_file_to_image(infos->mlx, "./assets/doorop.xpm", &width, &height);
	infos->enemy.img = mlx_xpm_file_to_image(infos->mlx, "./assets/ghost/ghost.xpm", &width, &height);
}

void	enemy_map(t_info *infos)
{
	int i = -1;
	int j = 0;

	if (!infos->enemy.map.map)
	{
		infos->enemy.map.map = (char **)malloc(sizeof(char *) * infos->map.height);
		while (++i < infos->map.height)
			infos->enemy.map.map[i] = (char *)malloc(infos->map.width + 1);
	}
	while (++i < infos->map.height)
	{
		j = -1;
		while (++j < infos->map.width)
		{
			infos->enemy.map.map[i][j] = infos->map.map[i][j];
			if(infos->map.map[i][j] == '1')
				infos->enemy.map.map[i][j] = 'W';
			if(infos->map.map[i][j] == 'C')
				infos->enemy.map.map[i][j] = '0';
		}
		infos->enemy.map.map[i][j] = 0;
	}
}

void	enemy_map_destroy(t_info *infos)
{
	int i = -1;

	while (++i < infos->map.height)
		free(infos->enemy.map.map[i]);
	free(infos->enemy.map.map);
}
int	move(int key, t_info *infos)
{
	if (key == 2 || key == 1 || key == 13 || key == 0)
	{
		animation_manage(infos);
		t_point s_enemy;
		s_enemy.x = infos->enemy.x;
		s_enemy.y = infos->enemy.y;
		t_point s_player;
		s_player.x = infos->hero.x / 32;
		s_player.y = infos->hero.y / 32;
		t_point size;
		size.x = infos->map.width;
		size.y = infos->map.height;
		enemy_map(infos);
		infos->enemy.road_len = floodmap(infos->enemy.map.map, s_player, size, s_enemy);
		infos->enemy.moves = 2;
		mlx_put_image_to_window(infos->mlx, infos->win, infos->enemy.img, infos->enemy.x * 32, infos->enemy.y * 32);
		mlx_put_image_to_window(infos->mlx, infos->win, infos->floor, infos->enemy.road[infos->enemy.moves - 1].x * 32, infos->enemy.road[infos->enemy.moves - 1].y * 32);
	}
	if (key == 2 && infos->map.map[infos->hero.y / 32][infos->hero.x / 32 + 1] != '1')
		put_img_right(infos, 0);
	if (key == 0 && infos->map.map[infos->hero.y / 32][infos->hero.x / 32 - 1] != '1')
		put_img_left(infos, 0);
	if (key == 1 && infos->map.map[infos->hero.y / 32 + 1][infos->hero.x / 32] != '1')
		put_img_bottom(infos, 0);
	if (key == 13 && infos->map.map[infos->hero.y / 32 - 1][infos->hero.x / 32] != '1')
		put_img_top(infos, 0);
	if (key == 53)
	{
		enemy_map_destroy(infos);
		mlx_destroy_window(infos->mlx, infos->win);
		system("leaks so_long");
		exit (0);
	}
	return (0);
}

void	draw_map(t_info *ifs)
{
	int i = -1;
	int j = 0;

	while (++i < ifs->map.height)
	{
		j = -1;
		while (++j < ifs->map.width)
		{
			if (ifs->map.map[i][j] == '1')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->wall, j*32, i*32);
			if (ifs->map.map[i][j] == '0')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->floor, j*32, i*32);
			if (ifs->map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->collect, j*32, i*32);
				ifs->collectible++;
			}
			if (ifs->map.map[i][j] == 'E')
			{
				ifs->door_pos.x = j*32;
				ifs->door_pos.y = i*32;
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->door, j*32, i*32);
			}
		}
	}
}

int	replay(t_info *info)
{
	static int door_opened = 0;
	static size_t i = 0;
	if (i == 1500)
	{
		info->hero.anime += 1;
		if (info->hero.anime == 5)
			info->hero.anime = 0;
		if (info->hero.pos == 'r')
			put_img_right(info, 1);
		if (info->hero.pos == 'l')
			put_img_left(info, 1);
		if (info->hero.pos == 't')
			put_img_top(info, 1);
		if (info->hero.pos == 'b')
			put_img_bottom(info, 1);
		t_point size;
		size.x = info->map.width;
		size.y = info->map.height;
		t_point s_enemy;
		s_enemy.x = info->enemy.x;
		s_enemy.y = info->enemy.y;
		info->enemy.road = get_road(info->enemy.map.map, size, s_enemy, info->enemy.road_len);
		info->enemy.x = info->enemy.road[info->enemy.moves].x;
		info->enemy.y = info->enemy.road[info->enemy.moves].y;
		mlx_put_image_to_window(info->mlx, info->win, info->enemy.img, info->enemy.x * 32, info->enemy.y * 32);
		mlx_put_image_to_window(info->mlx, info->win, info->floor, info->enemy.road[info->enemy.moves - 1].x * 32, info->enemy.road[info->enemy.moves - 1].y * 32);
		info->enemy.moves++;
		free(info->enemy.road);
		if (info->enemy.x == info->hero.x / 32 && info->enemy.y == info->hero.y / 32)
		{
			mlx_destroy_window(info->mlx, info->win);
			exit (0);
		}
		i = 0;
	}
	i++;
	if (info->collected == info->collectible && !door_opened)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->door_op, info->door_pos.x, info->door_pos.y);
		door_opened = 1;
	}
	if (info->collected == info->collectible && info->hero.x == info->door_pos.x && info->hero.y == info->door_pos.y)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit (0);
	}
	return (0);
}

void	get_player_pos(t_info *infos)
{
	int i = 0;
	int j = 0;

	while (i < infos->map.height)
	{
		j = 0;
		while (j < infos->map.width)
		{
			if (infos->map.map[i][j] == 'P')
			{
				infos->hero.x = j * 32;
				infos->hero.y = i * 32;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mapp_checker(t_info *infos, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit(0);
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
		return (0);
	mapp_checker(&infos, argv[1]);
	if (!infos.map.valid)
		return (0);
	infos.mlx = mlx_init();
	infos.hero.pos = 'r';
	infos.hero.anime = 0;
	infos.enemy.x = 1;
	infos.enemy.y = 1;
	xpm_to_img(&infos);
	infos.win = mlx_new_window(infos.mlx, (infos.map.width - 1) * 32, infos.map.height * 32, "so_long");
	draw_map(&infos);
	mlx_put_image_to_window(infos.mlx, infos.win, infos.enemy.img, 32, 32);
	t_point s_enemy;
	s_enemy.x = infos.enemy.x;
	s_enemy.y = infos.enemy.y;
	t_point s_player;
	s_player.x = infos.hero.x / 32;
	s_player.y = infos.hero.y / 32;
	t_point size;
	size.x = infos.map.width;
	size.y = infos.map.height;
	enemy_map(&infos);
	infos.enemy.road_len = floodmap(infos.enemy.map.map, s_player, size, s_enemy);
	infos.enemy.moves = 0;
	mlx_hook(infos.win, 2, 0, move, &infos);
	mlx_loop_hook(infos.mlx, replay, &infos);
	mlx_loop(infos.mlx);
}
