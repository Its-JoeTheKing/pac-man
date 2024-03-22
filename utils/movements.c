/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:10:05 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/22 12:18:01 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	infos->hero.img = infos->movs.hero_right_0;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x - (32 * !isIdle), infos->hero.pos.y);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_left(t_info *infos)
{
	infos->hero.posi = 'l';
	infos->count += 1;
	infos->collected += 1 * (infos->map.map[infos->hero.pos.y / 32]
		[(infos->hero.pos.x - 32) / 32] == 'C');
	infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
	infos->hero.pos.x -= 32;
	infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	infos->hero.img = infos->movs.hero_left_0;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x + 32, infos->hero.pos.y);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_top(t_info *infos)
{
	infos->hero.posi = 't';
	infos->count += 1;
	infos->collected += 1 * (infos->map.map[(infos->hero.pos.y - 32) / 32]
		[infos->hero.pos.x / 32] == 'C');
	infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
	infos->hero.pos.y -= 32;
	infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	infos->hero.img = infos->movs.hero_top_0;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x, infos->hero.pos.y + 32);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_bottom(t_info *infos)
{
	infos->hero.posi = 'b';
	infos->count += 1;
	infos->collected += 1 * (infos->map.map[(infos->hero.pos.y + 32) / 32]
		[infos->hero.pos.x / 32] == 'C');
	infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
	infos->hero.pos.y += 32;
	infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	infos->hero.img = infos->movs.hero_bottom_0;
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor,
		infos->hero.pos.x, infos->hero.pos.y - 32);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img,
		infos->hero.pos.x, infos->hero.pos.y);
}

void	animation_manage(t_info *infos)
{
	if (infos->hero.posi == 'r')
		put_img_right(infos, 0);
	if (infos->hero.posi == 'l')
		put_img_left(infos);
	if (infos->hero.posi == 't')
		put_img_top(infos);
	if (infos->hero.posi == 'b')
		put_img_bottom(infos);
}
