/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:25 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/03 14:54:55 by emsoares         ###   ########.fr       */
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
}
