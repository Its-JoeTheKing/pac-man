/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:59:02 by aerrfig           #+#    #+#             */
/*   Updated: 2024/03/22 15:24:02 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_wall(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == '1')
		i++;
	return (i);
}

int	check_first_line(int fd, t_info *infs)
{
	char	*tmp;
	int		stat;

	stat = 0;
	tmp = get_next_line(fd);
	infs->map.valid = ft_strlen(tmp) > 0;
	if (!tmp)
		return (0);
	infs->map.size.x = ft_strlen(tmp);
	stat = (infs->map.size.x == check_wall(tmp) + 1);
	return (free(tmp), stat);
}

void	map_infos_valid(int fd, t_info *infs)
{
	char	*tmp;
	int		i;

	i = 1;
	infs->map.valid = check_first_line(fd, infs);
	tmp = get_next_line(fd);
	while (ft_strlen(tmp))
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp || ft_strlen(tmp) != infs->map.size.x)
			break ;
		if (tmp[infs->map.size.x - 2] != '1' || tmp[0] != '1')
			infs->map.valid = 0;
		infs->map.valid *= is_clean_line(tmp);
		i++;
	}
	if ((ft_strlen(tmp) != infs->map.size.x - 1)
		|| (check_wall(tmp) != infs->map.size.x - 1))
		infs->map.valid = 0;
	free(tmp);
	infs->map.size.y = i + 2;
}

int	map_to_array(int fd, t_info *infs)
{
	int	i;

	i = 0;
	infs->map.map = malloc((infs->map.size.y + 1) * sizeof(char *));
	if (!(infs->map.map))
		exit (-1);
	while (i < infs->map.size.y)
	{
		infs->map.map[i] = get_next_line(fd);
		i++;
	}
	infs->map.map[i] = 0;
	return (0);
}

void	check_map(t_info *infs)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = -1;
	c = 0;
	e = 0;
	p = 0;
	while (++i < infs->map.size.y)
	{
		j = -1;
		while (++j < infs->map.size.x)
		{
			if (infs->map.map[i][j] == 'C')
				c++;
			if (infs->map.map[i][j] == 'E')
				e++;
			if (infs->map.map[i][j] == 'P')
				p++;
		}
	}
	if (c < 1 || e != 1 || p != 1)
		exit_game(infs, -1);
}

void	allocate_enemy_map(t_info *infos)
{
	int	i;

	i = -1;
	infos->enemy.map.map = malloc(sizeof(char *) * infos->map.size.y);
	if (!infos->enemy.map.map)
		exit (-1);
	while (++i < infos->map.size.y)
		infos->enemy.map.map[i] = (char *)malloc(infos->map.size.x + 1);
}
