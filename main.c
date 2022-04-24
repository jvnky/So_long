/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:03:35 by ychair            #+#    #+#             */
/*   Updated: 2022/04/24 03:05:43 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int ac, char **av)
{
	char *line;
	char **map;

	int fd;
	int i;
	int val;

	i = 0;
	fd = open("map1.ber",O_RDONLY);
	//printf("fd = %d    | av = %s\n",fd,av[1]);

	while(get_next_line(fd,&line))
	{
			free(line);
			i++;
	}
	free(line);
	map = (char **)malloc(sizeof(char*) * i + 1);
	close(fd);
	fd = open(av[1],O_RDONLY);
	i = 0;
	// while(get_next_line(fd,&line))
	// {
	// 	map[i] = ft_strdup(line);
	// 	printf("%s\n",map[i]);
	// 	i++;
	// }
	//map[i] = NULL;

	// while(line)
	// 	free(line);

	free(map);

	return (0);
}
