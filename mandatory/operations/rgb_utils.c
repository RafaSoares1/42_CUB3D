/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:25:50 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/29 15:25:50 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_rgb(t_data *d, char *line, int flag)
{
	int	i;

	i = 0;
	d->map_utils->color_aux = ft_split(line + 2, ',');
	if (ft_count(line, ',') != 2 || ft_check_next_comma(line) == 1)
		error_handling(line, d, "Error: Wrong number of color values!\n");
	while (i < 3)
	{
		if (ft_verify_digits(d->map_utils->color_aux[i], i))
			error_handling(line, d, "Error: Wrong value in RGB!\n");
		if (!(ft_atoi(d->map_utils->color_aux[i]) >= 0
				&& ft_atoi(d->map_utils->color_aux[i]) <= 255))
			error_handling(line, d, "Error: Wrong value in RGB!\n");
		i++;
	}
	if (flag == 1)
		put_fc_rgb(d, flag, line);
	else if (flag == 2)
		put_fc_rgb(d, flag, line);
	free_double_pointer(d->map_utils->color_aux);
}

void	put_fc_rgb(t_data *d, int flag, char *line)
{
	char	*temp;

	temp = 0;
	if (flag == 1)
	{
		temp = ft_strtrim(line, " \t\n");
		d->map_utils->f_color = ft_split(temp + 2, ',');
		d->map_utils->flag_f = 1;
	}
	else if (flag == 2)
	{
		temp = ft_strtrim(line, " \t\n");
		d->map_utils->c_color = ft_split(temp + 2, ',');
		d->map_utils->flag_c = 1;
	}
	if (temp)
		free(temp);
}

int	ft_check_next_comma(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			if (!ft_isdigit(line[i - 1]) || !ft_isdigit(line[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_verify_digits(char *str, int position)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] != ' ' && str[i] != '\t'))
		{
			if (ft_isalpha(str[i]))
				return (1);
			if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
				return (1);
			if (position != 2 && ft_isdigit(str[i]) && (!ft_isdigit(str[i + 1])
					&& (str[i + 1] != '\0' && str[i + 1] != '\n')))
				return (1);
		}
		if (position == 2 && (str[i] == ' ' || str[i] == '\t'))
			return (check_for_spaces(str + i));
		i++;
	}
	return (0);
}

int	check_for_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		return (1);
	return (0);
}
