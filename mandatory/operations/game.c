/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/09/12 11:28:50 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_game(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	draw_minimap(d);
	mlx_loop(d->mlx_ptr);
}

void draw_square(int x, int y, int size, t_data *d)
{
  int i;
  int j;

	i = x;
  while(i < x + size)
	{
    mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, y, 0x00FF00);			
		i++;
  }
	i = x;
	while(i < x + size)
	{
    mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, y + size - 1, 0x00FF00);			
		i++;
  }
	j = y;
	while(j < y + size)
	{
    mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, j, 0x00FF00);			
		j++;
  }
	j = y;
	while(j < y + size)
	{
    mlx_pixel_put(d->mlx_ptr,d->win_ptr, x + size - 1, j, 0x00FF00);			
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
        draw_square(x * 50, y * 50, 50, d);
			x++;
    }
		y++;
  }
}

/* void	draw_minimap(t_data *d)
{
	int	minimap_width;
	int	minimap_height;
	int	i;
	int	j;
	int	x;
	int	y;

	minimap_width = WIDTH / 500;
	minimap_height = HEIGHT / 100;
	i = 0;
	x = 0;
	y = 0;

	while(y < d->count_lines)
	{
		x = 0;
		while(x < d->line_length)
		{
			i = 0;
			j = (minimap_width * x) + 1;
			if(d->map_utils->map[y][x] == '1')
			{
				while(i < minimap_height)
				{
					if (j == minimap_width)
						j = 0;
					while(j <= minimap_width * 3)
					{
						mlx_pixel_put(d->mlx_ptr, d->win_ptr, j, i, 0xFF00);
						j++;
					}
					i++;
				}
			}
			if (d->map_utils->map[y][x] == '0')
			{
				while(i < minimap_height)
				{
					while(j < minimap_width)
					{
						mlx_pixel_put(d->mlx_ptr, d->win_ptr, j, i, 0xFF0000);
						j++;
					}
					i++;
				}
			}
			if (d->map_utils->map[y][x] == 'N')
			{
				while(i < 10)
				{
					while(j < 10)
					{
						mlx_pixel_put(d->mlx_ptr, d->win_ptr, j, i, 0x005dff);
						j++;
					}
					i++;
				}
			}
			x++;
		}
		y++;
	}
	 while(i < minimap_height)
	{
		j = 0;
		while(j < minimap_width)
		{
			mlx_pixel_put(d->mlx_ptr, d->win_ptr, j, i, 0xFF00);
			j++;
		}
		i++;
	} 
}

 void	draw_wall()
{
	int	i;
	int	j;

	i = 0;
	while(i < minimap_height)
	{
		j = 0;
		while(j < minimap_width)
		{
			mlx_pixel_put(d->mlx_ptr, d->win_ptr, j, i, 0xFF00);
			j++;
		}
		i++;
	}
}

void	draw_floor()
{

}

void	draw_player()
{

}  */