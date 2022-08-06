/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:03:35 by ychair            #+#    #+#             */
/*   Updated: 2022/08/06 08:45:24 by ychair           ###   ########.fr       */
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
	exit(0);
}

void	freeall(t_map *maprule)
{
	int	i;

	i = 0;
	while (i < maprule->line)
		free(maprule->map[i++]);
	free(maprule->map);
	free(maprule->test);
	free(maprule);
}

int	main(int ac, char **av)
{
	t_map	*maprule;

	maprule = (t_map *)malloc(sizeof(t_map));
	maprule->test = (t_img *)malloc(sizeof(t_img));
	initstruch(maprule);
	if (ac != 2)
		errorall();
	if (maprule == NULL || maprule->test == NULL)
		errorall();
	linemap(av[1], maprule);
	maprule->map = (char **) malloc(sizeof(char *) * maprule->line + 1);
	if (maprule->map == NULL)
		errorall();
	maprule->map = puttab(av[1], maprule->map, maprule->line);
	if (!ft_errormap(maprule->map, maprule))
	{
		freeall(maprule);
		return (0);
	}
	ft_render(maprule->map, maprule);
	closewin(maprule);
	return (0);
}

int	closewin(t_map *maprule)
{
	mlx_destroy_window(maprule->test->mlx, maprule->test->mlx_win);
	mlx_destroy_display(maprule->test->mlx);
	free(maprule->test->mlx);
	freeall(maprule);
	exit(0);
	return (0);
}
