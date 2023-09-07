/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:51:14 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/24 14:51:14 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	args_in_file(t_data *d, char *file_name)
{
	char	*line;

	d->fd = open(file_name, O_RDONLY);
	while (!d->map_utils->no || !d->map_utils->f_color || !d->map_utils->we
		|| !d->map_utils->ea || !d->map_utils->so || !d->map_utils->c_color)
	{
		line = get_next_line(d->fd);
		if (ft_strchr(" 1\t", line[0]))
		{
			free(line);
			ft_no_leak(d, line);
			ft_free_game(d);
			finish_error("File element position error!\n", 2);
		}
		valid_info(d, line);
		free(line);
		d->map_utils->skip_count++;
	}
	ft_no_leak(d, line);
	map_to_file(d, file_name);
}

void	valid_info(t_data *d, char *line)
{
	if (!ft_strncmp("NO ", line, 3))
	{
		if (d->map_utils->no)
			error_dup_elem(d, line);
		put_path(d, line, 1);
		return ;
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (d->map_utils->so)
			error_dup_elem(d, line);
		put_path(d, line, 2);
		return ;
	}
	valid_info1(d, line);
	valid_info2(d, line);
}

void	error_dup_elem(t_data *d, char *line)
{
	free(line);
	ft_no_leak(d, line);
	ft_free_game(d);
	finish_error("Error: duplicate elements!\n", 2);
}

void	valid_info1(t_data *d, char *line)
{
	if (!ft_strncmp("WE ", line, 3))
	{
		if (d->map_utils->we)
			error_dup_elem(d, line);
		put_path(d, line, 3);
		return ;
	}
	else if (!ft_strncmp("EA ", line, 3))
	{
		if (d->map_utils->ea)
			error_dup_elem(d, line);
		put_path(d, line, 4);
		return ;
	}
}

void	valid_info2(t_data *d, char *line)
{
	if (!ft_strncmp("F ", line, 2))
	{
		if (d->map_utils->f_color)
			error_dup_elem(d, line);
		put_rgb(d, line, 1);
		return ;
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (d->map_utils->c_color)
			error_dup_elem(d, line);
		put_rgb(d, line, 2);
		return ;
	}
}
