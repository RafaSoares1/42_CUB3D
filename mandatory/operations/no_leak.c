/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leak.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:33:49 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/06 11:35:20 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_no_leak(t_data *d, char *line)
{
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		valid_info(d, line);
		free(line);
	}
	close(d->fd);
}

void	ft_no_leak2(t_data *d, char *line)
{
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		free(line);
	}
	close(d->fd);
}

int	ft_no_leak3(t_data *d, char *line)
{
	int	i;

	i = 0;
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		if (!ft_search_space(line))
			i++;
		free(line);
	}
	close(d->fd);
	if (i == 0)
		return (1);
	return (0);
}
