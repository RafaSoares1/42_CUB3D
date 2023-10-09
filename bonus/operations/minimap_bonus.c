/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:48:48 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/09 18:54:27 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_minimap(t_data *d)
{
	d->draw_y = 0;
	d->y = (int)d->p_y - 5;
	d->temp_y = d->y;
	while (d->y < d->temp_y + 11)
	{
		d->draw_x = 0;
		d->x = (int)d->p_x - 5;
		d->temp_x = d->x;
		while (d->x < d->temp_x + 11)
		{
			if (d->y < 0 || d->y >= d->count_lines || d->x < 0 || d->x >= d->line_length)
				draw_on_map(d, OUTSIDE, d->draw_x, d->draw_y);
			else if (ft_strchr("1", d->map_utils->map[d->y][d->x]))
				draw_on_map(d, WALL, d->draw_x, d->draw_y);
			else if (ft_strchr("0", d->map_utils->map[d->y][d->x]))
				draw_on_map(d, FLOOR, d->draw_x, d->draw_y);
			else if (d->map_utils->map[d->y][d->x] == d->map_utils->player_pos)
				draw_on_map(d, FLOOR, d->draw_x, d->draw_y);
			d->x++;
			d->draw_x += 10;
		}
		d->y++;
		d->draw_y += 10;
	}
	draw_player_minimap(d, PLAYER);
}

void	draw_on_map(t_data *d, int color, int draw_x, int draw_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put_minimap(d, (draw_x + j), (draw_y + i), color);
			j++;
		}
		i++;
	}
}

void	draw_player_minimap(t_data *d, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put_minimap(d, ((10 * 5) + j), ((10 * 5) + i), color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->minimap_img->img, 0, 0);
}

void	my_mlx_pixel_put_minimap(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->minimap_img->addr + (y * data->minimap_img->line_length
			+ x * (data->minimap_img->bpp / 8));
	*(unsigned int *)dst = color;
}
