/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:18:42 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/25 14:39:29 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	direction(t_data *d)
{
	if (d->map_utils->player_pos == 'N')
	{
		d->dir_x = 0, d->dir_y = -1;
		d->plane_x = 0.66, d->plane_y = 0;
	}
	if (d->map_utils->player_pos == 'S')
	{
		d->dir_x = 0, d->dir_y = 1;
		d->plane_x = -0.66, d->plane_y = 0;
	}
	if (d->map_utils->player_pos == 'E')
	{
		d->dir_x = 1, d->dir_y = 0;
		d->plane_x = 0, d->plane_y = 0.66;
	}
	if (d->map_utils->player_pos == 'W')
	{
		d->dir_x = -1, d->dir_y = 0;
		d->plane_x = 0, d->plane_y = -0.66;
	}
}

void	ray_calc(t_data *d)
{
	d->camera_x = 2 * d->i / (double)WIDTH - 1;
	d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
	d->raydir_y = d->dir_y + d->plane_y * d->camera_x;
	d->mapx = (int)d->p_x;
	d->mapy = (int)d->p_y;
	if (d->raydir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->raydir_x);
	if (d->raydir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->raydir_y);
	d->hit = 0;
}

void	check_side(t_data *d)
{
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
		d->side_dist_y = (d->p_y - d->mapy) * d->delta_dist_y;
	}
	else
	{
		d->stepy = 1;
		d->side_dist_y = (d->mapy + 1.0 - d->p_y) * d->delta_dist_y;
	}
}

void	get_hit(t_data *d)
{
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
}

void	ray_values(t_data *d)
{
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
}