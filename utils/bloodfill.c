/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:21:04 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/16 13:54:46 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_tmp_map(t_info *infos)
{
	int		i;
	int		j;

	infos->tmp_map.size = infos->map.size;
	infos->tmp_map.map = malloc(sizeof(char *) * infos->map.size.y);
	if (!infos->tmp_map.map)
		exit(-1);
	i = -1;
	while (++i < infos->map.size.y)
	{
		infos->tmp_map.map[i] = malloc(sizeof(char) * infos->map.size.x);
		j = -1;
		while (++j < infos->map.size.x)
			infos->tmp_map.map[i][j] = infos->map.map[i][j];
	}
}

void	bloodfill(t_info *infs, t_point pos, t_point size)
{
	if (infs->tmp_map.map[pos.y][pos.x] == '1'
		|| infs->tmp_map.map[pos.y][pos.x] == 'X' )
		return ;
	infs->tmp_map.map[pos.y][pos.x] = 'X';
	if (infs->tmp_map.map[pos.y][pos.x + 1] != 'E')
		bloodfill(infs, (t_point){pos.x + 1, pos.y}, size);
	else
		infs->tmp_map.map[pos.y][pos.x + 1] = 'X';
	if (infs->tmp_map.map[pos.y][pos.x - 1] != 'E')
		bloodfill(infs, (t_point){pos.x - 1, pos.y}, size);
	else
		infs->tmp_map.map[pos.y][pos.x - 1] = 'X';
	if (infs->tmp_map.map[pos.y + 1][pos.x] != 'E')
		bloodfill(infs, (t_point){pos.x, pos.y + 1}, size);
	else
		infs->tmp_map.map[pos.y + 1][pos.x] = 'X';
	if (infs->tmp_map.map[pos.y - 1][pos.x] != 'E')
		bloodfill(infs, (t_point){pos.x, pos.y - 1}, size);
	else
		infs->tmp_map.map[pos.y - 1][pos.x] = 'X';
	return ;
}

void	verify_map(t_info *infos)
{
	int		i;
	int		j;

	i = -1;
	while (++i < infos->tmp_map.size.y)
	{
		j = -1;
		while (++j < infos->tmp_map.size.x)
		{
			if (infos->tmp_map.map[i][j] == 'C'
				|| infos->tmp_map.map[i][j] == 'E')
				infos->map.valid = 0;
		}
	}
}

void	check_assets(t_info *infos)
{
	if (!infos->floor || !infos->wall || !infos->collect
		|| !infos->door || !infos->door_op || !infos->enemy.img)
		exit_game(infos, -2);
}

int	is_clean_line(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != '\n')
			return (0);
	}
	return (1);
}
