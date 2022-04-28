/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:03:35 by ychair            #+#    #+#             */
/*   Updated: 2022/04/28 08:51:22 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int ac, char **av)
{
	char **map;
	int i;
	t_map	*maprule;

	if( ac != 2)
		return (0);
	linemap(av[1],&maprule);
	map = (char **)malloc(sizeof(char*) * maprule->line + 1);
	map = puttab(av[1],map);



	i = 0;
	while (i < maprule->line)
		free(map[i++]);
	free(map);
	return (0);
}
