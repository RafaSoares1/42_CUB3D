/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:05:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/09 10:41:03 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_draw(t_data *d, int i)
{
	int	color;
	int	y;

	get_wall_x(d);
	d->tex_x = (int)(d->wall_x * (double)TEX_WIDTH);
	d->tex_x = TEX_WIDTH - d->tex_x - 1;
	d->text_step = 1.0 * TEX_WIDTH / d->line_height;
	d->text_pos = (d->draw_start - HEIGHT / 2
			+ d->line_height / 2) * d->text_step;
	y = d->draw_start;
	while (y < d->draw_end)
	{
		d->tex_y = (int)d->text_pos & (TEX_HEIGHT - 1);
		d->text_pos += d->text_step;
		if (i >= 0 && y >= 0 && d->tex_x >= 0 && d->tex_y >= 0)
		{
			color = ft_get_pixel(d, d->tex_x, d->tex_y);
			my_mlx_pixel_put(d, i, y, color);
		}
		y++;
	}
}

void	get_wall_x(t_data *d)
{
	if (d->side == 0)
	{
		d->wall_x = d->p_y + d->perp_wall_dist * d->raydir_y;
		d->wall_x -= floor(d->wall_x);
	}
	if (d->side == 1)
	{
		d->wall_x = d->p_x + d->perp_wall_dist * d->raydir_x;
		d->wall_x -= floor(d->wall_x);
	}
}

int	ft_get_pixel(t_data *d, int x, int y)
{
	return (*(unsigned int *)((d->aux->addr
			+ (y * d->aux->line_length) + (x * d->aux->bpp / 8))));
}
