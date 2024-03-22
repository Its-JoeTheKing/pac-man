/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:43:02 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 13:40:17 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_pos(t_info *infos)
{
	int	i;
	int	j;

	i = 0;
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

void	xpm_to_img(t_info *infos)
{
	int	height;
	int	width;

	if (!infos->win)
		exit_game(infos, -3);
	config_movs_left(infos);
	config_movs_right(infos);
	config_movs_top(infos);
	config_movs_bottom(infos);
	infos->hero.img = mlx_xpm_file_to_image(infos->mlx,
			"./textures/pacs/pac_man_0.xpm", &width, &height);
	infos->floor = mlx_xpm_file_to_image(infos->mlx,
			"./textures/floor.xpm", &width, &height);
	infos->wall = mlx_xpm_file_to_image(infos->mlx,
			"./textures/wall.xpm", &width, &height);
	infos->collect = mlx_xpm_file_to_image(infos->mlx,
			"./textures/coin.xpm", &width, &height);
	infos->door = mlx_xpm_file_to_image(infos->mlx,
			"./textures/door.xpm", &width, &height);
	infos->door_op = mlx_xpm_file_to_image(infos->mlx,
			"./textures/doorop.xpm", &width, &height);
	infos->enemy.img = mlx_xpm_file_to_image(infos->mlx,
			"./textures/ghost/ghost.xpm", &width, &height);
	check_assets(infos);
}

void	img_win(void *mlx, void	*win, void *img, t_point pos)
{
	int	x;
	int	y;

	x = pos.x * 32;
	y = pos.y * 32;
	mlx_put_image_to_window(mlx, win, img, x, y);
}

void	exit_game(t_info *infos, int status)
{
	if (status == 0)
		write(1, "[3]  99085 segmentation [win]\n", 30);
	if (status == 1)
		write(1, "[3]  99085 segmentation [lost]\n", 31);
	if (status == -1)
		write(1, "Error\nInvalid Map", 17);
	if (status == -2)
		write(1, "Error\nInvalid Assets", 20);
	if (status == -3)
		write(1, "Internal Error", 14);
	if (status < 0)
		exit(-1);
	destroy_maps(infos);
	mlx_destroy_window(infos->mlx, infos->win);
	mlx_destroy_image(infos->mlx, infos->enemy.img);
	free_assets(infos);
	exit (0);
}

int	is_wall(t_info *infos, int x, int y)
{
	x /= 32;
	y /= 32;
	if (infos->map.map[y][x] == '1' || (infos->map.map[y][x] == 'E' &&
		infos->collected != infos->collectible))
		return (1);
	return (0);
}
