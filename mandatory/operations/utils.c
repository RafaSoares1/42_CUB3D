/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:32:39 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/10 15:03:39 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	finish_error(char *str, int i)
{
	ft_putstr_fd(str, i);
	exit (i);
}

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_lines(t_data *d)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(d->fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free (str);
	close(d->fd);
	return (i + 2);
}

int	string_comp(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2) && !ft_strncmp(s1, s2, ft_strlen(s2)))
		return (1);
	return (0);
}
