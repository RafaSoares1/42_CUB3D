/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:16:56 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/24 19:16:56 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_game(t_data *d)
{
	if (d->map_utils->flag_c == 1)
		free_double_pointer(d->map_utils->c_color);
	if (d->map_utils->flag_f == 1)
		free_double_pointer(d->map_utils->f_color);
	if (d->map_utils->map)
		free_double_pointer(d->map_utils->map);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	free(d->map_utils);
	free(d);
}

void	ft_free_game2(t_data *d)
{
	if (d->map_utils->flag_c == 1)
		free_double_pointer(d->map_utils->c_color);
	if (d->map_utils->flag_f == 1)
		free_double_pointer(d->map_utils->f_color);
	if (d->map_utils->map)
		free_double_pointer(d->map_utils->map);
	if (d->map_utils->map_dup)
		free_double_pointer(d->map_utils->map_dup);
	if (d->map_utils->color_aux)
		free_double_pointer(d->map_utils->color_aux);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	free(d->map_utils);
	free(d);
}

void	ft_free_game3(t_data *d)
{
	if (d->map_utils->flag_c == 1)
		free_double_pointer(d->map_utils->c_color);
	if (d->map_utils->flag_f == 1)
		free_double_pointer(d->map_utils->f_color);
	if (d->map_utils->map)
		free_double_pointer(d->map_utils->map);
	if (d->map_utils->map_dup)
		free_double_pointer(d->map_utils->map_dup);
	if (d->map_utils->ea)
		free(d->map_utils->ea);
	if (d->map_utils->no)
		free(d->map_utils->no);
	if (d->map_utils->so)
		free(d->map_utils->so);
	if (d->map_utils->we)
		free(d->map_utils->we);
	free(d->map_utils);
	free(d);
}
