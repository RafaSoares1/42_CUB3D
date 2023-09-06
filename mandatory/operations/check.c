/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:16:24 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/06 15:16:24 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_letters(t_data *d)
{
	int		f;
	char	c;

	f = 0;
	d->x = 0;
	d->y = 0;
	while (d->map_utils->map[d->x])
	{
		d->y = 0;
		while (d->map_utils->map[d->x][d->y])
		{
			c = d->map_utils->map[d->x][d->y];
			if (c == '1' || c == '0' || c == '#')
					d->y++;
			else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && f == 0)
			{
				d->map_utils->player_pos = c;
				f = 1;
				d->y++;
			}
			else
				handle_invalid_input(d);
		}
		d->x++;
	}
}

void	handle_invalid_input(t_data *d)
{
	ft_free_game(d);
	finish_error("Error: invalid elements in the map!\n", 2);
}

void	check_flood_fill(t_data *d);