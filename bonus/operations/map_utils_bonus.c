/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/12 12:37:05 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	map_to_file(t_data *d, char *file_name)
{
	d->fd = open(file_name, O_RDONLY);
	d->temp_fd = open("map_temp.map", O_RDWR | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR);
	while (d->i < d->map_utils->skip_count)
	{
		d->line = get_next_line(d->fd);
		free(d->line);
		d->i++;
	}
	d->line = get_next_line(d->fd);
	search_for_map_elem(d);
	while (ft_search(d->line, '1') == 1)
	{
		if (ft_search(d->line, '\t'))
			no_tab_error_handle(d);
		if ((int)ft_strlen(d->line) > d->line_length)
			d->line_length = ft_strlen(d->line);
		write(d->temp_fd, d->line, ft_strlen(d->line));
		free(d->line);
		d->line = get_next_line(d->fd);
	}
	map_to_file2(d);
}

void	search_for_map_elem(t_data *d)
{
	while (ft_search(d->line, '1') != 1)
	{
		if (!ft_search_space(d->line))
		{
			free(d->line);
			ft_no_leak(d, d->line);
			ft_free_game(d);
			finish_error("Error: invalid element position!\n", 2);
		}
		free(d->line);
		d->line = get_next_line(d->fd);
	}
}

void	map_to_file2(t_data *d)
{
	if (ft_no_leak3(d, d->line) == 0)
	{
		close(d->temp_fd);
		ft_free_game(d);
		finish_error("ERROR: Invalid elements after the map!\n", 2);
	}
	close(d->temp_fd);
	map_to_matrix(d);
}

void	map_to_matrix(t_data *d)
{
	d->fd = open("map_temp.map", O_RDONLY);
	d->count_lines = ft_count_lines(d);
	d->map_utils->map = ft_calloc(d->count_lines + 1, sizeof(char *));
	ft_fill_map_index(d);
	close (d->fd);
}

void	ft_fill_map_index(t_data *d)
{
	char	*str;

	d->i = 0;
	d->fd = open("map_temp.map", O_RDONLY);
	d->i = 1;
	put_first_last(d);
	while (d->i <= d->count_lines)
	{
		str = get_next_line(d->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		d->map_utils->map[d->i] = fill_matrix_line(d, str);
		free (str);
		d->i++;
	}
	close(d->fd);
	fill_rest(d);
}
