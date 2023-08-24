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
	line = get_next_line(d->fd);
	while (!d->map_utils->no || !d->map_utils->so || !d->map_utils->we ||
		!d->map_utils->ea || !d->map_utils->f_color || !d->map_utils->c_color)
	{
		if(ft_strchr("1\t", line[0]))
		{
			ft_putstr_fd("File element position error!\n", 2);
			exit(2);
		}
		valid_info(d, line);
		free(line);
		line = get_next_line(d->fd);
	}
}

void	valid_info(t_data *d, char *line)
{
	if(!ft_strncmp("NO ", line, 3))
	{
		put_path(d, line, 1);
		return ;
	}
	else if(!ft_strncmp("SO ", line, 3))
	{
		put_path(d, line, 2);
		return ;
	}
	else if(!ft_strncmp("WE ", line, 3))
	{
		put_path(d, line, 3);
		return ;
	}
	else if(!ft_strncmp("EA ", line, 3))
	{
		put_path(d, line, 4);
		return ;
	}
	else if(!ft_strncmp("F ", line, 2))
	{
		put_rgb(d, line, 1);
		return ;
	}
	else if(!ft_strncmp("C ", line, 2))
	{
		put_rgb(d, line, 2);
	}
}

void	put_path(t_data *d, char *line, int flag)
{
	char *temp;

	temp = ft_strdup(line + 3);
	if(flag == 1 && !d->map_utils->no)
		d->map_utils->no = ft_strtrim(temp, " \t\n");
	else if(flag == 2 && !d->map_utils->so)
		d->map_utils->so = ft_strtrim(temp, " \t\n");
	else if(flag == 3 && !d->map_utils->we)
		d->map_utils->we = ft_strtrim(temp, " \t\n");
	else if(flag == 4 && !d->map_utils->ea)
		d->map_utils->ea = ft_strtrim(temp, " \t\n");
	free(temp);
	return ;
}

void	put_rgb(t_data *d, char *line, int flag)
{
	int	i;

	i = 0;
	if (ft_count(line, ',') != 2)
		finish_error("Error: Wrong number of color values!\n", 2);
	d->map_utils->color_aux = ft_split(line + 2, ',');
	while (i < 3)
	{
		if (!(ft_atoi(d->map_utils->color_aux[i]) >= 0 && ft_atoi(d->map_utils->color_aux[i]) <= 255))
		{
			free_double_pointer(d->map_utils->color_aux);
			finish_error("Error: Wrong value in RGB!\n", 2);
		}
		i++;
	}
	if (flag == 1)
		put_fc_rgb(d, flag);
	else if (flag == 2)
		put_fc_rgb(d, flag);
	free_double_pointer(d->map_utils->color_aux);
}

void	put_fc_rgb(t_data *d, int flag)
{
	if (flag == 1)
	{
		d->map_utils->f_color[ft_atoi(d->map_utils->color_aux[0])]
		[ft_atoi(d->map_utils->color_aux[1])]
		[ft_atoi(d->map_utils->color_aux[2])] = 1;
	}
	else if (flag == 2)
	{
		d->map_utils->c_color[ft_atoi(d->map_utils->color_aux[0])]
		[ft_atoi(d->map_utils->color_aux[1])]
		[ft_atoi(d->map_utils->color_aux[2])] = 1;
	}
}
