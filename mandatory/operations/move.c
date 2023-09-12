/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:51:14 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/12 14:51:14 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_input(int keysym, t_data *d)
{
	if (keysym == 65307)
	{
		exit (2);
	}
	if (keysym == 119)//W
	{
		draw_player(d->p_x, d->p_y, FLOOR, d);
		ft_move_player(d, d->p_y - 1, d->p_x);
	}
	if (keysym == 97)//A
	{
		draw_player(d->p_x, d->p_y, FLOOR, d);
		ft_move_player(d, d->p_y, d->p_x - 1);
	}
	if (keysym == 115)//S
	{
		draw_player(d->p_x, d->p_y, FLOOR, d);
		ft_move_player(d, d->p_y + 1, d->p_x);
	}	
	if (keysym == 100)//D
	{
		draw_player(d->p_x, d->p_y, FLOOR, d);
		ft_move_player(d, d->p_y, d->p_x + 1);
	}	
	return (0);
}

void	ft_move_player(t_data *d, int y, int x)
{
	draw_player(x, y, PLAYER, d);
}