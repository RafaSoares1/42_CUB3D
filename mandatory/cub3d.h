/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:12:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/10/04 12:32:16 by jomirand         ###   ########.fr       */
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
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}	t_image;

typedef struct s_map
{
	char	**map;
	char	**map_dup;
	char	*no;
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
	t_map	*map_utils;
	t_image	*img;
	t_image	*aux;
	t_image	*n_img;
	t_image	*s_img;
	t_image	*w_img;
	t_image	*e_img;
	float	p_y;
	float	p_x;
	double	dir_x;
	double	dir_y;
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
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		mapx;
	int		mapy;
	int		wall_dir;
	int		x;
	int		y;
	int		fd;
	int		temp_fd;
	int		i;
	int		a;
	int		b;
	int		key_press_up;
	int		key_press_down;
	int		key_press_left;
	int		key_press_right;
	int		key_press_r_right;
	int		key_press_r_left;
	int		tab_count;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	text_step;
	double	text_pos;
}	t_data;

//****************init.c*********************
void	ft_init_stack(t_data *d);
void	ft_init_stack1(t_data *d);
void	ft_init_stack2(t_data *d);
void	ft_init_stack3(t_data *d);
void	ft_init_stack4(t_data *d);

//****************init2.c*********************
void	init_struct_imgs(t_data *d);

//****************utils.c********************
int		ft_count(char *str, char c);
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
void	ft_free_game(t_data *d);
void	ft_free_game2(t_data *d);
void	ft_free_game3(t_data *d);
void	ft_no_leak(t_data *d, char *line);
void	ft_no_leak2(t_data *d, char *line);

//****************free2.c********************
void	free_double_pointer(char **str);
void	ft_free_game4(t_data *d);
void	ft_free_game5(t_data *d);

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
int		strlength(char *str);
void	map_to_file2(t_data *d);
void	map_to_matrix(t_data *d);
void	ft_fill_map_index(t_data *d);

//***************map_utils2.c*****************
char	*fill_matrix_line(t_data *d, char *str);
char	*fill_matrix_line2(char *line, char *str, int *i, int *j);
void	fill_rest(t_data *d);
void	print_matrix(t_data *d);
void	put_first_last(t_data *d);

//***************check.c***********************
void	check_letters(t_data *d);
void	check_letters2(t_data *d, char c);
void	put_player_pos(t_data *d, int y, int x);
void	handle_invalid_input(t_data *d);
int		check_flood_fill(t_data *d, char **map, int x, int y);

//***************check2.c***********************
void	ft_check_textures(t_data *d);
void	ft_check_textures2(t_data *d);

//***************game.c***********************
void	start_game(t_data *d);
int		game_loop(t_data *d);
void	draw_raycast(t_data *d);
void	draw_floor_celling(t_data *d);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//***************game2.c***********************
void	ray_calc(t_data *d);
void	check_side(t_data *d);
void	get_hit(t_data *d);
void	ray_values(t_data *d);
void	get_texture_val(t_data *d);

//**************game3.c**************************
void	draw_floor_celling2(t_data *d, int f_color, int c_color);

//***************direction.c***********************
void	direction(t_data *d);
void	direction2(t_data *d);

//***************movement.c********************
int		ft_movs(t_data *d);
void	move_vertical(t_data *d, int dir_flag);
void	move_horizontal(t_data *d, int dir_flag);
void	rotate_player(t_data *d, int dir_flag);

//***************minimap.c***********************
void	draw_minimap(t_data *d);
void	draw_grid(int x, int y, int color, t_data *d);
void	draw_square(int x, int y, int color, t_data *d);
void	draw_player(int x, int y, int color, t_data *d);

//***************close_window.c***********************
int		ft_xbutton(t_data *d);

//***************key_handle.c***********************
int		handle_input(int keysym, t_data *d);
int		release_key(int keysym, t_data *d);
void	ft_move_player(t_data *d, int y, int x);

//**************error.c***********************
void	error_handling(char *line, t_data *d, char *str);

//**************xpm_files.c*******************
void	get_imgs_xpm(t_data *d);

//**************draw.c************************
void	ft_draw(t_data *d, int i);
void	get_wall_x(t_data *d);
int		ft_get_pixel(t_data *d, int x, int y);
#endif