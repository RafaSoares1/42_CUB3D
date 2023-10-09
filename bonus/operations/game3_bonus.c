/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:31:12 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/27 15:31:12 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_floor_celling2(t_data *d, int f_color, int c_color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y <= (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, c_color);
			if (y > (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, f_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}
