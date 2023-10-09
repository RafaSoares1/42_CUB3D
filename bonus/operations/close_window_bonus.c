/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:34:50 by jomirand          #+#    #+#             */
/*   Updated: 2023/10/09 10:40:59 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_xbutton(t_data *d)
{
	if (d != NULL && d->mlx_ptr != NULL && d->win_ptr != NULL)
		ft_free_game4(d);
	exit(0);
}
