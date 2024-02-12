/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:17:12 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/12 11:59:42 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_corners(char **map, t_point *pos, t_point size, int val)
{
	
	if (pos->x + 1 < size.x && pos->y + 1 < size.y && map[pos->y + 1][pos->x + 1] == val)
	{
		pos->x++;
		pos->y++;
	}
	if (pos->x - 1 >= 0 && pos->y - 1 >= 0 && map[pos->y - 1][pos->x - 1] == val)
	{
		pos->x--;
		pos->y--;
	}
	if (pos->x + 1 < size.x && pos->y - 1 >= 0 && map[pos->y - 1][pos->x + 1] == val)
	{
		pos->x++;
		pos->y--;
	}
	if (pos->x - 1 >= 0 && pos->y + 1 < size.y && map[pos->y + 1][pos->x - 1] == val)
	{
		pos->x--;
		pos->y++;
	}
}

t_point get_next_pos(char **map, t_point size, t_point pont, int val)
{
	t_point pos;

	pos.y = pont.y;
	pos.x = pont.x;
	pos.x += (pos.x + 1 < size.x && map[pos.y][pos.x + 1] == val) * 1;
	pos.x -= (pos.x - 1 >= 0 && map[pos.y][pos.x - 1] == val) * 1;
	pos.y += (pos.y + 1 < size.y && map[pos.y + 1][pos.x] == val) * 1;
	pos.y -= (pos.y - 1 >= 0 && map[pos.y - 1][pos.x] == val) * 1;
	if (map[pos.y][pos.x] == val)
		return (pos);
	check_corners(map, &pos, size, val);
	return (pos);
}

t_point	*get_road(char **map, t_point size, t_point pos, int val)
{
	t_point	*road;
	int		i;

	i = 0;
	road = (t_point *)malloc(sizeof(t_point) * (val + 2));
	road[0] = pos;
	while (val > 0)
	{
		road[i + 1] = get_next_pos(map, size, road[i], val);
		val--;
		i++;
	}
	road[i] = get_next_pos(map, size, road[i], 'P');
	road[i + 1].x = 0;
	road[i + 1].y = 0;
	return (road);
}
