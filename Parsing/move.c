/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:01:34 by ychair            #+#    #+#             */
/*   Updated: 2022/07/22 02:58:33 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_map *maprule, int i, int j)
{
	char	tmp;

	if (maprule->map[i - 1][j] != maprule->exit)
	{
		if (maprule->map[i - 1][j] == maprule->col)
		{
			maprule->map[i - 1][j] = maprule->grass;
			maprule->collect++;
		}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i - 1][j];
		maprule->map[i - 1][j] = tmp;
		maprule->c = 'Q';
		maprule->move++;
		printmove(maprule);
	}
	else
	{
		if (maprule->collect == maprule->maxcollect)
		{
			write(1, "YOU WIN\n", 8);
			exit(0);
		}
	}
}

void	down(t_map *maprule, int i, int j)
{
	char	tmp;

	if (maprule->map[i + 1][j] != maprule->exit)
	{
		if (maprule->map[i + 1][j] == maprule->col)
		{
			maprule->map[i + 1][j] = maprule->grass;
			maprule->collect++;
		}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i + 1][j];
		maprule->map[i + 1][j] = tmp;
		maprule->c = 'Q';
		maprule->move++;
		printmove(maprule);
	}
	else
	{
		if (maprule->collect == maprule->maxcollect)
		{
			write(1, "YOU WIN\n", 8);
			exit(0);
		}
	}
}

void	left(t_map *maprule, int i, int j)
{
	char	tmp;

	if (maprule->map[i][j - 1] != maprule->exit)
	{
		if (maprule->map[i][j - 1] == maprule->col)
		{
			maprule->map[i][j - 1] = maprule->grass;
			maprule->collect++;
		}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i][j - 1];
		maprule->map[i][j - 1] = tmp;
		maprule->c = 'Q';
		maprule->move++;
		printmove(maprule);
	}
	else
	{
		if (maprule->collect == maprule->maxcollect)
		{
			write(1, "YOU WIN\n", 8);
			exit(0);
		}
	}
}

void	right(t_map *maprule, int i, int j)
{
	char	tmp;

	if (maprule->map[i][j + 1] != maprule->exit)
	{
		if (maprule->map[i][j + 1] == maprule->col)
		{
			maprule->map[i][j + 1] = maprule->grass;
			maprule->collect++;
		}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i][j + 1];
		maprule->map[i][j + 1] = tmp;
		maprule->c = 'Q';
		maprule->move++;
		printmove(maprule);
	}
	else
	{
		if (maprule->collect == maprule->maxcollect)
		{
			write(1, "YOU WIN\n", 8);
			exit(0);
		}
	}
}

void	printmove(t_map *maprule)
{
	char	*tmp;

	tmp = ft_itoa(maprule->move);
	write(1, "move: ", 6);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	free(tmp);
}
