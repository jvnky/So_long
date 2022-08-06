/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:48:38 by ychair            #+#    #+#             */
/*   Updated: 2022/08/06 09:01:21 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**puttab(char *av, char **map, int line)
{
	int		fd;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	i = 0;
	map[i] = get_next_line(fd);
	while (i++ < line)
		map[i] = get_next_line(fd);
	return (map);
}

int	linemap(char *av, t_map *maprule)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		write(1, "Invalid fd\n", 11);
		exit (0);
	}
	line = get_next_line(fd);
	maprule->column = ft_strlen1(line);
	while (line)
	{
		if (maprule->column != ft_strlen1(line))
			errorall();
		if (line)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	maprule->line = i;
	close(fd);
	return (1);
}

int	toomuchline(char c, t_map *maprule, int i, int tab[])
{
	if (c != maprule->exit && c != maprule->charac && c != maprule->col
		&& c != maprule->grass && c != maprule->wall)
		return (0);
	if ((i == 0 || i == maprule->line - 1) && c != maprule->wall)
		return (0);
	if (c == maprule->charac)
		tab['p'] = maprule->player++;
	if (c == maprule->exit)
		tab['e'] = 1;
	if (c == maprule->col)
	{
		tab['c'] = 1;
		maprule->maxcollect++;
	}
	return (1);
}

int	verifmap(char **map, t_map *maprule)
{
	int	i;
	int	j;
	int	tab[255];

	maprule->maxcollect = 0;
	i = 0;
	while (i < maprule->line)
	{
		j = 0;
		while (j < maprule->column)
		{
			if (!toomuchline(map[i][j], maprule, i, tab))
				return (0);
			if ((j == 0 || j == maprule->column) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (tab['e'] != 1 || maprule->player != 1 || tab['c'] != 1)
		return (0);
	return (1);
}

int	ft_errormap(char **map, t_map *maprule)
{
	int	i;

	i = 0;
	if (!verifmap(map, maprule))
	{
		write(1, "Error\n", 6);
		write(1, "Mauvaise Map\n", 13);
		return (0);
	}
	while (i < maprule->line)
	{
		if (i > 0 && ft_strlen1(map[i]) != ft_strlen1(map[i - 1]))
		{
			errorall();
			return (0);
		}
		i++;
	}
	return (1);
}
