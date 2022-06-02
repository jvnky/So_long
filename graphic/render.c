/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:17:50 by ychair            #+#    #+#             */
/*   Updated: 2022/05/19 05:36:32 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	path(char c,t_img *img)
{
	// t_player *pos;

	if(c == '1')
		img->relative_path = "./graphic/image/sprites/tilesets/floors/wooden.xpm";
	if(c == '0')
		img->relative_path = "./graphic/image/sprites/tilesets/grass.xpm";
	if(c == 'C')
		img->relative_path = "./graphic/image/sprites/tilesets/watermelon.xpm";
	if(c == 'E')
		img->relative_path = "./graphic/image/sprites/tilesets/floors/arrow_1.xpm";
	if(c == 'P')
	{
		img->relative_path = "./graphic/image/sprites/tilesets/char/priest1.xpm";
		// pos->x = img->x;
		// pos->y = img->y;
	}
	img->img = mlx_xpm_file_to_image(img->mlx,img->relative_path,&img->img_width,&img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x, img->y);
}

int	key_hook(int keycode, t_img *img)
{
	if(keycode == KEY_UP)
		printf("UP\n");
	if(keycode == KEY_DOWN)
		printf("DOWN\n");

	//mlx_loop_hook(img->mlx, render_next_frame, YourStruct);
	return (0);
}



// int	ft_refresh(t_img *img)
// {
// 	img->mlx = mlx_init();
// 	img->mlx_win = mlx_new_window(img->mlx, 34*16,6*16, "So_long");


// }
int ft_render(char **map,t_map	*maprule)
{
	int i;
	int j;
	t_img	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, maprule->column*16,maprule->line*16, "So_long");
	i = 0;
	img.y = 0;
	while(i < maprule->line)
	{
		j = 0;
		img.x = 0;
		while(j < maprule->column)
			{
				path(map[i][j],&img);
				j++;
				img.x+=img.img_height;
			}
		i++;
		img.y+=img.img_width;
	}
		// mlx_key_hook(img.mlx_win, key_hook, &img);
		// mlx_loop_hook(img.mlx, ft_refresh, &img);
		mlx_loop(img.mlx);
	return(1);
}
