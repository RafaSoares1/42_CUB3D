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
	d->y = 0;
	while (d->map_utils->map[d->y])
	{
		d->x = 0;
		while (d->map_utils->map[d->y][d->x])
		{
			c = d->map_utils->map[d->y][d->x];
			if (c == '1' || c == '0' || c == '#')
				d->x++;
			else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && f == 0)
			{
				f = check_letters2(d, c);
				d->x++;
			}
			else
				handle_invalid_input(d);
		}
		d->y++;
	}
	if (!f)
		handle_invalid_input(d);
}

int	check_letters2(t_data *d, char c)
{
	d->map_utils->player_pos = c;
	put_player_pos(d, d->y, d->x);
	return (1);
}

void	put_player_pos(t_data *d, int y, int x)
{
	d->p_y = y + 0.5;
	d->p_x = x + 0.5;
}

void	handle_invalid_input(t_data *d)
{
	ft_free_game(d);
	finish_error("Error: invalid elements in the map!\n", 2);
}
