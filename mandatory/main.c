/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:11:55 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/28 16:42:18 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_file(t_data *d, char *file_name)
{
	int	i;

	i = 0;
	d->fd = open(file_name, O_RDONLY);
	i = ft_strlen(file_name) - 1;
	while (file_name[i] != '.')
		i--;
	if (ft_strncmp((file_name + i), ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file type\n", 2);
		close(d->fd);
		exit(1);
	}
	if (d->fd < 0)
	{
		ft_putstr_fd("Error\nInvalid FD\n", 2);
		close(d->fd);
		exit(1);
	}
	close(d->fd);
	d->fd = 0;
	args_in_file(d, file_name);
}

int main(int ac, char **av)
{
	t_data *game;
	(void)av;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nCheck the input-->./Cub3D <Map path>\n", 2);
		return (0);
	}
	game = malloc(sizeof(t_data));
	game->map_utils = malloc(sizeof(t_map));
	ft_init_stack(game);
	if (ac == 2)
	{
		ft_check_map_file(game, av[1]);
		ft_printf("passou");
		ft_free_game(game);
	}
	free(game->map_utils);
	free(game);
	return (0);
}
