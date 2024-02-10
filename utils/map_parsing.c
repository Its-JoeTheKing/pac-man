#include "../so_long.h"
int	check_wall(char *str)
{
	int	i = 0;
	while (str[i] == '1')
	{
		i++;
	}
	return (i);
}

void	map_infos_valid(int fd, t_info *infs)
{
	char	*tmp;
	int		i = 1;

	tmp = get_next_line(fd);
	infs->map.width = ft_strlen(tmp);
	if (infs->map.width != check_wall(tmp) + 1)
		infs->map.valid = 0;
	free(tmp);
	while (ft_strlen(tmp) == infs->map.width)
	{
		if (tmp[infs->map.width - 2] != '1' || tmp[0] != '1')
			infs->map.valid  = 0;
		tmp = get_next_line(fd);
		free(tmp);
		i++;
	}
	if ((ft_strlen(tmp) != infs->map.width - 1) || (check_wall(tmp) != infs->map.width - 1))
		infs->map.valid = 0;
	infs->map.height = i;
}

int	map_to_array(int fd, t_info *infs)
{
	infs->map.map = malloc((infs->map.height + 1) * sizeof(char *));
	if (!(infs->map.map))
		return (0);
	int i = 0;
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
	int	i = 0;
	int	j = 0;
	int	c = 0;
	int	e = 0;
	int	p = 0;

	while (i < infs->map.height)
	{
		j = 0;
		while (j < infs->map.width)
		{
			if (infs->map.map[i][j] == 'C')
				c++;
			if (infs->map.map[i][j] == 'E')
				e++;
			if (infs->map.map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
		infs->map.valid = 0;
}
