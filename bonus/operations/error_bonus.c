/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:19:40 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/09 10:41:05 by jomirand         ###   ########.fr       */
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
