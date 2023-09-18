/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:56:26 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/14 10:56:26 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_stack(t_data *d)
{
	d->mlx_ptr = 0;
	d->win_ptr = 0;
	d->line = 0;
	d->count_lines = 0;
	d->line_length = 0;
	d->p_y = 0;
	d->p_x = 0;
	d->dir_y = 0;
	d->dir_x = 0;
	d->plane_x = 0;
	d->plane_y = 0;
	d->camera_x = 0;
	d->raydir_x = 0;
	d->raydir_y = 0;
	d->mapx = 0;
	d->mapy = 0;
	d->side_dist_x = 0;
	d->side_dist_y = 0;
	d->delta_dist_x = 0;
	d->delta_dist_y = 0;
	d->perp_wall_dist = 0;
	ft_init_stack1(d);
}

void	ft_init_stack1(t_data *d)
{
	d->stepx = 0;
	d->stepy = 0;
	d->hit = 0;
	d->side = 0;
	d->draw_start = 0;
	d->draw_end = 0;
	d->line_height = 0;
	d->x = 0;
	d->y = 0;
	d->fd = 0;
	d->temp_fd = 0;
	d->i = 0;
	ft_init_stack2(d);
}

void	ft_init_stack2(t_data *d)
{
	d->map_utils->map = 0;
	d->map_utils->map_dup = 0;
	d->map_utils->no = 0;
	d->map_utils->so = 0;
	d->map_utils->we = 0;
	d->map_utils->ea = 0;
	d->map_utils->flag_c = 0;
	d->map_utils->flag_f = 0;
	d->map_utils->player_pos = 0;
	d->map_utils->f_color = 0;
	d->map_utils->c_color = 0;
	d->map_utils->color_aux = 0;
	d->map_utils->skip_count = 0;
}

void	ft_init_stack3(t_data *d)
{
	d->img->addr = 0;
	d->img->bpp = 0;
	d->img->endian = 0;
	d->img->img = 0;
	d->img->line_length = 0;
}
