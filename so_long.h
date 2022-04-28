/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 06:23:30 by ychair            #+#    #+#             */
/*   Updated: 2022/04/28 08:33:38 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_map
{
	int		line;
	int		column;

}	t_map;


char	**puttab(char *av,char **map);
int		linemap(char *av, t_map **maprule);


#endif
