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

#include "../cub3d_bonus.h"

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

static void	process_tabs_and_spaces(char *str, char *line, t_data *d)
{
	while (str[d->a])
	{
		if (str[d->a] == '\n')
			str[d->a] = '#';
		line[d->b] = str[d->a];
		d->a++;
		d->b++;
	}
}

static void	fill_remaining_with_hash(char *line, t_data *d)
{
	while (d->b < d->line_length)
	{
		line[d->b++] = '#';
	}
}

char	*fill_matrix_line(t_data *d, char *str)
{
	char	*line;

	d->a = 0;
	d->b = 0;
	line = malloc(sizeof(char) * (d->line_length + 1));
	process_tabs_and_spaces(str, line, d);
	fill_remaining_with_hash(line, d);
	line[d->b] = '\0';
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
	check_letters(d);
	ft_map_dup(d);
	if (check_flood_fill(d, d->map_utils->map_dup, d->p_x, d->p_y) == 0)
	{
		ft_free_game3(d);
		finish_error("Error: Map is not closed!\n", 2);
	}
}
