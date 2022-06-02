/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:43:51 by ychair            #+#    #+#             */
/*   Updated: 2022/05/01 05:15:06 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			letter;
	char		buff[BUFFER_SIZE + 1];
	static char	*buffline[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || line == NULL || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	if (buffline[fd] == NULL)
		buffline[fd] = ft_strdup("");
	letter = read(fd, buff, BUFFER_SIZE);
	while (letter > 0)
	{
		buff[letter] = '\0';
		tmp = ft_strjoin(buffline[fd], buff);
		free(buffline[fd]);
		buffline[fd] = tmp;
		letter = read(fd, buff, BUFFER_SIZE);
	}
	*line = ft_cpylink(buffline, fd);
	buffline[fd] = ft_strchr(buffline[fd], '\n');
	if (buffline[fd])
		return (1);
	free(tmp);
	return (0);
}

char	*ft_cpylink(char **buffline, int fd)
{
	int		i;
	char	*link;

	i = 0;
	while (buffline[fd][i] && buffline[fd][i] != '\n')
		i++;
	link = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (buffline[fd][i] && buffline[fd][i] != '\n')
	{
		link[i] = buffline[fd][i];
		i++;
	}
	link[i] = '\0';
	return (link);
}
