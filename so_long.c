/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:40 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/25 16:48:24 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/so_long.h"

int	move(int key, t_info *infos)
{
	static int	count = 0;

	if (key == 2 || key == 1 || key == 13 || key == 0)
	{
		if (count != infos->count)
		{
			count = infos->count;
			ft_putnbr(infos->count);
			write(1, "\n", 1);
		}
	}
	if (key == 2 && !is_wall(infos, infos->hero.pos.x + 32, infos->hero.pos.y))
		put_img_right(infos, 0);
	if (key == 0 && !is_wall(infos, infos->hero.pos.x - 32, infos->hero.pos.y))
		put_img_left(infos);
	if (key == 1 && !is_wall(infos, infos->hero.pos.x, infos->hero.pos.y + 32))
		put_img_bottom(infos);
	if (key == 13 && !is_wall(infos, infos->hero.pos.x, infos->hero.pos.y - 32))
		put_img_top(infos);
	if (key == 53)
		exit_game(infos, 1);
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

	if (info->collected == info->collectible && !door_opened)
	{
		door_opened = 1;
		mlx_put_image_to_window(info->mlx, info->win, info->door_op,
			info->door_pos.x, info->door_pos.y);
	}
	if (info->collected == info->collectible && info->hero.pos.x
		== info->door_pos.x && info->hero.pos.y == info->door_pos.y)
		exit_game(info, 0);
	return (0);
}

void	mapp_checker(t_info *infos, char *file)
{
	int		fd;
	t_point	pos;

	fd = open(file, O_RDONLY);
	if (fd <= 0 || read(fd, 0, 0) < 0)
		exit_game(infos, -1);
	map_infos_valid(fd, infos);
	close(fd);
	if (!infos->map.valid)
		exit_game(infos, -1);
	fd = open(file, O_RDONLY);
	map_to_array(fd, infos);
	close(fd);
	check_map(infos);
	get_player_pos(infos);
	pos.x = infos->hero.pos.x / 32;
	pos.y = infos->hero.pos.y / 32;
	create_tmp_map(infos);
	bloodfill(infos, pos, infos->map.size);
	verify_map(infos);
	if (!infos->map.valid)
		exit_game(infos, -1);
	infos->count = 0;
	infos->hero.anime = 0;
}

int	main(int argc, char **argv)
{
	t_info	infos;

	if (argc != 2)
		exit (-1);
	infos.mlx = mlx_init();
	if (!infos.mlx)
		exit_game(&infos, -3);
	mapp_checker(&infos, argv[1]);
	infos.win = mlx_new_window(infos.mlx, (infos.map.size.x - 1) * 32,
			infos.map.size.y * 32, "so_long");
	if (!infos.win)
		exit_game(&infos, -3);
	infos.hero.posi = 'r';
	xpm_to_img(&infos);
	draw_map(&infos);
	put_img_right(&infos, 1);
	mlx_hook(infos.win, 2, 0, move, &infos);
	mlx_hook(infos.win, 17, 0, close_win, &infos);
	mlx_loop_hook(infos.mlx, replay, &infos);
	mlx_loop(infos.mlx);
}
