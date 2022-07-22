/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:17:50 by ychair            #+#    #+#             */
/*   Updated: 2022/07/22 06:36:29 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path(char c, t_map *img)
{
	if (c == img->wall)
		img->test->relative_path
			= "./graphic/image/sprites/tilesets/floors/arbre.xpm";
	if (c == img->grass)
		img->test->relative_path
			= "./graphic/image/sprites/tilesets/nothing.xpm";
	if (c == img->col)
		img->test->relative_path
			= "./graphic/image/sprites/tilesets/frozinha.xpm";
	if (c == img->exit)
		img->test->relative_path
			= "./graphic/image/sprites/tilesets/floors/end.xpm";
	if (c == img->charac)
		img->test->relative_path
			= "./graphic/image/sprites/tilesets/char/nuvem.xpm";
	img->test->img = mlx_xpm_file_to_image(img->test->mlx, img->test
			->relative_path, &img->test->img_width, &img->test->img_height);
	if (img->test->img == NULL)
		errorall();
	mlx_put_image_to_window(img->test->mlx, img->test->mlx_win,
		img->test->img, img->test->x, img->test->y);
	return (1);
}

int	key_hook(int keycode, t_map *maprule)
{
	if (keycode == ESC)
		closewin(maprule);
	if (keycode == KEY_UP || keycode == ARROW_UP)
		frame_map(maprule, 'H');
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		frame_map(maprule, 'B');
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
		frame_map(maprule, 'G');
	if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
		frame_map(maprule, 'D');
	return (0);
}

void	printmap(t_map *maprule)
{
	int	i;
	int	j;

	i = 0;
	maprule->test->y = 0;
	while (i < maprule->line)
	{
		j = 0;
		maprule->test->x = 0;
		while (j < maprule->column)
		{
			path(maprule->map[i][j], maprule);
			j++;
			maprule->test->x += maprule->test->img_height;
		}
		i++;
		maprule->test->y += maprule->test->img_width;
	}
}

int	ft_render(char **map, t_map	*maprule)
{
	maprule->map = map;
	maprule->move = 0;
	maprule->collect = 0;
	maprule->test->mlx = mlx_init();
	if (maprule->test->mlx == NULL)
		errorall();
	maprule->test->mlx_win = mlx_new_window(maprule->test->mlx, maprule
			->column * 64, maprule->line * 64, "So_long");
	if (maprule->test->mlx_win == NULL)
		errorall();
	printmap(maprule);
	mlx_hook(maprule->test->mlx_win, 17, (1L << 17), closewin, maprule);
	mlx_hook(maprule->test->mlx_win, 2, (1L << 0), key_hook, maprule);
	mlx_loop(maprule->test->mlx);
	return (0);
}
