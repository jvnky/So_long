/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:45:41 by ychair            #+#    #+#             */
/*   Updated: 2022/08/06 06:12:32 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 542

# include <stdlib.h>
# include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t size);
char	*stop_condition(ssize_t nb, char *valid_line);
char	*extract_str(char *buffer, ssize_t *new_line);
char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *actual_line, char *temp);
char	*ft_strndup(char *buffer, size_t n);
size_t	ft_strlen(char *str);
ssize_t	fill_buffer(int fd, char *buffer);

#endif
