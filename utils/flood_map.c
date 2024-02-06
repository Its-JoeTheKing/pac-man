/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:48:33 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/06 18:07:59 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_is_surrounded(char **map, t_point enemy, t_point size)
{
	int is_surrounded;

	is_surrounded = 0;
	if (enemy.x + 1 < size.x && map[enemy.y][enemy.x + 1] != '0')
		is_surrounded = 1;
	if (enemy.x - 1 >= 0 && map[enemy.y][enemy.x - 1] != '0')
		is_surrounded = 1;
	if (enemy.y + 1 < size.y && map[enemy.y + 1][enemy.x] != '0')
		is_surrounded = 1;
	if (enemy.y - 1 >= 0 && map[enemy.y - 1][enemy.x] != '0')
		is_surrounded = 1;
	if (enemy.x + 1 < size.x && enemy.y + 1 < size.y && map[enemy.y + 1][enemy.x + 1] != '0')
		is_surrounded = 1;
	if (enemy.x - 1 >= 0 && enemy.y - 1 >= 0 && map[enemy.y - 1][enemy.x - 1] != '0')
		is_surrounded = 1;
	if (enemy.x + 1 < size.x && enemy.y - 1 >= 0 && map[enemy.y - 1][enemy.x + 1] != '0')
		is_surrounded = 1;
	if (enemy.x - 1 >= 0 && enemy.y + 1 < size.y && map[enemy.y + 1][enemy.x - 1] != '0')
		is_surrounded = 1;
	return (is_surrounded);
}

void	init_val(char **map, t_point player, t_point size, int val)
{
	int	x;
	int	y;

	x = player.x;
	y = player.y;
	if (x + 1 < size.x && map[y][x + 1] == '0')
		map[y][x + 1] = val + 48;
	if (x - 1 >= 0 && map[y][x - 1] == '0')
		map[y][x - 1] = val + 48;
	if (y + 1 < size.y && map[y + 1][x] == '0')
		map[y + 1][x] = val + 48;
	if (y - 1 >= 0 && map[y - 1][x] == '0')
		map[y - 1][x] = val + 48;
	if (x + 1 < size.x && y + 1 < size.y && map[y + 1][x + 1] == '0')
		map[y + 1][x + 1] = val + 48;
	if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1] == '0')
		map[y - 1][x - 1] = val + 48;
	if (x + 1 < size.x && y - 1 >= 0 && map[y - 1][x + 1] == '0')
		map[y - 1][x + 1] = val + 48;
	if (x - 1 >= 0 && y + 1 < size.y && map[y + 1][x - 1] == '0')
		map[y + 1][x - 1] = val + 48;
	if (map[y][x + 1] == 'E' || map[y][x - 1] == 'E' || map[y + 1][x] == 'E' || map[y - 1][x] == 'E')
		return ;
}

void	init_val_2(char **map, t_point size, int val)
{
	int		i_row;
	int		i_dice;
	t_point	player;

	i_row = -1;
	while (++i_row < size.y)
	{
		i_dice = -1;
		while (++i_dice < size.x)
		{
			if (map[i_row][i_dice] == val + 48 - 1)
			{
				player.x = i_dice;
				player.y = i_row;
				init_val (map, player, size, val);
			}
		}
	}
}
void	floodmap(char **map, t_point player, t_point size, t_point enemy)
{
	int	val;

	val = 1;
	init_val(map, player, size, val++);
	while (check_is_surrounded(map, enemy, size) == 0)
		init_val_2(map, size ,val++);
}