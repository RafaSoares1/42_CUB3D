/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/18 17:25:42 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	while (ft_search(d->line, '1') != 1)
	{
		free(d->line);
		d->line = get_next_line(d->fd);
	}
	while (ft_search(d->line, '1') == 1)
	{
		if (strlength(d->line) > d->line_length)
			d->line_length = strlength(d->line);
		write(d->temp_fd, d->line, ft_strlen(d->line));
		free(d->line);
		d->line = get_next_line(d->fd);
	}
	map_to_file2(d);
}

int	strlength(char *str)
{
	int i;
	int	tab_count;
	int	j;

	tab_count = 0;
	i = 0;
	j = 0;
	while(str[i])
	{
		if(j == 8)
			j = 0;
		if(str[i] =='\t')
		{
			tab_count = tab_count + (8 - j);
			j = 0;
		}
		j++;
		i++;
	}
	return (i + tab_count);
}

void	map_to_file2(t_data *d)
{
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
	print_matrix(d);
}

void	put_first_last(t_data *d)
{
	int	i;

	i = 0;
	d->map_utils->map[0] = malloc(sizeof(char) * (d->line_length + 1));
	d->map_utils->map[d->count_lines - 1] = malloc(sizeof(char)
			* (d->line_length + 1));
	while (i < d->line_length)
	{
		d->map_utils->map[0][i] = '#';
		i++;
	}
	d->map_utils->map[0][i] = '\0';
	i = 0;
	while (i < d->line_length)
	{
		d->map_utils->map[d->count_lines - 1][i] = '#';
		i++;
	}
	d->map_utils->map[d->count_lines - 1][i] = '\0';
}
