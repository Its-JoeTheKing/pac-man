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
	if (map[y][x] == 'E')
		printf("%d\n", val - 1);
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

void	get_road(char **map, t_point size, t_point pos, int val)
{
	t_point	*road;
	int		i;

	i = 0;
	road = (t_point *)malloc(sizeof(t_point) * (val + 1));
	road[i] = pos;
	while (val > 1)
	{
		road[i] = get_next_pos(map, size, road[i - 1], val - 1);
		val--;
		i++;
	}
	i = 0;
	while (road[i].x)
	{
		printf("%d %d\n", road[i].x, road[i].y);
		i++;
	}
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
	t_point enemy;
	enemy.y = 1;
	enemy.x = 6;
	t_point poo =  get_next_pos(map, size, enemy, '7');
	printf("%d %d\n", poo.x, poo.y);
	aff_map(map, size);
}
