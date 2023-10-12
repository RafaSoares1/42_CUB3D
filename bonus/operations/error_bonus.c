/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:19:40 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/12 14:52:21 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	error_handling(char *line, t_data *d, char *str)
{
	free(line);
	ft_no_leak2(d, line);
	ft_free_game2(d);
	finish_error(str, 2);
}

void	error_handling2(t_data *d, char *str)
{
	ft_free_game6(d);
	finish_error(str, 2);
}

void	no_tab_error_handle(t_data *d)
{
	free(d->line);
	close(d->fd);
	close(d->temp_fd);
	ft_no_leak(d, d->line);
	ft_free_game(d);
	finish_error("Error\nProgram does not suport tabs\n", 2);
}

void	file_name_error(t_data *d)
{
	free(d->map_utils);
	free(d);
	finish_error("Error\nInvalid file type\n", 2);
}
