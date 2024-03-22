/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:10:05 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/17 14:51:04 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img_right(t_info *infos, int isIdle)
{
	infos->hero.posi = 'r';
	if (!isIdle)
	{
		infos->count += 1;
		infos->collected += 1 * (infos->map.map[infos->hero.pos.y / 32]
			[(infos->hero.pos.x + 32) / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.x += 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.anime == 0)
		infos->hero.img = infos->movs.hero_right_0;
	if (infos->hero.anime == 1)
		infos->hero.img = infos->movs.hero_right_1;
	if (infos->hero.anime == 2)
		infos->hero.img = infos->movs.hero_right_2;
	if (infos->hero.anime == 3)
		infos->hero.img = infos->movs.hero_right_3;
	if (infos->hero.anime == 4)
		infos->hero.img = infos->movs.hero_right_4;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x - (32 * !isIdle), infos->hero.pos.y);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_left(t_info *infos, int isIdle)
{
	infos->hero.posi = 'l';
	if (!isIdle)
	{
		infos->count += 1;
		infos->collected += 1 * (infos->map.map[infos->hero.pos.y / 32]
			[(infos->hero.pos.x - 32) / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.x -= 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.anime == 0)
		infos->hero.img = infos->movs.hero_left_0;
	if (infos->hero.anime == 1)
		infos->hero.img = infos->movs.hero_left_1;
	if (infos->hero.anime == 2)
		infos->hero.img = infos->movs.hero_left_2;
	if (infos->hero.anime == 3)
		infos->hero.img = infos->movs.hero_left_3;
	if (infos->hero.anime == 4)
		infos->hero.img = infos->movs.hero_left_4;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x + (32 * !isIdle), infos->hero.pos.y);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_top(t_info *infos, int isIdle)
{
	infos->hero.posi = 't';
	if (!isIdle)
	{
		infos->count += 1;
		infos->collected += 1 * (infos->map.map[(infos->hero.pos.y - 32) / 32]
			[infos->hero.pos.x / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.y -= 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.anime == 0)
		infos->hero.img = infos->movs.hero_top_0;
	if (infos->hero.anime == 1)
		infos->hero.img = infos->movs.hero_top_1;
	if (infos->hero.anime == 2)
		infos->hero.img = infos->movs.hero_top_2;
	if (infos->hero.anime == 3)
		infos->hero.img = infos->movs.hero_top_3;
	if (infos->hero.anime == 4)
		infos->hero.img = infos->movs.hero_top_4;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x, infos->hero.pos.y + (32 * !isIdle));
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_bottom(t_info *infos, int isIdle)
{
	infos->hero.posi = 'b';
	if (!isIdle)
	{
		infos->count += 1;
		infos->collected += 1 * (infos->map.map[(infos->hero.pos.y + 32) / 32]
			[infos->hero.pos.x / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.y += 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.anime == 0)
		infos->hero.img = infos->movs.hero_bottom_0;
	if (infos->hero.anime == 1)
		infos->hero.img = infos->movs.hero_bottom_1;
	if (infos->hero.anime == 2)
		infos->hero.img = infos->movs.hero_bottom_2;
	if (infos->hero.anime == 3)
		infos->hero.img = infos->movs.hero_bottom_3;
	if (infos->hero.anime == 4)
		infos->hero.img = infos->movs.hero_bottom_4;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x, infos->hero.pos.y - (32 * !isIdle));
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	animation_manage(t_info *infos)
{
	infos->hero.anime += 1;
	if (infos->hero.anime == 5)
		infos->hero.anime = 0;
	if (infos->hero.posi == 'r')
		put_img_right(infos, 1);
	if (infos->hero.posi == 'l')
		put_img_left(infos, 1);
	if (infos->hero.posi == 't')
		put_img_top(infos, 1);
	if (infos->hero.posi == 'b')
		put_img_bottom(infos, 1);
}
