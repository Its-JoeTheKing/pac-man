/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:44 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 12:43:44 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	config_movs(t_info *infos)
{
	infos->movs.hero_right_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/right/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/left/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/top/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/down/pac_man_0.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_right_0 || !infos->movs.hero_left_0
		|| !infos->movs.hero_top_0 || !infos->movs.hero_bottom_0)
	{
		write(1, "Error\nInvalid textures", 20);
		exit_game(infos, -2);
	}
}

void	free_assets(t_info *infos)
{
	mlx_destroy_image(infos->mlx, infos->floor);
	mlx_destroy_image(infos->mlx, infos->wall);
	mlx_destroy_image(infos->mlx, infos->collect);
	mlx_destroy_image(infos->mlx, infos->door);
	mlx_destroy_image(infos->mlx, infos->door_op);
	mlx_destroy_image(infos->mlx, infos->movs.hero_bottom_0);
	mlx_destroy_image(infos->mlx, infos->movs.hero_top_0);
	mlx_destroy_image(infos->mlx, infos->movs.hero_left_0);
	mlx_destroy_image(infos->mlx, infos->movs.hero_right_0);
}
