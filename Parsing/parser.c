/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:48:38 by ychair            #+#    #+#             */
/*   Updated: 2022/08/05 04:10:04 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**puttab(char *av, char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	free(line);
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
	while (get_next_line(fd, &line))
	{
		maprule->column = ft_strlen(line);
		if (line)
			free(line);
		i++;
	}
	free(line);
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

	i = 0;
	maprule->maxcollect = 0;
	while (i < maprule->line)
	{
		j = 0;
		while (j < maprule->column)
		{
			if (!toomuchline(map[i][j], maprule, i, tab))
				return (0);
			if ((j == 0 || j == maprule->column - 1) && map[i][j] != '1')
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
		if (i > 0 && ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (0);
		i++;
	}
	return (1);
}
