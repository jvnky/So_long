/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:23:30 by ychair            #+#    #+#             */
/*   Updated: 2022/06/02 06:29:54 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>




typedef struct s_img
{

	void	*img;
	char	*addr;
	char	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
} t_img;

typedef struct s_map
{
	char	c;
	int		line;
	int		column;
	char 	**map;
	t_img	*test;
}	t_map;

typedef struct s_player
{
	int x;
	int y;

} t_player;
enum e_keycode
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	ARROW_UP = 65362,
	ARROW_DOWN = 65364,
	ARROW_LEFT = 65361,
	ARROW_RIGHT =65363,
	RESET = 114,
	ESC = 65307,
};

char	**puttab(char *av,char **map);
int		linemap(char *av, t_map *maprule);
int		verifmap(char **map, t_map *maprule);
int		ft_errormap(char **map, t_map *maprule);
int		ft_render(char **map,t_map	*maprule);
#endif
