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
		ft_free_game4(d);
		exit (2);
	}
	if (keysym == 119)
		d->key_press_up = 1;
	if (keysym == 97)
		d->key_press_left = 1;
	if (keysym == 115)
		d->key_press_down = 1;
	if (keysym == 100)
		d->key_press_right = 1;
	if (keysym == 65361)
		d->key_press_r_left = 1;
	if (keysym == 65363)
		d->key_press_r_right = 1;
	return (0);
}

int	release_key(int keysym, t_data *d)
{
	if (keysym == 119)
		d->key_press_up = 0;
	if (keysym == 97)
		d->key_press_left = 0;
	if (keysym == 115)
		d->key_press_down = 0;
	if (keysym == 100)
		d->key_press_right = 0;
	if (keysym == 65361)
		d->key_press_r_left = 0;
	if (keysym == 65363)
		d->key_press_r_right = 0;
	return (0);
}
