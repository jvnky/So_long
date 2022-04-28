/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:48:38 by ychair            #+#    #+#             */
/*   Updated: 2022/04/28 08:50:08 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**puttab(char *av,char **map)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(av,O_RDONLY);
	i = 0;
	while(get_next_line(fd,&line))
	{
		map[i] = ft_strdup(line);
		printf("%s\n",map[i]);
		i++;
		free(line);
	}
	free(line);

	return(map);
}

int	linemap(char *av, t_map **maprule)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open(av,O_RDONLY);
	while(get_next_line(fd,&line))
	{
		(*maprule)->column = ft_strlen(line);
			free(line);
			i++;
	}
	free(line);
	(*maprule)->line = i;
	close(fd);

	return (i);
}
