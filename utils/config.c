/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:16:44 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/28 14:59:35 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	config_movs_right(t_info *infos)
{
	infos->movs.hero_right_0 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/right/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_1 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/right/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_2 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/right/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_3 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/right/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_right_4 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/right/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_right_0 || !infos->movs.hero_right_1
		|| !infos->movs.hero_right_2 || !infos->movs.hero_right_3
		|| !infos->movs.hero_right_4)
		exit(-1);
}

void	config_movs_left(t_info *infos)
{
	infos->movs.hero_left_0 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/left/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_1 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/left/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_2 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/left/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_3 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/left/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_left_4 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/left/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_left_0 || !infos->movs.hero_left_1
		|| !infos->movs.hero_left_2 || !infos->movs.hero_left_3
		|| !infos->movs.hero_left_4)
		exit(-1);
}

void	config_movs_top(t_info *infos)
{
	infos->movs.hero_top_0 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/top/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_1 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/top/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_2 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/top/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_3 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/top/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_top_4 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/top/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_top_0 || !infos->movs.hero_top_1
		|| !infos->movs.hero_top_2 || !infos->movs.hero_top_3
		|| !infos->movs.hero_top_4)
		exit(-1);
}

void	config_movs_bottom(t_info *infos)
{
	infos->movs.hero_bottom_0 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/down/pac_man_0.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_1 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/down/pac_man_1.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_2 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/down/pac_man_2.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_3 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/down/pac_man_3.xpm", &infos->height, &infos->width);
	infos->movs.hero_bottom_4 = mlx_xpm_file_to_image(infos->mlx,
			"./assets/pacs/down/pac_man_4.xpm", &infos->height, &infos->width);
	if (!infos->movs.hero_bottom_0 || !infos->movs.hero_bottom_1
		|| !infos->movs.hero_bottom_2 || !infos->movs.hero_bottom_3
		|| !infos->movs.hero_bottom_4)
		exit(-1);
}
