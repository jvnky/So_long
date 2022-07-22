/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:03:35 by ychair            #+#    #+#             */
/*   Updated: 2022/07/22 05:37:04 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	read/open
*/
void	initstruch(t_map *maprule)
{
	maprule->wall = '1';
	maprule->charac = 'P';
	maprule->col = 'C';
	maprule->grass = '0';
	maprule->exit = 'E';
	maprule->player = 0;
}

void	errorall(void)
{
	write(1, "ERROR\n", 6);
	write(1, "Pointeur NULL\n", 14);
	exit(0);
}

void	freeall(t_map *maprule, char **map)
{
	int	i;

	i = 0;
	while (i < maprule->line)
		free(map[i++]);
	free(map);
	free(maprule->test);
	free(maprule);
}

int	main(int ac, char **av)
{
	char	**map;
	t_map	*maprule;

	maprule = (t_map *)malloc(sizeof(t_map));
	maprule->test = (t_img *)malloc(sizeof(t_img));
	initstruch(maprule);
	if (ac != 2)
		write(1, "ERROR\n", 6);
	if (maprule == NULL || maprule->test == NULL)
		errorall();
	linemap(av[1], maprule);
	map = (char **) malloc(sizeof(char *) * maprule->line + 1);
	if (map == NULL)
		errorall();
	map = puttab(av[1], map);
	if (!ft_errormap(map, maprule))
	{
		freeall(maprule, map);
		return (0);
	}
	ft_render(map, maprule);
	mlx_destroy_window(maprule->test->mlx, maprule->test->mlx_win);
	freeall(maprule, map);
	return (0);
}

int	closewin(t_map *maprule)
{
	mlx_destroy_window(maprule->test->mlx, maprule->test->mlx_win);
	exit(0);
	return (0);
}
