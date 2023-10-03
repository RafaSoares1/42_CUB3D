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

static void	process_tabs_and_spaces(char *str, char *line, int *i, int *j)
{
	unsigned int	tab_count;

	while (str[*i])
	{
		(tab_count)++;
		if (str[*i] == '\t')
		{
			if (tab_count == 8)
				tab_count = 0;
			while ((tab_count)++ <= 8)
				line[(*j)++] = ' ';
			tab_count = 0;
			(*i)++;
		}
		else
		{
			if (tab_count >= 7)
				tab_count = 0;
			if (str[*i] == '\n')
				str[*i] = '#';
			line[*j] = str[*i];
			(*i)++;
			(*j)++;
		}
	}
}

static void	fill_remaining_with_hash(char *line, int line_length, int *j)
{
	while (*j < line_length)
	{
		line[(*j)++] = '#';
	}
}

char	*fill_matrix_line(t_data *d, char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (d->line_length + 1));
	process_tabs_and_spaces(str, line, &i, &j);
	fill_remaining_with_hash(line, d->line_length, &j);
	line[j] = '\0';
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
