/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:12:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/06 17:43:25 by emsoares         ###   ########.fr       */
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
# define SIZE 45

typedef struct s_map
{
	char	**map;
	char *no;
	char *so;
	char *we;
	char *ea;
	char **f_color;
	int		flag_c;
	int		flag_f;
	char	player_pos;
	char **c_color;
	char **color_aux;
	int		skip_count;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*line;
	int		count_lines;
	int		line_length;
	t_map *map_utils;
	int		x;
	int		y;
	int		fd;
	int		temp_fd;
	int		i;
}	t_data;


//****************utils.c********************
void	ft_init_stack(t_data *d);
int 	ft_count(char *str, char c);
void	finish_error(char *str, int i);
int		ft_search(char *str, char c);
int		ft_count_lines(t_data *d);

//****************utils2.c********************
void	ft_map_dup(t_data *d);

//****************file.c********************
void	args_in_file(t_data *d, char *file_name);
void	valid_info(t_data *d, char *line);
void	valid_info2(t_data *d, char *line);
void	put_path(t_data *d, char *line, int flag);

//****************free.c********************
void	free_double_pointer(char **str);
void	ft_free_game(t_data *d);
void	ft_no_leak(t_data *d, char *line);


//***************main.c*********************
int		main(int ac, char **av);
void	ft_check_map_file(t_data *d, char *file_name);

//***************rgb_utils.c******************
void	put_rgb(t_data *d, char *line, int flag);
void	put_fc_rgb(t_data *d, int flag, char *line);

//***************map_utils.c*******************
void	map_to_file(t_data *d, char *file_name);
void	map_to_file2(t_data *d);
void	map_to_matrix(t_data *d);
void	ft_fill_map_index(t_data *d);
void	put_first_last(t_data *d);

//***************map_utils2.c*****************
char	*fill_matrix_line(t_data *d, char *str);
void	fill_rest(t_data *d);
void	print_matrix(t_data *d);

//***************check.c***********************
void	check_letters(t_data *d);
void	handle_invalid_input(t_data *d);

#endif