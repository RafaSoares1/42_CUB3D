/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:19:40 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/04 16:14:37 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
