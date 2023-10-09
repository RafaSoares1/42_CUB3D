/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:11 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/09 10:41:45 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_movs(t_data *d)
{
	if (d->key_press_up == 1)
		move_vertical(d, 1);
	if (d->key_press_down == 1)
		move_vertical(d, 0);
	if (d->key_press_right == 1)
		move_horizontal(d, 1);
	if (d->key_press_left == 1)
		move_horizontal(d, 0);
	if (d->key_press_r_left == 1)
		rotate_player(d, -1);
	if (d->key_press_r_right == 1)
		rotate_player(d, 1);
	if (d->key_press_up || d->key_press_down || d->key_press_left
		|| d->key_press_right || d->key_press_r_left || d->key_press_r_right)
		return (1);
	return (0);
}

void	move_vertical(t_data *d, int dir_flag)
{
	if (dir_flag)
	{
		if (d->map_utils->map[(int)(d->p_y + d->dir_y * 0.2)]
			[(int) d->p_x] != '1')
			d->p_y += d->dir_y * 0.2;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x + d->dir_x * 0.2)] != '1')
			d->p_x += d->dir_x * 0.2;
	}
	else
	{
		if (d->map_utils->map[(int)(d->p_y - d->dir_y * 0.2)]
			[(int) d->p_x] != '1')
			d->p_y -= d->dir_y * 0.2;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x - d->dir_x * 0.2)] != '1')
			d->p_x -= d->dir_x * 0.2;
	}
}

void	move_horizontal(t_data *d, int dir_flag)
{
	if (dir_flag)
	{
		if (d->map_utils->map[(int)(d->p_y + d->dir_x * 0.2)]
			[(int) d->p_x] != '1')
			d->p_y += d->dir_x * 0.2;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x - d->dir_y * 0.2)] != '1')
			d->p_x -= d->dir_y * 0.2;
	}
	else
	{
		if (d->map_utils->map[(int)(d->p_y - d->dir_x * 0.2)]
			[(int) d->p_x] != '1')
			d->p_y -= d->dir_x * 0.2;
		if (d->map_utils->map[(int)d->p_y]
			[(int)(d->p_x + d->dir_y * 0.2)] != '1')
			d->p_x += d->dir_y * 0.2;
	}
}

void	rotate_player(t_data *d, int dir_flag)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.10;
	if (dir_flag != 1)
		angle *= -1;
	temp_x = d->dir_x * cos(angle) - d->dir_y * sin(angle);
	temp_y = d->dir_x * sin(angle) + d->dir_y * cos(angle);
	d->dir_x = temp_x;
	d->dir_y = temp_y;
	temp_x = d->plane_x * cos(angle) - d->plane_y * sin(angle);
	temp_y = d->plane_x * sin(angle) + d->plane_y * cos(angle);
	d->plane_x = temp_x;
	d->plane_y = temp_y;
}
