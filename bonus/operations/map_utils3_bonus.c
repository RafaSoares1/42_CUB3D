/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:07:58 by jomirand          #+#    #+#             */
/*   Updated: 2023/10/16 17:10:28 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_closed_map(t_data *d)
{
	int	y;
	int	x;
	int	size;

	y = 1;
	while (y < d->count_lines - 1)
	{
		x = 0;
		size = (int)ft_strlen(d->map_utils->map[y]);
		while (x < size)
		{
			if (d->map_utils->map[y][x] != '1'
				&& d->map_utils->map[y][x] != '#')
			{
				if (check_around(d, y, x, size))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_around(t_data *d, int y, int x, int size)
{
	if (x == 0 || y == 0 || x == size || y == d->count_lines)
		return (1);
	if (d->map_utils->map[y][x - 1] == '#' || d->map_utils->map[y][x + 1] == '#'
		|| (d->map_utils->map[y - 1][x] == '#'
		|| d->map_utils->map[y + 1][x] == '#'))
		return (1);
	return (0);
}
