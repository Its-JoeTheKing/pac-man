/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:43:02 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/28 14:55:52 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	config_movs_left(infos);
	config_movs_right(infos);
	config_movs_top(infos);
	config_movs_bottom(infos);
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

void	img_win(void *mlx, void	*win, void *img, t_point pos)
{
	int	x;
	int	y;

	x = pos.x * 32;
	y = pos.y * 32;
	mlx_put_image_to_window(mlx, win, img, x, y);
}

void	exit_game(t_info *infos)
{
	enemy_map_destroy(infos);
	mlx_destroy_window(infos->mlx, infos->win);
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
