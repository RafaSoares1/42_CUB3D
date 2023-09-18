/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:12:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/09/18 14:58:03 by emsoares         ###   ########.fr       */
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
# include <math.h>
# define HEIGHT 1080
# define WIDTH 1920
# define WALL 0xffffff
# define FLOOR 0x000000
# define GRID 0x838589
# define PLAYER 0xfffb00
# define SIZE 50
# define PLAYER_SIZE 7


typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp; //bits per pixel
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_map
{
	char	**map;
	char	**map_dup;
	char 	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		flag_c;
	int		flag_f;
	char	player_pos;
	char	**f_color;
	char	**c_color;
	char	**color_aux;
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
	t_image *img;
	float	p_y;
	float	p_x;
	float	dir_x;
	float	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			mapx;
	int			mapy;
	int		x;
	int		y;
	int		fd;
	int		temp_fd;
	int		i;
}	t_data;


//****************init.c*********************
void	ft_init_stack(t_data *d);
void	ft_init_stack2(t_data *d);
void	ft_init_stack3(t_data *d);

//****************utils.c********************
int 	ft_count(char *str, char c);
void	finish_error(char *str, int i);
int		ft_search(char *str, char c);
int		ft_count_lines(t_data *d);

//****************utils2.c********************
void	ft_map_dup(t_data *d);


//****************file.c********************
void	args_in_file(t_data *d, char *file_name);
int		valid_info(t_data *d, char *line);
int		valid_info1(t_data *d, char *line);
int		valid_info2(t_data *d, char *line);
void	error_dup_elem(t_data *d, char *line);

//****************file2.c********************
void	error_in_elem(t_data *d, char *line);
void	put_path(t_data *d, char *line, int flag);

//****************free.c********************
void	free_double_pointer(char **str);
void	ft_free_game(t_data *d);
void	ft_free_game2(t_data *d);
void	ft_no_leak(t_data *d, char *line);
void	ft_no_leak2(t_data *d, char *line);


//***************main.c*********************
int		main(int ac, char **av);
void	ft_check_map_file(t_data *d, char *file_name);

//***************rgb_utils.c******************
void	put_rgb(t_data *d, char *line, int flag);
void	put_fc_rgb(t_data *d, int flag, char *line);
int		ft_check_next_comma(char *line);
int		ft_verify_digits(char *str);

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
int		strlength(char *str);

//***************check.c***********************
void	check_letters(t_data *d);
void	put_player_pos(t_data *d, int y, int x);
void	handle_invalid_input(t_data *d);
int		check_flood_fill(t_data *d, char **map, int x, int y);

//***************game.c***********************
void	start_game(t_data *d);
void	draw_minimap(t_data *d);
void	draw_grid(int x, int y, int color, t_data *d);
void	draw_square(int x, int y, int color, t_data *d);
void	draw_player(int x, int y, int color, t_data *d);
int	game_loop(t_data *d);
void	draw_raycast(t_data *d);
void	draw_floor_celling(t_data *d);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//***************close_window.c***********************
int	ft_xbutton(t_data *d);

//***************move.c***********************
int	handle_input(int keysym, t_data *d);
void	ft_move_player(t_data *d, int y, int x);
#endif