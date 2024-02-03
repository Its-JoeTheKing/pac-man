#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef	struct s_point
{
	int		x;
	int		y;
}	t_point;

void	aff_map(char **map, t_point size)
{
	int	i_row;
	int	i_dice;

	i_row = -1;
	while (++i_row < size.y)
	{
		i_dice = -1;
		while (++i_dice < size.x)
			printf ("%c ", map[i_row][i_dice]);
		printf("\n");
	}
}

int	check_0(char **map, t_point *size)
{
	int	i_row;
	int	i_dice;

	i_row = -1;
	while (++i_row < size->y)
	{
		i_dice = -1;
		while (++i_dice < size->x)
			if (map[i_row][i_dice] == '0')
				return (1);
	}
	return (0);
}

void	init_val(char **map, t_point *player, t_point *size, int val)
{
	int	x;
	int	y;

	x = player->x;
	y = player->y;
	if (x + 1 < size->x && map[y][x + 1] == '0')
		map[y][x + 1] = val + 48;
	if (x - 1 >= 0 && map[y][x - 1] == '0')
		map[y][x - 1] = val + 48;
	if (y + 1 < size->y && map[y + 1][x] == '0')
		map[y + 1][x] = val + 48;
	if (y - 1 >= 0 && map[y - 1][x] == '0')
		map[y - 1][x] = val + 48;
	if (x + 1 < size->x && y + 1 < size->y && map[y + 1][x + 1] == '0')
		map[y + 1][x + 1] = val + 48;
	if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1] == '0')
		map[y - 1][x - 1] = val + 48;
	if (x + 1 < size->x && y - 1 >= 0 && map[y - 1][x + 1] == '0')
		map[y - 1][x + 1] = val + 48;
	if (x - 1 >= 0 && y + 1 < size->y && map[y + 1][x - 1] == '0')
		map[y + 1][x - 1] = val + 48;
}

void	init_val_2(char **map, t_point *size, int val)
{
	int		i_row;
	int		i_dice;
	t_point	*player;

	player = (t_point *)malloc(sizeof(t_point));
	i_row = -1;
	while (++i_row < size->y)
	{
		i_dice = -1;
		while (++i_dice < size->x)
		{
			if (map[i_row][i_dice] == val + 48 - 1)
			{
				player->x = i_dice;
				player->y = i_row;
				init_val (map, player, size, val);
			}
		}
	}
}
void	floodmap(char **map, t_point *player, t_point *size)
{
	int	val;

	val = 1;
	init_val(map, player, size, val++);
	while (check_0(map, size))
		init_val_2(map, size ,val++);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
int	main(void)
{
	int	val;

	val = 1;
	char	**map;
	map = (char **)malloc(sizeof(char *) * 8);
	for (int i = 0; i < 8; i++)
		map[i] = (char *)malloc(sizeof(char) * 10);
	map[0] = ft_strdup("000W00000");
	map[1] = ft_strdup("000W00E00");
	map[2] = ft_strdup("000W00000");
	map[3] = ft_strdup("0P0W00000");
	map[4] = ft_strdup("WW0W00000");
	map[5] = ft_strdup("000W00000");
	map[6] = ft_strdup("000000000");
	map[7] = ft_strdup("000000000");
	t_point	player;
	t_point	size;
	size.y = 8;
	size.x = 10;
	player.y = 3;
	player.x = 1;
	floodmap(map, &player, &size);
	aff_map(map, size);
}