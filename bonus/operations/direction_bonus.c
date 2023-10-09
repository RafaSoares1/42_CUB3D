/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:04:55 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/09 10:41:01 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	direction(t_data *d)
{
	if (d->map_utils->player_pos == 'N')
	{
		d->dir_x = 0;
		d->dir_y = -1;
		d->plane_x = 0.66;
		d->plane_y = 0;
		return ;
	}
	if (d->map_utils->player_pos == 'S')
	{
		d->dir_x = 0;
		d->dir_y = 1;
		d->plane_x = -0.66;
		d->plane_y = 0;
		return ;
	}
	direction2(d);
}

void	direction2(t_data *d)
{
	if (d->map_utils->player_pos == 'E')
	{
		d->dir_x = 1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = 0.66;
		return ;
	}
	if (d->map_utils->player_pos == 'W')
	{
		d->dir_x = -1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = -0.66;
		return ;
	}
}
