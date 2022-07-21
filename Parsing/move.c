/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:01:34 by ychair            #+#    #+#             */
/*   Updated: 2022/07/21 04:14:54 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_map *maprule,int i , int j)
{
	char tmp;
	if(maprule->map[i-1][j] != 'E')
	{
		if(maprule->map[i-1][j] == 'C')
		{
			maprule->map[i-1][j] = '0';
			maprule->collect++;
		}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i-1][j];
		maprule->map[i-1][j] = tmp;
		maprule->c = 'Q';
		maprule->move++;
	}
	else
		{
			if(maprule->collect == maprule->maxCollect)
				exit(0); // a changer
		}
}

void	down(t_map *maprule,int i , int j)
{
	char tmp;

	if(maprule->map[i+1][j] == 'C')
				{
					maprule->map[i+1][j] = '0';
					maprule->collect++;
				}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i+1][j];
		maprule->map[i+1][j] = tmp;
		maprule->c = 'Q';
		maprule->move++;

}
void	left(t_map *maprule,int i , int j)
{
	char tmp;

			if(maprule->map[i][j-1] == 'C')
				{
					maprule->map[i][j-1] = '0';
					maprule->collect++;
				}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i][j-1];
		maprule->map[i][j-1] = tmp;
		maprule->c = 'Q';
		maprule->move++;
		}

void	right(t_map *maprule,int i , int j)
{
	char tmp;

			if(maprule->map[i][j+1] == 'C')
				{
					maprule->map[i][j+1] = '0';
					maprule->collect++;
				}
		tmp = maprule->map[i][j];
		maprule->map[i][j] = maprule->map[i][j+1];
		maprule->map[i][j+1] = tmp;
		maprule->c = 'Q';
		maprule->move++;
}
