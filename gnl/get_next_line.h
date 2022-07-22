/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:45:41 by ychair            #+#    #+#             */
/*   Updated: 2022/07/22 12:46:06 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_gnl
{
	int				fd;
	int				index;
	char			*ligne;
	int				fin;
	char			*buffer;
	int				ret;
	struct s_gnl	*next;
}					t_gnl;

char				*ft_strjoin(char *s1, char const s2);
char				*ft_strdup(const char *src);
int					get_next_line(int fd, char **line);
int					ft_strlen(const char *s);
char				*ft_search(int fd, t_gnl *lst);
int					ft_check(int fd, t_gnl *lst);
t_gnl				*ft_lstnew(int content);
void				ft_lstadd_back(t_gnl **alst, t_gnl *new);

#endif
