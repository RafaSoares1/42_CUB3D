/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/30 12:32:02 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map_to_file(t_data *d, char *file_name)
{
	int i;
	char *line;

	i = 0;
	d->fd = open(file_name, O_RDONLY);
	d->temp_fd = open("map_temp.map", O_RDWR | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR);
	while(i < d->map_utils->skip_count)
	{
		line = get_next_line(d->fd);
		free(line);
		i++;
	}
	line = get_next_line(d->fd);
	while(ft_search(line, '1') != 1)
	{
		free(line);
		line = get_next_line(d->fd);
	}
	while(ft_search(line, '1') == 1)
	{
		write(d->temp_fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(d->fd);
	}
	free(line);
	ft_no_leak(d, line);
	close(d->temp_fd);
}