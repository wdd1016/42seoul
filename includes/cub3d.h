/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:27:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 15:41:02 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "utils.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20
# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANGLE (60 * (M_PI / 180))
# define NUM_RAYS WINDOW_WIDTH

# define MINIMAP_SCALE_FACTOR 0.3

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define NUM_TEXTURES 5

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

# define PI 3.1415926535

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}	t_player;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		wall_hit_content;
}	t_ray;

typedef struct s_texture
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
}	t_sprite;

typedef struct s_sprite_cast
{
	float	sprite_x;
	float	sprite_y;
	float	transform_x;
	float	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
}	t_sprite_cast;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			map[MAP_NUM_ROWS][MAP_NUM_COLS];
	t_player	player;
	t_ray		rays[NUM_RAYS];
	t_texture	texture[NUM_TEXTURES];
	int			num_sprites;
	t_sprite	*sprite;
	float		*z_buffer;
}	t_data;

void	ft_map_parsing(char *path, t_data *data);
void	ft_mlx_init(t_data *data);
void	ft_set_hooks(t_data *data);
void	ft_print_image(t_data *data);

#endif