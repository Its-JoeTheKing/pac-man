#include "../so_long.h"

void	put_img_right(t_info *infos, int isIdle)
{
	infos->hero.posi = 'r';
	if (!isIdle)
	{
		infos->collected += 1 * (infos->map.map[infos->hero.pos.y / 32][(infos->hero.pos.x + 32) / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.x += 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.img)
	{
		mlx_destroy_image(infos->mlx, infos->hero.img);
		infos->hero.img = NULL;
	}
	if (infos->hero.anime == 0)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/right/pac_man_0.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 1)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/right/pac_man_1.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 2)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/right/pac_man_2.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 3)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/right/pac_man_3.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 4)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/right/pac_man_4.xpm", &infos->height, &infos->width);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor, infos->hero.pos.x - (32 * !isIdle), infos->hero.pos.y);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img, infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_left(t_info *infos, int isIdle)
{
	infos->hero.posi = 'l';
	if (!isIdle)
	{
		infos->collected += 1 * (infos->map.map[infos->hero.pos.y / 32][(infos->hero.pos.x - 32) / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.x -= 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.img)
	{
		mlx_destroy_image(infos->mlx, infos->hero.img);
		infos->hero.img = NULL;
	}
	if (infos->hero.anime == 0)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/left/pac_man_0.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 1)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/left/pac_man_1.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 2)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/left/pac_man_2.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 3)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/left/pac_man_3.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 4)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/left/pac_man_4.xpm", &infos->height, &infos->width);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor, infos->hero.pos.x + (32 * !isIdle), infos->hero.pos.y);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img, infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_top(t_info *infos, int isIdle)
{
	infos->hero.posi = 't';
	if (!isIdle)
	{
		infos->collected += 1 * (infos->map.map[(infos->hero.pos.y - 32) / 32][infos->hero.pos.x / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.y -= 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.img)
	{
		mlx_destroy_image(infos->mlx, infos->hero.img);
		infos->hero.img = NULL;
	}
	if (infos->hero.anime == 0)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/top/pac_man_0.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 1)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/top/pac_man_1.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 2)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/top/pac_man_2.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 3)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/top/pac_man_3.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 4)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/top/pac_man_4.xpm", &infos->height, &infos->width);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor, infos->hero.pos.x, infos->hero.pos.y + (32 * !isIdle));
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img, infos->hero.pos.x, infos->hero.pos.y);
}

void	put_img_bottom(t_info *infos, int isIdle)
{
	infos->hero.posi = 'b';
	if (!isIdle)
	{
		infos->collected += 1 * (infos->map.map[(infos->hero.pos.y + 32) / 32][infos->hero.pos.x / 32] == 'C');
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = '0';
		infos->hero.pos.y += 32;
		infos->map.map[infos->hero.pos.y / 32][infos->hero.pos.x / 32] = 'P';
	}
	if (infos->hero.img)
	{
		mlx_destroy_image(infos->mlx, infos->hero.img);
		infos->hero.img = NULL;
	}
	if (infos->hero.anime == 0)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/bottom/pac_man_0.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 1)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/bottom/pac_man_1.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 2)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/bottom/pac_man_2.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 3)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/bottom/pac_man_3.xpm", &infos->height, &infos->width);
	if (infos->hero.anime == 4)
		infos->hero.img = mlx_xpm_file_to_image(infos->mlx, "./assets/pacs/bottom/pac_man_4.xpm", &infos->height, &infos->width);
	mlx_put_image_to_window(infos->mlx, infos->win, infos->floor, infos->hero.pos.x, infos->hero.pos.y - (32 * !isIdle));
	mlx_put_image_to_window(infos->mlx, infos->win, infos->hero.img, infos->hero.pos.x, infos->hero.pos.y);
}
