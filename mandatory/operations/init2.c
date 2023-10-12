/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:25 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/12 14:52:36 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct_imgs(t_data *d)
{
	d->img = ft_calloc(1, sizeof(t_image));
	d->n_img = ft_calloc(1, sizeof(t_image));
	d->s_img = ft_calloc(1, sizeof(t_image));
	d->w_img = ft_calloc(1, sizeof(t_image));
	d->e_img = ft_calloc(1, sizeof(t_image));
	if (!check_access(d))
		error_handling2(d, "Error: A certain texture is not valid!\n");
}

int	check_access(t_data *d)
{
	int	fd[4];

	fd[0] = open(d->map_utils->no, O_RDONLY);
	fd[1] = open(d->map_utils->so, O_RDONLY);
	fd[2] = open(d->map_utils->we, O_RDONLY);
	fd[3] = open(d->map_utils->ea, O_RDONLY);
	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1] > 0)
		close(fd[1]);
	if (fd[2] > 0)
		close(fd[2]);
	if (fd[3] > 0)
		close(fd[3]);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0)
		return (0);
	return (1);
}
