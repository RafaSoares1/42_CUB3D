/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/30 15:52:09 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map_to_file(t_data *d, char *file_name)
{
	d->fd = open(file_name, O_RDONLY);
	d->temp_fd = open("map_temp.map", O_RDWR | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR);
	while(i < d->map_utils->skip_count)
	{
		d->line = get_next_line(d->fd);
		free(d->line);
		d->i++;
	}
	d->line = get_next_line(d->fd);
	while(ft_search(d->line, '1') != 1)
	{
		free(d->line);
		d->line = get_next_line(d->fd);
	}
	while(ft_search(d->line, '1') == 1)
	{
		write(d->temp_fd, d->line, ft_strlen(line));
		free(d->line);
		d->line = get_next_line(d->fd);
	}
	free(d->line);
	ft_no_leak(d, line);
	close(d->temp_fd);
	map_to_matrix(d);
}

void	map_to_matrix(t_data *d)
{
	d->fd = open("../../map_temp.map", O_RDONLY);
	
}
