/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:32:39 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/29 12:14:06 by emsoares         ###   ########.fr       */
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
	d->map_utils->c_color = 0;
	d->map_utils->f_color = 0;
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

void	ft_free_game(t_data *d)
{
	free_double_pointer(d->map_utils->c_color);
	free_double_pointer(d->map_utils->f_color);
	free(d->map_utils->ea);
	free(d->map_utils->no);
	free(d->map_utils->so);
	free(d->map_utils->we);
}

void	ft_no_leak(t_data *d, char *line)
{
	while(1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break;
		free(line);
	}
	close(d->fd);
}
