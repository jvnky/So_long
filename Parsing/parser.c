/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:48:38 by ychair            #+#    #+#             */
/*   Updated: 2022/04/23 22:16:05 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**puttab(char *av,char **map)
{
	int fd;


	fd = open(av,O_RDONLY);

	while(get_next_line(fd,map))

	printf("%s\n",map[1]);
	return(map);
}
