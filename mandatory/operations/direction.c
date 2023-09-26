/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:04:55 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/26 19:09:00 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
