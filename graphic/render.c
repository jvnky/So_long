/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:17:50 by ychair            #+#    #+#             */
/*   Updated: 2022/07/13 04:31:36 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// void ff(t_map *maprule);

void	path(char c,t_map *img)
{
	if(c == '1')
		img->test->relative_path = "./graphic/image/sprites/tilesets/floors/wooden.xpm";
	if(c == '0')
		img->test->relative_path = "./graphic/image/sprites/tilesets/grass.xpm";
	if(c == 'C')
		img->test->relative_path = "./graphic/image/sprites/tilesets/watermelon.xpm";
	if(c == 'E')
		img->test->relative_path = "./graphic/image/sprites/tilesets/floors/arrow_1.xpm";
	if(c == 'P')
		img->test->relative_path = "./graphic/image/sprites/tilesets/char/priest1.xpm";
	img->test->img = mlx_xpm_file_to_image(img->test->mlx,img->test->relative_path,&img->test->img_width,&img->test->img_height);
	mlx_put_image_to_window(img->test->mlx, img->test->mlx_win, img->test->img, img->test->x, img->test->y);
}

int	ft_refresh(t_map *maprule)
{
	//img->mlx = mlx_init();
	//img->mlx_win = mlx_new_window(img->mlx, 34*16,6*16, "So_long");
	int i;
	int j;
	char tmp;

	i = 0;
	// puts("zsdwfwef");
	maprule->test->y = 0;
	while(i < maprule->line)
	{
		printf("%d\n",i);
		// puts("qqqqq");
		j = 0;
		maprule->test->x = 0;
		while(j < maprule->column)
			{
				//printf("%d\n",j);
				// puts("ffff");
				if(maprule->map[i][j] == 'P' && maprule->c == 'D')
				{
					tmp = maprule->map[i][j];
					maprule->map[i][j] = maprule->map[i+1][j];
					maprule->map[i+1][j] = tmp;
				puts("xxxx");
				}
				path(maprule->map[i][j],maprule);
				// puts("asd");
				j++;
				maprule->test->x+=maprule->test->img_height;
			}
		i++;
		maprule->test->y+=maprule->test->img_width;
	}
	//maprule->test->img = mlx_xpm_file_to_image(maprule->test->mlx,maprule->test->relative_path,&maprule->test->img_width,&maprule->test->img_height);
	//mlx_put_image_to_window(maprule->test->mlx, maprule->test->mlx_win, maprule->test->img, maprule->test->x, maprule->test->y);
	// ff(maprule);
	return (0);
}

int	key_hook(int keycode, t_map *maprule,t_img *img)
{
	//printf(" %d\n",keycode);
	if(keycode == KEY_UP || keycode == ARROW_UP)
		{	printf("UP\n");
		maprule->c = 'H';
	}
	if(keycode == KEY_DOWN || keycode == ARROW_DOWN)
		{	printf("down\n");
		maprule->c = 'B';
	}
	if(keycode == KEY_LEFT || keycode == ARROW_LEFT)
	{	printf("left\n");
		maprule->c = 'G';
	}
	if(keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
	{	printf("right\n");
		maprule->c = 'D';
	}
	
	return (0);
}

int ft_render(char **map,t_map	*maprule)
{
	int i;
	int j;
	maprule->map = map;
	 maprule->test->mlx = mlx_init();
	maprule->test->mlx_win = mlx_new_window(maprule->test->mlx, maprule->column*16,maprule->line*16, "So_long");
//
	i = 0;
	maprule->test->y = 0;
	while(i < maprule->line)
	{
		j = 0;
		maprule->test->x = 0;
		while(j < maprule->column)
			{
				path(maprule->map[i][j],maprule);
				j++;
				maprule->test->x+=maprule->test->img_height;
			}
		i++;
		maprule->test->y+=maprule->test->img_width;
	}
	mlx_key_hook(maprule->test->mlx_win, key_hook, &maprule);
	//mlx_loop_hook(maprule->test->mlx, ft_refresh, maprule);
	mlx_loop(maprule->test->mlx);
	return(1);
}
// void ff(t_map *maprule)
// {
// 	int j;
// 	int i;

// 	i = 0;
// 	j = 0;
// 	maprule->test->y = 0;
// 	while(i < maprule->line)
// 	{
// 		j = 0;
// 		maprule->test->x = 0;
// 		while(j < maprule->column)
// 			{
// 				path(maprule->map[i][j],maprule);
// 				j++;
// 				maprule->test->x+=maprule->test->img_height;
// 			}
// 		i++;
// 		maprule->test->y+=maprule->test->img_width;
// 	}
// }
