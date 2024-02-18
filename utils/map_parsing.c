/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:59:02 by aerrfig           #+#    #+#             */
/*   Updated: 2024/02/18 14:09:57 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '1')
		i++;
	return (i);
}

void	map_infos_valid(int fd, t_info *infs)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = get_next_line(fd);
	infs->map.width = ft_strlen(tmp);
	if (infs->map.width != check_wall(tmp) + 1)
		infs->map.valid = 0;
	free(tmp);
	while (ft_strlen(tmp) == infs->map.width)
	{
		if (tmp[infs->map.width - 2] != '1' || tmp[0] != '1')
			infs->map.valid = 0;
		tmp = get_next_line(fd);
		free(tmp);
		i++;
	}
	if ((ft_strlen(tmp) != infs->map.width - 1)
		|| (check_wall(tmp) != infs->map.width - 1))
		infs->map.valid = 0;
	infs->map.height = i;
}

int	map_to_array(int fd, t_info *infs)
{
	int	i;

	i = 0;
	infs->map.map = malloc((infs->map.height + 1) * sizeof(char *));
	if (!(infs->map.map))
		return (0);
	while (i < infs->map.height)
	{
		infs->map.map[i] = get_next_line(fd);
		i++;
	}
	infs->map.map[i] = 0;
	return (0);
}

int	get_map(t_info *infs, int fd)
{
	char	**res;

	infs->map.valid = 1;
	if (fd <= 0)
		return (0);
	map_infos_valid(fd, infs);
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
	while (++i < infs->map.height)
	{
		j = -1;
		while (++j < infs->map.width)
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
		infs->map.valid = 0;
}
