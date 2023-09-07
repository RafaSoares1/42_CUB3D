/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:56:11 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/07 14:56:11 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_path(t_data *d, char *line, int flag)
{
	char	*temp;

	temp = ft_strdup(line + 3);
	if (flag == 1 && !d->map_utils->no)
		d->map_utils->no = ft_strtrim(temp, " \t\n");
	else if (flag == 2 && !d->map_utils->so)
		d->map_utils->so = ft_strtrim(temp, " \t\n");
	else if (flag == 3 && !d->map_utils->we)
		d->map_utils->we = ft_strtrim(temp, " \t\n");
	else if (flag == 4 && !d->map_utils->ea)
		d->map_utils->ea = ft_strtrim(temp, " \t\n");
	free(temp);
	return ;
}

void	error_in_elem(t_data *d, char *line)
{
	free(line);
	ft_no_leak(d, line);
	ft_free_game(d);
	finish_error("Error: invalid element!\n", 2);
}
