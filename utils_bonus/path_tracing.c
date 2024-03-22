/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:12 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/16 13:54:38 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_corners(char **map, t_point *pos, t_point size, int val)
{
	if (pos->x + 1 < size.x && pos->y + 1 < size.y
		&& map[pos->y + 1][pos->x + 1] == val)
	{
		pos->x++;
		pos->y++;
	}
	if (pos->x - 1 >= 0 && pos->y - 1 >= 0
		&& map[pos->y - 1][pos->x - 1] == val)
	{
		pos->x--;
		pos->y--;
	}
	if (pos->x + 1 < size.x && pos->y - 1 >= 0
		&& map[pos->y - 1][pos->x + 1] == val)
	{
		pos->x++;
		pos->y--;
	}
	if (pos->x - 1 >= 0 && pos->y + 1 < size.y
		&& map[pos->y + 1][pos->x - 1] == val)
	{
		pos->x--;
		pos->y++;
	}
}

t_point	get_next_pos(char **map, t_point size, t_point pont, int val)
{
	t_point	pos;

	pos.y = pont.y;
	pos.x = pont.x;
	pos.x += (pos.x + 1 < size.x && map[pos.y][pos.x + 1] == val) * 1;
	pos.x -= (pos.x - 1 >= 0 && map[pos.y][pos.x - 1] == val) * 1;
	pos.y += (pos.y + 1 < size.y && map[pos.y + 1][pos.x] == val) * 1;
	pos.y -= (pos.y - 1 >= 0 && map[pos.y - 1][pos.x] == val) * 1;
	check_corners(map, &pos, size, val);
	return (pos);
}

t_point	*get_road(char **map, t_point size, t_point pos, int val)
{
	t_point	*road;
	int		i;

	i = 0;
	road = (t_point *)malloc(sizeof(t_point) * (val + 2));
	if (!road)
		exit(-1);
	road[i] = pos;
	while (val > 0)
	{
		road[i + 1] = get_next_pos(map, size, road[i], val + 48);
		val--;
		i++;
	}
	road[i] = get_next_pos(map, size, road[i], 'P');
	road[i + 1].x = 0;
	road[i + 1].y = 0;
	return (road);
}

void	enemy_map(t_info *infos)
{
	int	i;
	int	j;

	i = -1;
	while (++i < infos->map.size.y)
	{
		j = -1;
		while (++j < infos->map.size.x)
		{
			infos->enemy.map.map[i][j] = infos->map.map[i][j];
			if (infos->map.map[i][j] == '1')
				infos->enemy.map.map[i][j] = 'W';
			if (infos->map.map[i][j] == 'C')
				infos->enemy.map.map[i][j] = '0';
		}
		infos->enemy.map.map[i][j] = 0;
	}
}

void	destroy_maps(t_info *infos)
{
	int	i;

	i = -1;
	if (infos->map.map)
	{
		while (++i < infos->map.size.y)
			free(infos->map.map[i]);
		free(infos->map.map);
	}
	if (infos->enemy.map.map)
	{
		i = -1;
		while (++i < infos->map.size.y)
			free(infos->enemy.map.map[i]);
		free(infos->enemy.map.map);
	}
	if (infos->tmp_map.map)
	{
		i = -1;
		while (++i < infos->tmp_map.size.y)
			free(infos->tmp_map.map[i]);
		free(infos->tmp_map.map);
	}
}
