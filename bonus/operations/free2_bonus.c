/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:59:06 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/21 18:59:06 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_double_pointer(char **str)
{
	int	i;

	i = 0;
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

void	ft_free_game4(t_data *d)
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
	ft_free_game5(d);
	free(d->map_utils);
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	free(d);
}

void	ft_free_game5(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->n_img->img);
	mlx_destroy_image(d->mlx_ptr, d->s_img->img);
	mlx_destroy_image(d->mlx_ptr, d->w_img->img);
	mlx_destroy_image(d->mlx_ptr, d->e_img->img);
	free(d->n_img);
	free(d->s_img);
	free(d->w_img);
	free(d->e_img);
	mlx_destroy_image(d->mlx_ptr, d->img->img);
	free(d->img);
}

void	ft_free_game6(t_data *d)
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
	ft_free_game7(d);
	free(d->map_utils);
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	free(d);
}

void	ft_free_game7(t_data *d)
{
	free(d->n_img);
	free(d->s_img);
	free(d->w_img);
	free(d->e_img);
	free(d->img);
}
