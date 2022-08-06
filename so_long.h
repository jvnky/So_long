/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:23:30 by ychair            #+#    #+#             */
/*   Updated: 2022/08/06 09:17:11 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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
}	t_img;

typedef struct s_map
{
	char	c;
	int		line;
	int		column;
	int		move;
	int		collect;
	int		maxcollect;
	char	**map;
	char	wall;
	char	charac;
	char	col;
	char	grass;
	char	exit;
	int		player;
	t_img	*test;
}	t_map;

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

int		frame_map(t_map *maprule, char c);
void	render_frame(t_map *maprule);
char	**puttab(char *av, char **map, int line);
int		linemap(char *av, t_map *maprule);
int		verifmap(char **map, t_map *maprule);
int		ft_errormap(char **map, t_map *maprule);
int		ft_render(char **map, t_map	*maprule);
int		path(char c, t_map *img);
void	up(t_map *maprule, int i, int j);
void	down(t_map *maprule, int i, int j);
void	left(t_map *maprule, int i, int j);
void	right(t_map *maprule, int i, int j);
void	errorall(void);
int		ft_putstr(char *s);
char	*ft_itoa(int nbr);
void	printmove(t_map *maprule);
int		closewin(t_map *maprule);
int		ft_strlen1(char *str);
int		extension(char *str);
#endif
