/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:26:09 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/25 15:26:09 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_input(int keysym, t_data *d)
{
	(void) d;
	if (keysym == 65307)
	{
		//FALTA FREE
		exit (2);
	}
	if (keysym == 119)
		d->key_press = 'w';
	if (keysym == 97)
		d->key_press = 'a';
	if (keysym == 115)
		d->key_press = 's';
	if (keysym == 100)
		d->key_press = 'd';
	if (keysym == 65361)
		d->key_press = 'l';
	if (keysym == 65363)
		d->key_press = 'r';
	return (0);
}

int	release_key(int keysym, t_data *d)
{
	if (keysym == 119)
		d->key_press = 'u';
	if (keysym == 97)
		d->key_press = 'u';
	if (keysym == 115)
		d->key_press = 'u';
	if (keysym == 100)
		d->key_press = 'u';
	if (keysym == 65361)
		d->key_press = 'u';
	if (keysym == 65363)
		d->key_press = 'u';	
	return (0);
}

void	ft_move_player(t_data *d, int y, int x)
{
	draw_player(x, y, PLAYER, d);
}