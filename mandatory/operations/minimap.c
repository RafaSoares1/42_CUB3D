/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:48:48 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/25 14:49:24 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_grid(int x, int y, int color, t_data *d)
{
	int	i;
	int	j;

	i = x;
	while(i < x + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, y, color);
		i++;
	}
	i = x;
	while(i < x + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, y + SIZE - 1, color);
		i++;
	}
	j = y;
	while(j < y + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, j, color);
		j++;
	}
	j = y;
	while(j < y + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x + SIZE - 1, j, color);
		j++;
	}
}

void	draw_minimap(t_data *d)
{
	int y = 0;
	int	x = 0;

	while (y < d->count_lines)
	{
		x = 0;
		while (d->map_utils->map[y][x])
		{
			if (d->map_utils->map[y][x] == '1')
			{
				draw_square(x * 50, (y - 1) * 50, WALL, d);
				draw_grid(x * 50, (y - 1) * 50, GRID, d);
			}
			if (d->map_utils->map[y][x] == '0')
			{
				draw_square(x * 50, (y - 1) * 50, FLOOR, d);
				draw_grid(x * 50, (y - 1) * 50, GRID, d);
			}
			if (d->map_utils->map[y][x] == d->map_utils->player_pos)
			{
				draw_square(x * 50, (y - 1) * 50, FLOOR, d);
				draw_grid(x * 50, (y - 1) * 50, GRID, d);
				draw_player((x * 50) + (SIZE / 2), ((y - 1) * 50) + (SIZE / 2), PLAYER, d);
			}
			x++;
		}
	y++;
	}
}

void draw_square(int x, int y, int color, t_data *d)
{
	int	i;
	int	j;

	i = x;
	while(i < x + SIZE)
	{
		j = y;
		while(j < y + SIZE)
		{
			mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, j, color);
			j++;
		}
		i++;
	}
}

void draw_player(int x, int y, int color, t_data *d)
{
	int	j;

	j = 1;
	put_player_pos(d, y, x);
	mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, y, color);
	while(j < PLAYER_SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x + j, y, color);
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x - j, y, color);
		j++;
	}
	j = 1;
	while(j < PLAYER_SIZE + 5)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, y - j, color);
		j++;
	}
}
