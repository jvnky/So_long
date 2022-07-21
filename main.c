/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:03:35 by ychair            #+#    #+#             */
/*   Updated: 2022/07/21 03:24:08 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int ac, char **av)
{
	char **map;
	int		i;
	t_map	*maprule;

	maprule= (t_map *)malloc(sizeof(t_map));
	maprule->test= (t_img *)malloc(sizeof(t_img));
	if( ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	linemap(av[1],maprule);
	map = (char **)malloc(sizeof(char*) * maprule->line + 1);
	map = puttab(av[1],map);
	if(!ft_errormap(map, maprule))
		return (0);
	ft_render(map,maprule);
	i = 0;
	while (i < maprule->line)
		free(map[i++]);
	free(map);
	// free(maprule->test);
	// free(maprule);
	return (0);
}
