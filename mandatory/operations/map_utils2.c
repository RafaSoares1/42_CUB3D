/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:45:40 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/06 12:45:40 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*fill_matrix_line(t_data *d, char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * (d->line_length + 1));
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '#';
		line[i] = str[i];
		i++;
	}
	while (i < d->line_length)
	{
		line[i] = '#';
		i++;
	}	
	line[i] = '\0';
	return (line);
}

void	fill_rest(t_data *d)
{
	while (d->map_utils->map[d->x])
	{
		d->y = 0;
		while (d->map_utils->map[d->x][d->y])
		{
			if (d->map_utils->map[d->x][d->y] == ' ')
				d->map_utils->map[d->x][d->y] = '#';
			d->y++;
		}
		d->x++;
	}
}

void	print_matrix(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map_utils->map[i])
	{
		j = 0;
		while (d->map_utils->map[i][j])
		{
			write(1, &d->map_utils->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
