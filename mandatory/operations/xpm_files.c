/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:09:16 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/12 12:30:30 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_imgs_xpm(t_data *d)
{
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->n_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->no,
			&d->n_img->w, &d->n_img->h);
	d->s_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->so,
			&d->s_img->w, &d->s_img->h);
	d->w_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->we,
			&d->w_img->w, &d->w_img->h);
	d->e_img->img = mlx_xpm_file_to_image(d->mlx_ptr, d->map_utils->ea,
			&d->e_img->w, &d->e_img->h);
	if (!d->img->img || !d->n_img->img || !d->s_img->img
		|| !d->w_img->img || !d->e_img->img)
	{
		ft_free_game4(d);
		finish_error("Error\nInvalid texture file\n", 2);
		return ;
	}
	get_imgs_addr(d);
}

void	get_imgs_addr(t_data *d)
{
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp,
			&d->img->line_length, &d->img->endian);
	d->n_img->addr = mlx_get_data_addr(d->n_img->img, &d->n_img->bpp,
			&d->n_img->line_length, &d->n_img->endian);
	d->s_img->addr = mlx_get_data_addr(d->s_img->img, &d->s_img->bpp,
			&d->s_img->line_length, &d->s_img->endian);
	d->w_img->addr = mlx_get_data_addr(d->w_img->img, &d->w_img->bpp,
			&d->w_img->line_length, &d->w_img->endian);
	d->e_img->addr = mlx_get_data_addr(d->e_img->img, &d->e_img->bpp,
			&d->e_img->line_length, &d->e_img->endian);
}
