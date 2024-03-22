/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:44 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/21 12:31:12 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	config_movs_right(t_info *infos)
{
	infos->movs.hero_right_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/right/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_1 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/right/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_2 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/right/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_3 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/right/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_4 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/right/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_right_0 || !infos->movs.hero_right_1
		|| !infos->movs.hero_right_2 || !infos->movs.hero_right_3
		|| !infos->movs.hero_right_4)
	{
		write(1, "Error\nInvalid textures", 20);
		exit(-1);
	}
}

void	config_movs_left(t_info *infos)
{
	infos->movs.hero_left_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/left/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_1 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/left/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_2 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/left/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_3 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/left/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_4 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/left/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_left_0 || !infos->movs.hero_left_1
		|| !infos->movs.hero_left_2 || !infos->movs.hero_left_3
		|| !infos->movs.hero_left_4)
	{
		write(1, "Error\nInvalid textures", 20);
		exit(-1);
	}
}

void	config_movs_top(t_info *infos)
{
	infos->movs.hero_top_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/top/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_1 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/top/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_2 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/top/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_3 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/top/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_4 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/top/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_top_0 || !infos->movs.hero_top_1
		|| !infos->movs.hero_top_2 || !infos->movs.hero_top_3
		|| !infos->movs.hero_top_4)
	{
		write(1, "Error\nInvalid textures", 20);
		exit(-1);
	}
}

void	config_movs_bottom(t_info *infos)
{
	infos->movs.hero_bottom_0 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/down/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_1 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/down/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_2 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/down/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_3 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/down/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_4 = mlx_xpm_file_to_image(infos->mlx,
			"textures/pacs/down/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_bottom_0 || !infos->movs.hero_bottom_1
		|| !infos->movs.hero_bottom_2 || !infos->movs.hero_bottom_3
		|| !infos->movs.hero_bottom_4)
	{
		write(1, "Error\nInvalid textures", 20);
		exit(-1);
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
	mlx_destroy_image(infos->mlx, infos->movs.hero_bottom_1);
	mlx_destroy_image(infos->mlx, infos->movs.hero_bottom_2);
	mlx_destroy_image(infos->mlx, infos->movs.hero_bottom_3);
	mlx_destroy_image(infos->mlx, infos->movs.hero_bottom_4);
	mlx_destroy_image(infos->mlx, infos->movs.hero_top_0);
	mlx_destroy_image(infos->mlx, infos->movs.hero_top_1);
	mlx_destroy_image(infos->mlx, infos->movs.hero_top_2);
	mlx_destroy_image(infos->mlx, infos->movs.hero_top_3);
	mlx_destroy_image(infos->mlx, infos->movs.hero_top_4);
	mlx_destroy_image(infos->mlx, infos->movs.hero_left_0);
	mlx_destroy_image(infos->mlx, infos->movs.hero_left_1);
	mlx_destroy_image(infos->mlx, infos->movs.hero_left_2);
	mlx_destroy_image(infos->mlx, infos->movs.hero_left_3);
	mlx_destroy_image(infos->mlx, infos->movs.hero_left_4);
	mlx_destroy_image(infos->mlx, infos->movs.hero_right_0);
	mlx_destroy_image(infos->mlx, infos->movs.hero_right_1);
	mlx_destroy_image(infos->mlx, infos->movs.hero_right_2);
	mlx_destroy_image(infos->mlx, infos->movs.hero_right_3);
	mlx_destroy_image(infos->mlx, infos->movs.hero_right_4);
}
