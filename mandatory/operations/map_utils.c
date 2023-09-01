/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/01 09:18:32 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map_to_file(t_data *d, char *file_name)
{
	d->fd = open(file_name, O_RDONLY);
	d->temp_fd = open("map_temp.map", O_RDWR | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR);
	while(d->i < d->map_utils->skip_count)
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
		write(d->temp_fd, d->line, ft_strlen(d->line));
		free(d->line);
		d->line = get_next_line(d->fd);
	}
	free(d->line);
	ft_no_leak(d, d->line);
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
	d->i = 0;
	char	*str;

	d->fd = open("map_temp.map", O_RDONLY);
	d->i = 0;
	while (d->i <= d->count_lines)
	{
		str = get_next_line(d->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		d->map_utils->map[d->i] = ft_strtrim(str, "\n");
		free (str);
		d->i++;
	}
	close(d->fd);
	print_matrix(d);//ta a printar bem !!!
}

void	print_matrix(t_data *d)
{
	int i = 0;
	int j = 0;

	while(d->map_utils->map[i])
	{
		j = 0;
		while(d->map_utils->map[i][j])
		{
			write(1, &d->map_utils->map[i][j], 1);
			j++;
		}
		write(1,"\n", 1);
		i++;
	}
	write(1,"\n", 1);
}
