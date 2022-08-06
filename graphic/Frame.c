/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 03:06:48 by ychair            #+#    #+#             */
/*   Updated: 2022/08/06 09:02:08 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	changemap(t_map *maprule, int i, int j)
{
	if (maprule->map[i][j] == maprule->charac && maprule->c == 'D')
		if (j < maprule->column && maprule->map[i][j + 1] != maprule->wall)
			right(maprule, i, j);
	if (maprule->map[i][j] == maprule->charac && maprule->c == 'G')
		if (j > 0 && maprule->map[i][j - 1] != maprule->wall)
			left(maprule, i, j);
	if (maprule->map[i][j] == maprule->charac && maprule->c == 'H')
		if (i > 0 && maprule->map[i - 1][j] != maprule->wall)
			up(maprule, i, j);
	if (i < maprule->line && maprule->map[i][j] == maprule->charac
		&& maprule->c == 'B')
		if (maprule->map[i + 1][j] != maprule->wall && i < maprule->line)
			down(maprule, i, j);
}

int	frame_map(t_map *maprule, char c)
{
	int		i;
	int		j;

	i = 0;
	maprule->c = c;
	while (i < maprule->line)
	{
		j = 0;
		while (j < maprule->column)
		{
			changemap(maprule, i, j);
			j++;
		}
		i++;
	}
	render_frame(maprule);
	return (0);
}

void	render_frame(t_map *maprule)
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

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
