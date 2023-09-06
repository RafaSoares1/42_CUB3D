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
	d->map_dup = ft_calloc(d->lines + 1, sizeof(char *));
	while (i < d->lines)
	{
		d->map_dup[i] = ft_strdup(d->map[i]);
		i++;
	}
}
