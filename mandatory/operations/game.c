/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/09/18 14:02:06 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_game(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	d->img = ft_calloc(1, sizeof(t_image));
	ft_init_stack3(d);
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp, &d->img->line_length, &d->img->endian); 
	//draw_minimap(d);
	//mlx_hook(d->win_ptr, KeyPress, KeyPressMask, ft_keypress, &mlx);
	
	mlx_hook(d->win_ptr, KeyPress, KeyPressMask, handle_input, d);
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_xbutton, d);
	mlx_loop_hook(d->mlx_ptr, game_loop, d);
	mlx_loop(d->mlx_ptr);
}

int	game_loop(t_data *d)//funcao principal para renders
{
	draw_raycast(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
	return (0);
}

void	draw_raycast(t_data *d)
{
	int color;
	draw_floor_celling(d);
	//Position of the Player in d->p_y and p_x;
	d->dir_x = 0, d->dir_y = -1;//initial direction vector = NORTH
	d->plane_x = 1, d->plane_y = 0;
	d->i = 0;
	while(d->i < WIDTH)
	{
		d->camera_x = 2 * d->i / (double)WIDTH - 1;
		d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
		d->raydir_y = d->dir_y + d->plane_y * d->camera_x;
		d->mapx = d->p_x;
		d->mapy = d->p_y;
		if (d->raydir_x == 0)
			d->delta_dist_x = 1e30;
		else
			d->delta_dist_x = fabs(1 / d->raydir_x);
		if (d->raydir_y == 0)
			d->delta_dist_y = 1e30;
		else
			d->delta_dist_y = fabs(1 / d->raydir_y);
		d->hit = 0;

		if (d->raydir_x < 0)
		{
			d->stepx = -1;
			d->side_dist_x = (d->p_x - d->mapx) * d->delta_dist_x;
		}
		else
		{
			d->stepx = 1;
			d->side_dist_x = (d->mapx + 1.0 - d->p_x) * d->delta_dist_x;
		}
		if (d->raydir_y < 0)
		{
			d->stepy = -1;
			d->side_dist_y = (d->p_y - d->mapx) * d->delta_dist_y;
		}
		else
		{
			d->stepy = 1;
			d->side_dist_y = (d->mapy + 1.0 - d->p_y) * d->delta_dist_y;
		}
		while (!d->hit)
		{
			if ( d->side_dist_x < d->side_dist_y)
			{
				d->side_dist_x += d->delta_dist_x;
				d->mapx += d->stepx;
				d->side = 0;
			}
			else
			{
				d->side_dist_y += d->delta_dist_y;
				d->mapy += d->stepy;
				d->side = 1;
			}
			if (d->map_utils->map[d->mapy][d->mapx] == '1')
				d->hit = 1;
		}
		if (d->side == 0)
			d->perp_wall_dist = (d->side_dist_x - d->delta_dist_x);
		else
			d->perp_wall_dist = (d->side_dist_y - d->delta_dist_y);
		if (d->perp_wall_dist)
			d->line_height = (int)(HEIGHT / d->perp_wall_dist);
		else
			d->line_height = HEIGHT;
		d->draw_start = -d->line_height / 2 + HEIGHT / 2;
		if (d->draw_start < 0)
			d->draw_start = 0;
		d->draw_end = d->line_height / 2 + HEIGHT / 2;
		if (d->draw_end >= HEIGHT)
			d->draw_end = HEIGHT - 1;
		if (d->side == 1)
			color = 0xffc0cb;
		else
			color = 0xfff4aa;
		int j = d->draw_start;
		while (j < d->draw_end)
		{
			my_mlx_pixel_put(d, d->i, j, color);
			j++;
		}
		d->i++;
	}
}

void	draw_floor_celling(t_data *d)
{
	int	x;
	int	y;
	unsigned int f_color;
	unsigned int c_color;

	x = 0;
	y = 0;
	f_color = (0x010000 * ft_atoi(d->map_utils->f_color[0])) + (0x000100 * ft_atoi(d->map_utils->f_color[1])) + ft_atoi(d->map_utils->f_color[2]);
	c_color = 0x010000 * ft_atoi(d->map_utils->c_color[0]) + 0x000100 * ft_atoi(d->map_utils->c_color[1]) + ft_atoi(d->map_utils->c_color[2]);
	while(x < WIDTH)
	{
		y = 0;
		while(y < HEIGHT)
		{
			if (y <= (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, c_color);
			if(y > (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, f_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
	*(unsigned int*)dst = color;
}


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
			if (d->map_utils->map[y][x] == 'N') //falta S, E e W
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