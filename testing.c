#include "so_long.h"
void	xpm_to_img(t_info *infos)
{
	int	height;
	int	width;

	infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/pac_man_0.xpm", &width, &height);
	infos->floor = mlx_xpm_file_to_image(infos->mlx, "./assets/floor.xpm", &width, &height);
	infos->wall = mlx_xpm_file_to_image(infos->mlx, "./assets/wall.xpm", &width, &height);
	infos->collect = mlx_xpm_file_to_image(infos->mlx, "./assets/coin.xpm", &width, &height);
	infos->door = mlx_xpm_file_to_image(infos->mlx, "./assets/door.xpm", &width, &height);
	infos->door_op = mlx_xpm_file_to_image(infos->mlx, "./assets/doorop.xpm", &width, &height);
}
int	move(int key, t_info *infos)
{
	printf("%d\n", infos->collected);
	if (key == 2 || key == 1 || key == 13 || key == 0)
		animation_manage(infos);
	if (key == 2 && infos->map.map[infos->hero.y / 32][infos->hero.x / 32 + 1] != '1')
		put_img_right(infos, 0);
	if (key == 0 && infos->map.map[infos->hero.y / 32][infos->hero.x / 32 - 1] != '1')
		put_img_left(infos, 0);
	if (key == 1 && infos->map.map[infos->hero.y / 32 + 1][infos->hero.x / 32] != '1')
		put_img_bottom(infos, 0);
	if (key == 13 && infos->map.map[infos->hero.y / 32 - 1][infos->hero.x / 32] != '1')
		put_img_top(infos, 0);
	if (key == 53)
	{
		mlx_destroy_window(infos->mlx, infos->win);
		exit (0);
	}
	return (0);
}

void	draw_map(t_info *ifs)
{
	int i = -1;
	int j = 0;

	while (++i < ifs->map.height)
	{
		j = -1;
		while (++j < ifs->map.width)
		{
			if (ifs->map.map[i][j] == '1')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->wall, j*32, i*32);
			if (ifs->map.map[i][j] == '0')
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->floor, j*32, i*32);
			if (ifs->map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->collect, j*32, i*32);
				ifs->collectible++;
			}
			if (ifs->map.map[i][j] == 'E')
			{
				ifs->door_x = j*32;
				ifs->door_y = i*32;
				mlx_put_image_to_window(ifs->mlx, ifs->win, ifs->door, j*32, i*32);
			}
		}
	}
}

int	replay(t_info *info)
{
	static size_t i = 0;
	if (info->collected == info->collectible)
		mlx_put_image_to_window(info->mlx, info->win, info->door_op, info->door_x, info->door_y);
	if (info->collected == info->collectible && info->hero.x == info->door_x && info->hero.y == info->door_y)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit (0);
	}
	if (i == 1500)
	{
		info->hero.anime += 1;
		if (info->hero.anime == 5)
			info->hero.anime = 0;
		if (info->hero.pos == 'r')
			put_img_right(info, 1);
		if (info->hero.pos == 'l')
			put_img_left(info, 1);
		if (info->hero.pos == 't')
			put_img_top(info, 1);
		if (info->hero.pos == 'b')
			put_img_bottom(info, 1);
		i = 0;
	}
	i++;
	return (0);
}

void	get_player_pos(t_info *infos)
{
	int i = 0;
	int j = 0;

	while (i < infos->map.height)
	{
		j = 0;
		while (j < infos->map.width)
		{
			if (infos->map.map[i][j] == 'P')
			{
				infos->hero.x = j * 32;
				infos->hero.y = i * 32;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	infos;
	int		fd;

	if (argc != 2)
		return (0);
	infos.mlx = mlx_init();
	infos.hero.pos = 'r';
	infos.hero.anime = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		exit(0);
	get_map(&infos, fd);
	if (!infos.map.valid)
		return (0);
	close(fd);
	xpm_to_img(&infos);
	infos.win = mlx_new_window(infos.mlx, (infos.map.width - 1) * 32, infos.map.height * 32, "Hello");
	fd = open(argv[1], O_RDONLY);
	map_to_array(fd, &infos);
	close(fd);
	check_map(&infos);
	if (!infos.map.valid)
		return (0);
	get_player_pos(&infos);
	draw_map(&infos);
	mlx_hook(infos.win, 2, 0, move, &infos);
	mlx_loop_hook(infos.mlx, replay, &infos);
	mlx_loop(infos.mlx);
}
