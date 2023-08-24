/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:32:39 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/24 21:04:38 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_stack(t_data *d)
{
    d->mlx_ptr = 0;
	d->win_ptr = 0;
	d->x = 0;
	d->y = 0;
	d->fd = 0;
	d->map_utils->map = 0;
	d->map_utils->no = 0;
	d->map_utils->so = 0;
	d->map_utils->we = 0;
	d->map_utils->ea = 0;
	d->map_utils->color_aux = 0;
}

int ft_count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	finish_error(char *str, int i)
{
	ft_putstr_fd(str, i);
	exit(i);	
}
