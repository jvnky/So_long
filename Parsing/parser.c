/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:48:38 by ychair            #+#    #+#             */
/*   Updated: 2022/05/01 05:20:04 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**puttab(char *av, char **map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		//printf("%s\n", map[i]);
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
	while (get_next_line(fd, &line))
	{
		maprule->column = ft_strlen(line);
		free(line);
		i++;
	}
	free(line);
	maprule->line = i;
	close(fd);
	return (1);
}

int	verifmap(char **map, t_map *maprule)
{
	int	i;
	int	j;
	int	tab[255];

	i = 0;
	while (i < maprule->line)
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == maprule->line - 1) && map[i][j] != '1')
				return (0);
			if (map[i][j] == 'E')
				tab['e'] = 1;
			if (map[i][j] == 'P')
				tab['p'] = 1;
			if (map[i][j] == 'C')
				tab['c'] = 1;
			j++;
		}
		i++;
	}
	if (tab['e'] != 1 || tab['p'] != 1 || tab['c'] != 1)
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
