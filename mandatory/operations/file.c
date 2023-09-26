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
			finish_error("Error: invalid element position!\n", 2);
		}
		if (!valid_info(d, line) && line[0] != '\n')
			error_in_elem(d, line);
		free(line);
		d->map_utils->skip_count++;
	}
	ft_no_leak(d, line);
	ft_check_textures(d);
	map_to_file(d, file_name);
}

int	valid_info(t_data *d, char *line)
{
	int	r;

	r = 0;
	if (!ft_strncmp("NO ", line, 3))
	{
		if (d->map_utils->no)
			error_dup_elem(d, line);
		put_path(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("SO ", line, 3))
	{
		if (d->map_utils->so)
			error_dup_elem(d, line);
		put_path(d, line, 2);
		return (1);
	}
	if (valid_info1(d, line) == 1)
		r = 1;
	if (valid_info2(d, line) == 1)
		r = 1;
	return (r);
}

int	valid_info1(t_data *d, char *line)
{
	if (!ft_strncmp("WE ", line, 3))
	{
		if (d->map_utils->we)
			error_dup_elem(d, line);
		put_path(d, line, 3);
		return (1);
	}
	else if (!ft_strncmp("EA ", line, 3))
	{
		if (d->map_utils->ea)
			error_dup_elem(d, line);
		put_path(d, line, 4);
		return (1);
	}
	return (0);
}

int	valid_info2(t_data *d, char *line)
{
	if (!ft_strncmp("F ", line, 2))
	{
		if (d->map_utils->f_color)
			error_dup_elem(d, line);
		put_rgb(d, line, 1);
		return (1);
	}
	else if (!ft_strncmp("C ", line, 2))
	{
		if (d->map_utils->c_color)
			error_dup_elem(d, line);
		put_rgb(d, line, 2);
		return (1);
	}
	return (0);
}

void	error_dup_elem(t_data *d, char *line)
{
	free(line);
	ft_no_leak(d, line);
	ft_free_game(d);
	finish_error("Error: duplicate elements!\n", 2);
}
