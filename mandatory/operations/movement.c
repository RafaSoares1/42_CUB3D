/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:11 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/28 14:16:32 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_movs(t_data *d)
{
	if (d->key_press == 'w' || d->key_press == 's')
	{
		move_vertical(d);
		return (1);
	}
	if (d->key_press == 'a' || d->key_press == 'd')
	{
		move_horizontal(d);
		return (1);
	}
	if (d->key_press == 'l' || d->key_press == 'r')
	{
		rotate_player(d);
		return (1);
	}
	return (0);
}

void	move_vertical(t_data *d)
{
	if (d->key_press == 'w')
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

void	move_horizontal(t_data *d)
{
	if (d->key_press == 'd')
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

void	rotate_player(t_data *d)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.07;
	if (d->key_press != 'r')
		angle *= -1;
	temp_x = d->dir_x * cos(angle) - d->dir_y * sin(angle);
	temp_y = d->dir_x * sin(angle) + d->dir_y * cos(angle);
	d->dir_x = temp_x;
	d->dir_y = temp_y;
	temp_x = d->plane_x * cos(angle) - d->plane_y * sin(angle);
	temp_y = d->plane_x * sin(angle) + d->plane_y * cos(angle);
	d->plane_x = temp_x;
	d->plane_y = temp_y;
	printf("%f, %f\n", d->dir_x, d->dir_y);
}
