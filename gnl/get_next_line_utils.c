/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:45:30 by ychair            #+#    #+#             */
/*   Updated: 2022/08/05 11:53:08 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 3));
	if (dest == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char const s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen(s1) + 2;
	str = (char *)malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
			str[j++] = s1[i++];
	str[j++] = s2;
	str[j] = '\0';
	free(s1);
	return (str);
}

t_gnl	*ft_lstnew(int content)
{
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (new == NULL)
		return (NULL);
	new->fd = content;
	new->next = NULL;
	new->fin = 1;
	new->buffer = NULL;
	new->ligne = NULL;
	new->index = 0;
	return (new);
}

void	ft_lstadd_back(t_gnl **alst, t_gnl *new)
{
	t_gnl	*tmp;

	if (!new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = 0;
	}
	else
		*alst = new;
}
