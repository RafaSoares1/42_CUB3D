/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/09/20 12:18:39 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_game(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	d->img = ft_calloc(1, sizeof(t_image));
	ft_init_stack3(d);
	d->img->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp, &d->img->line_length, &d->img->endian);
	//draw_minimap(d);
	//mlx_hook(d->win_ptr, KeyPress, KeyPressMask, ft_keypress, &mlx);

	mlx_hook(d->win_ptr, KeyPress, KeyPressMask, handle_input, d);
	mlx_hook(d->win_ptr, DestroyNotify, ButtonPressMask, ft_xbutton, d);
	mlx_loop_hook(d->mlx_ptr, game_loop, d);
	mlx_loop(d->mlx_ptr);
}

int	game_loop(t_data *d)//funcao principal para renders
{
	draw_raycast(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
	return (0);
}

void	draw_raycast(t_data *d)
{
	int color;
	draw_floor_celling(d);
	//Position of the Player in d->p_y and p_x;
	if(d->map_utils->player_pos == 'N')
	{
		d->dir_x = 0, d->dir_y = -1;//initial direction vector = NORTH
		d->plane_x = 0.66, d->plane_y = 0;
	}
	if(d->map_utils->player_pos == 'S')
	{
		d->dir_x = 0, d->dir_y = 1;//initial direction vector = SOUTH
		d->plane_x = -0.66, d->plane_y = 0;
	}
	if(d->map_utils->player_pos == 'E')
	{
		d->dir_x = 1, d->dir_y = 0;//initial direction vector = EAST
		d->plane_x = 0, d->plane_y = 0.66;
	}
	if(d->map_utils->player_pos == 'W')
	{
		d->dir_x = -1, d->dir_y = 0;//initial direction vector = WEST
		d->plane_x = 0, d->plane_y = -0.66;
	}

/* Camera Plane: In addition to the direction, you need to define the camera plane.
The camera plane is like a flat surface that the player sees.
It's always perpendicular (at a right angle) to the direction the player is looking, but you can change how wide it is.
This width determines how much the player can see. In the code, planeX is set to 0 (horizontal direction),
and planeY is set to 0.66 (vertical direction). This creates a specific field of view (FOV) for the player,
which is similar to a flashlight beam. */
//-----------------------------------------------------------------------

	d->i = 0;
	while(d->i < WIDTH)
	{
		d->camera_x = 2 * d->i / (double)WIDTH - 1;
		d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
		d->raydir_y = d->dir_y + d->plane_y * d->camera_x;

/* Here starts the actual raycasting. calculation for every vertical stripe.
The ray starts at the position of the player (posX, posY).

Imagine you're looking at a computer screen, and you want to know where on the screen you are currently focusing.
cameraX helps in this by assigning a value to each column of the screen. If cameraX is -1, you're looking at the far left side of the screen,
and if it's 1, you're looking at the far right side. If it's 0, you're looking straight ahead at the center.
So, in essence, cameraX helps the code understand where your character is aiming or looking within the game world, making it possible to
calculate the direction of rays for each column on the screen.

rayDirX and rayDirY represent the direction of the ray in the game world. They are calculated by combining the player's direction vector (dirX and dirY)
with a part of the plane vector (planeX and planeY) scaled by cameraX. This step determines where the ray is pointing in the game world.
*/

//----------------------------------------------------------------------

		d->mapx = (int)d->p_x;
		d->mapy = (int)d->p_y;
		if (d->raydir_x == 0)
			d->delta_dist_x = 1e30;
		else
			d->delta_dist_x = fabs(1 / d->raydir_x);
		if (d->raydir_y == 0)
			d->delta_dist_y = 1e30;
		else
			d->delta_dist_y = fabs(1 / d->raydir_y);
		d->hit = 0;

/* mapX and mapY represent the box or grid cell of the map that your character (or the ray) is currently inside.  

sideDistX and sideDistY are used to keep track of the distance from the current position
to the next vertical or horizontal grid boundary (side of a wall).

deltaDistX and deltaDistY represent the length of the ray that needs to be traveled to move from one grid boundary to the next.
These values are used to calculate how far the ray should move horizontally or vertically before reaching the next grid boundary.
The code checks if rayDirX or rayDirY is zero to avoid division by zero.
If rayDirX is indeed equal to zero (meaning the ray is traveling perfectly vertically), the code sets deltaDistX to a very large value, 1e30.
This effectively means that the ray will travel a virtually infinite distance horizontally before reaching the next grid boundary.
This is done to avoid division by zero, which would occur if rayDirX is zero.

perpWallDist will be used to store the final distance from the player to the nearest wall.
It's calculated based on the previous values

stepX and stepY determine the direction in which the ray should move horizontally and vertically.
They can have values of either +1 or -1, indicating whether the ray is moving to the right or left, or up or down.

hit is a flag variable that is initially set to 0, indicating that there has been no wall hit.
It will be used later to check if the ray has hit a wall.

side is used to determine whether the ray hit a north-south (NS == 1) wall or an east-west (EW == 0) wall.
It's initialized but will be set later based on the direction of the first wall hit.

*/
//----------------------------------------------------------------------
		if (d->raydir_x < 0)
		{
			d->stepx = -1;
			d->side_dist_x = (d->p_x - d->mapx) * d->delta_dist_x;
		}
		else
		{
			d->stepx = 1;
			d->side_dist_x = (d->mapx + 1.0 - d->p_x) * d->delta_dist_x;
		}
		if (d->raydir_y < 0)
		{
			d->stepy = -1;
			d->side_dist_y = (d->p_y - d->mapy) * d->delta_dist_y;
		}
		else
		{
			d->stepy = 1;
			d->side_dist_y = (d->mapy + 1.0 - d->p_y) * d->delta_dist_y;
		}

/* If rayDirX (the x-component of the ray's direction) is negative, it means the ray is pointing to the left in the game world.
	In this case, stepX is set to -1, indicating that the ray will move to the left.	
	sideDistX is calculated as the distance from the player's current x-position (posX) to the left side of the grid cell (mapX) multiplied by deltaDistX.
	This calculates how far the ray needs to travel horizontally to reach the left side of the grid cell.

	If rayDirX is not negative (i.e., it's positive or zero), it means the ray is pointing to the right in the game world.
    In this case, stepX is set to 1, indicating that the ray will move to the right.
    sideDistX is calculated as the distance from the right side of the grid cell (mapX + 1.0) to the player's current x-position (posX) multiplied by deltaDistX.
	This calculates how far the ray needs to travel horizontally to reach the right side of the grid cell.

*/
//----------------------------------------------------------------------------
		while (!d->hit)
		{
			if ( d->side_dist_x < d->side_dist_y)
			{
				d->side_dist_x += d->delta_dist_x;
				d->mapx += d->stepx;
				d->side = 0;
			}
			else
			{
				d->side_dist_y += d->delta_dist_y;
				d->mapy += d->stepy;
				d->side = 1;
			}
			if (d->map_utils->map[d->mapy][d->mapx] == '1')
				d->hit = 1;
		}

/*it keeps track of whether the ray has hit a wall or not.
Inside the loop, the code decides whether to move the ray horizontally (in the x-direction) or vertically (in the y-direction) to the next grid square (map square).
It does this by comparing the distances to the next horizontal grid boundary (sideDistX) and the next vertical grid boundary (sideDistY).

If sideDistX is smaller than sideDistY, it means the next horizontal grid boundary is closer.
So, the code updates sideDistX by adding deltaDistX, moves to the next horizontal grid square (mapX += stepX), and sets side to 0 to indicate that the ray is moving horizontally

If sideDistY is smaller than or equal to sideDistX, it means the next vertical grid boundary is closer.
So, the code updates sideDistY by adding deltaDistY, moves to the next vertical grid square (mapY += stepY), and sets side to 1 to indicate that the ray is moving vertically.

Checking if the Ray Hits a Wall: After jumping to the next grid square, the code checks if the ray has hit a wall

In easy terms, this piece of code repeatedly moves the ray from one grid square to the next, either horizontally or vertically, depending on which boundary (side) is closer.
t keeps doing this until the ray hits a wall (as determined by the worldMap) or until it has explored all relevant grid squares along its path.
This process is essential for tracing the ray's path and finding where it intersects with walls in the game world.

*/
//-----------------------------------------------------------------------------------
		if (d->side == 0)
			d->perp_wall_dist = (d->side_dist_x - d->delta_dist_x);
		else
			d->perp_wall_dist = (d->side_dist_y - d->delta_dist_y);

/* depending on whether the ray hits a vertical or horizontal wall (d->side), this code calculates the distance from the player to the wall.
If d->side is 0 (indicating a vertical wall), it calculates perp_wall_dist as the difference between d->side_dist_x and d->delta_dist_x.
If d->side is 1 (indicating a horizontal wall), it calculates perp_wall_dist as the difference between d->side_dist_y and d->delta_dist_y. */
		if (d->perp_wall_dist)
			d->line_height = (int)(HEIGHT / d->perp_wall_dist);
		else
			d->line_height = HEIGHT;
/*line_height is determined by dividing the height of the screen (HEIGHT) by perp_wall_dist.
This represents how tall the wall should appear on the screen.
The closer the wall, the taller it appears. */
		d->draw_start = -d->line_height / 2 + HEIGHT / 2;
		if (d->draw_start < 0)
			d->draw_start = 0;
		d->draw_end = d->line_height / 2 + HEIGHT / 2;
/*draw_start is calculated as half of the screen height (HEIGHT) minus half of the line_height. This ensures that the wall is drawn from the center of the screen upward.
draw_end is calculated as half of the screen height plus half of the line_height. This ensures that the wall is drawn from the center of the screen downward.*/
		if (d->draw_end >= HEIGHT)
			d->draw_end = HEIGHT - 1;

/* if draw_start is less than 0, it's set to 0 to prevent drawing above the top of the screen.
If draw_end is greater than or equal to the screen height (HEIGHT), it's set to HEIGHT - 1 to prevent drawing below the bottom of the screen. */
		if (d->side == 1)
			color = 0xffc0cb;
		else
			color = 0xfff4aa;
/* Depending on whether the ray hits a vertical or horizontal wall (d->side), a color is chosen.
If it's a vertical wall, it's set to a pinkish color; if it's a horizontal wall, it's set to a pale yellow color. */
		int j = d->draw_start;
		while (j < d->draw_end)
		{
			my_mlx_pixel_put(d, d->i, j, color);
			j++;
		}
		d->i++;
	}
}

void	draw_floor_celling(t_data *d)
{
	int	x;
	int	y;
	unsigned int f_color;
	unsigned int c_color;

	x = 0;
	y = 0;
	f_color = (0x010000 * ft_atoi(d->map_utils->f_color[0])) + (0x000100 * ft_atoi(d->map_utils->f_color[1])) + ft_atoi(d->map_utils->f_color[2]);
	c_color = 0x010000 * ft_atoi(d->map_utils->c_color[0]) + 0x000100 * ft_atoi(d->map_utils->c_color[1]) + ft_atoi(d->map_utils->c_color[2]);
	while(x < WIDTH)
	{
		y = 0;
		while(y < HEIGHT)
		{
			if (y <= (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, c_color);
			if(y > (HEIGHT / 2))
				my_mlx_pixel_put(d, x, y, f_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
	*(unsigned int*)dst = color;
}


void draw_grid(int x, int y, int color, t_data *d)
{
	int	i;
	int	j;

	i = x;
	while(i < x + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, y, color);
		i++;
	}
	i = x;
	while(i < x + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, y + SIZE - 1, color);
		i++;
	}
	j = y;
	while(j < y + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, j, color);
		j++;
	}
	j = y;
	while(j < y + SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x + SIZE - 1, j, color);
		j++;
	}
}

void	draw_minimap(t_data *d)
{
	int y = 0;
	int	x = 0;

	while (y < d->count_lines)
	{
		x = 0;
		while (d->map_utils->map[y][x])
		{
			if (d->map_utils->map[y][x] == '1')
			{
				draw_square(x * 50, (y - 1) * 50, WALL, d);
				draw_grid(x * 50, (y - 1) * 50, GRID, d);
			}
			if (d->map_utils->map[y][x] == '0')
			{
				draw_square(x * 50, (y - 1) * 50, FLOOR, d);
				draw_grid(x * 50, (y - 1) * 50, GRID, d);
			}
			if (d->map_utils->map[y][x] == 'N') //falta S, E e W
			{
				draw_square(x * 50, (y - 1) * 50, FLOOR, d);
				draw_grid(x * 50, (y - 1) * 50, GRID, d);
				draw_player((x * 50) + (SIZE / 2), ((y - 1) * 50) + (SIZE / 2), PLAYER, d);
			}
			x++;
		}
	y++;
	}
}

void draw_square(int x, int y, int color, t_data *d)
{
	int	i;
	int	j;

	i = x;
	while(i < x + SIZE)
	{
		j = y;
		while(j < y + SIZE)
		{
			mlx_pixel_put(d->mlx_ptr,d->win_ptr, i, j, color);
			j++;
		}
		i++;
	}
}

void draw_player(int x, int y, int color, t_data *d)
{
	int	j;

	j = 1;
	put_player_pos(d, y, x);
	mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, y, color);
	while(j < PLAYER_SIZE)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x + j, y, color);
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x - j, y, color);
		j++;
	}
	j = 1;
	while(j < PLAYER_SIZE + 5)
	{
		mlx_pixel_put(d->mlx_ptr,d->win_ptr, x, y - j, color);
		j++;
	}
}