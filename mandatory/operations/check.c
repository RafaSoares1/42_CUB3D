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
				check_letters2(d, c);
				f = 1;
				d->x++;
			}
			else
				handle_invalid_input(d);
		}
		d->y++;
	}
}

void	check_letters2(t_data *d, char c)
{
	d->map_utils->player_pos = c;
	put_player_pos(d, d->y, d->x);
}

void	put_player_pos(t_data *d, int y, int x)
{
	d->p_y = y;
	d->p_x = x;
}

void	handle_invalid_input(t_data *d)
{
	ft_free_game(d);
	finish_error("Error: invalid elements in the map!\n", 2);
}

int	check_flood_fill(t_data *d, char **map, int x, int y)
{
	static int	hastag_count;

	if (y < 0 || x < 0 || y > d->count_lines || x > d->line_length
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == '#')
	{
		hastag_count++;
		map[y][x] = 'X';
		return (0);
	}
	map[y][x] = 'X';
	check_flood_fill(d, map, x + 1, y);
	check_flood_fill(d, map, x - 1, y);
	check_flood_fill(d, map, x, y + 1);
	check_flood_fill(d, map, x, y - 1);
	if (hastag_count == 0)
		return (1);
	return (0);
}
