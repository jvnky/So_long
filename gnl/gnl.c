/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:43:51 by ychair            #+#    #+#             */
/*   Updated: 2022/08/06 07:03:59 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fill_buffer(int fd, char *buffer)
{
	ssize_t	nb;

	if (!buffer)
		return (-1);
	nb = read(fd, buffer, BUFFER_SIZE);
	if (nb < 1)
		return (nb);
	buffer[nb] = '\0';
	return (nb);
}

char	*stop_condition(ssize_t nb, char *valid_line)
{
	if (nb < 0)
	{
		if (valid_line)
			free(valid_line);
		return (NULL);
	}
	return (valid_line);
}

char	*extract_str(char *buffer, ssize_t *new_line)
{
	size_t	i;
	char	*extracted;

	i = 0;
	if (buffer)
	{
		while (*(buffer + (i + 1)) && *(buffer + i) != '\n')
				i++;
		if (*(buffer + i) == '\n')
				*new_line = TRUE;
		extracted = ft_strndup(buffer, i);
		if (!extracted)
			return (NULL);
		ft_memmove(buffer, (buffer + (i + 1)), ft_strlen((buffer + i)));
		return (extracted);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*valid_line;
	char		*temp;
	ssize_t		nb;
	ssize_t		new_line;

	nb = 2;
	new_line = FALSE;
	valid_line = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	while (!new_line)
	{
		if (!*buffer)
			nb = fill_buffer(fd, buffer);
		if (nb < 1)
			return (stop_condition(nb, valid_line));
		temp = extract_str(buffer, &new_line);
		valid_line = ft_strjoin_and_free(valid_line, temp);
		if (!valid_line)
			return (stop_condition(-1, valid_line));
	}
	return (stop_condition(nb, valid_line));
}
