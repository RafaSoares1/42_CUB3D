/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:12:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/08/24 19:31:12 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char *no;
	char *so;
	char *we;
	char *ea;
	int f_color[255][255][255];
	int c_color[255][255][255];
	char **color_aux;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map *map_utils;
	int		x;
	int		y;
	int		fd;
}	t_data;


//****************utils.c********************
void	ft_init_stack(t_data *d);
int ft_count(char *str, char c);
void	finish_error(char *str, int i);
//****************file.c********************
void	args_in_file(t_data *d, char *file_name);
void	valid_info(t_data *d, char *line);
void	put_path(t_data *d, char *line, int flag);
void	put_rgb(t_data *d, char *line, int flag);
void	put_fc_rgb(t_data *d, int flag);
//****************free.c********************
void	free_double_pointer(char **str);

#endif