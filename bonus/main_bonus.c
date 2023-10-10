/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:11:55 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/10 12:29:25 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_null_file(t_data *d, char *file_name)
{
	char	*line;

	d->fd = open(file_name, O_RDONLY);
	line = get_next_line(d->fd);
	if (!line)
	{
		ft_free_game(d);
		finish_error("Error: no content on file\n", 2);
	}
	free(line);
	ft_no_leak2(d, line);
}

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
		close(d->fd);
		free(d->map_utils);
		free(d);
		finish_error("Error\nInvalid file type\n", 2);
	}
	if (d->fd < 0)
	{
		close(d->fd);
		free(d->map_utils);
		free(d);
		finish_error("Error\nInvalid FD\n", 2);
	}
	close(d->fd);
	d->fd = 0;
	check_null_file(d, file_name);
	args_in_file(d, file_name);
}

int	main(int ac, char **av)
{
	t_data	*game;

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
		start_game(game);
		ft_free_game2(game);
	}
	return (0);
}
