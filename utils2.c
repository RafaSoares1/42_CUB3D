/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:42:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/06 17:42:07 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_map_dup(t_data *d)
{
	int	i;

	i = 0;
	d->map_utils->map_dup = ft_calloc(d->count_lines + 1, sizeof(char *));
	while (i < d->count_lines)
	{
		d->map_utils->map_dup[i] = ft_strdup(d->map_utils->map[i]);
		i++;
	}
}

int	ft_search_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	strlength(char *str)
{
	int	i;
	int	tab_count;
	int	j;

	tab_count = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (j == 8)
			j = 0;
		if (str[i] == '\t')
		{
			tab_count = tab_count + (8 - j);
			j = 0;
		}
		j++;
		i++;
	}
	return (i + tab_count);
}

void	check_spaces_before_newline(t_data *d, char *temp, char *line)
{
	int	i;

	i = 0;
	while (temp[i + 1] != '\n')
		i++;
	if (temp[i] == ' ')
	{
		free(temp);
		error_in_elem(d, line);
	}
}
