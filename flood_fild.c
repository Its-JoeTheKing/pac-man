#include <stdio.h>

void	aff_map(char map[8][8])
{
	int	i_row;
	int	i_dice;

	i_row = -1;
	while (++i_row < 8)
	{
		i_dice = -1;
		while (++i_dice < 8)
			printf ("%c ", map[i_row][i_dice]);
		printf("\n");
	}
}

int	check_0(char map[8][8])
{
	int	i_row;
	int	i_dice;

	i_row = -1;
	while (++i_row < 8)
	{
		i_dice = -1;
		while (++i_dice < 8)
			if (map[i_row][i_dice] == '0')
				return (1);
	}
	return (0);
}

void	init_val(char map[8][8], int x, int y, int val)
{
	if ((x + 1 >= 0 && x + 1 < 8) && (y >= 0 && y < 8) && map[x + 1][y] == '0')
		map[x + 1][y] = val + 48;
	if ((x - 1 >= 0 && x - 1 < 8) && (y >= 0 && y < 8) && map[x - 1][y] == '0')
		map[x - 1][y] = val + 48;
	if ((x >= 0 && x < 8) && (y + 1 >= 0 && y + 1 < 8) && map[x][y + 1] == '0')
		map[x][y + 1] = val + 48;
	if ((x >= 0 && x < 8) && (y - 1 >= 0 && y - 1 < 8) && map[x][y - 1] == '0')
		map[x][y - 1] = val + 48;
	if ((x + 1 >= 0 && x + 1 < 8) && (y + 1 >= 0 && y + 1 < 8)
		&& map[x + 1][y + 1] == '0')
		map[x + 1][y + 1] = val + 48;
	if ((x + 1 >= 0 && x + 1 < 8) && (y - 1 >= 0 && y - 1 < 8)
		&& map[x + 1][y - 1] == '0')
		map[x + 1][y - 1] = val + 48;
	if ((x - 1 >= 0 && x - 1 < 8) && (y + 1 >= 0 && y + 1 < 8)
		&& map[x - 1][y + 1] == '0')
		map[x - 1][y + 1] = val + 48;
	if ((x - 1 >= 0 && x - 1 < 8) && (y - 1 >= 0 && y - 1 < 8)
		&& map[x - 1][y - 1] == '0')
		map[x - 1][y - 1] = val + 48;
}

void	init_val_2(char map[8][8], int val)
{
	int		i_row;
	int		i_dice;
	char	val_char;

	i_row = -1;
	val_char = val + 48;
	while (++i_row < 8)
	{
		i_dice = -1;
		while (++i_dice < 8)
		{
			if (map[i_row][i_dice] == val_char - 1)
				init_val (map, i_row, i_dice, val);
		}
	}
}

int	main(void)
{
	int	val;

	val = 1;
	char	map[8][8] = {
	{'0', '0', '0', 'W', '0', '0', '0', '0'},
	{'0', '0', '0', 'W', '0', '0', 'E', '0'},
	{'0', '0', '0', 'W', '0', '0', '0', '0'},
	{'0', 'P', '0', 'W', '0', '0', '0', '0'},
	{'W', 'W', '0', 'W', '0', '0', '0', '0'},
	{'0', '0', '0', 'W', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0'}};
	init_val(map, 3, 1 , val++);
	while (check_0(map))
		init_val_2(map, val++);

	aff_map(map);
}