/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:06:31 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/04 19:41:33 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACRO_H
# define CUB3D_MACRO_H

# define NUM_TEXTURES 4

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define TILE_SIZE 64

# define MAP_MAX_ROWS 50
# define MAP_MAX_COLS 28

# define WINDOW_WIDTH 3200
# define WINDOW_HEIGHT 1792

# define SUCCESS 0
# define FAILURE 1
# define FALSE 0
# define TRUE 1
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define FLOOR 4
# define CEILING 5

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

# define FOV_ANGLE (60 * (M_PI / 180))
# define NUM_RAYS WINDOW_WIDTH

# define MINIMAP_SCALE_FACTOR 0.3

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

# define PI 3.1415926535

typedef struct s_img
{
	void	*img;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	width;
	double	height;
	double	direction;
	double	walk_speed;
	double	turn_speed;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
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
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_sprite
{
	double	x;
	double	y;
	double	distance;
}	t_sprite;

typedef struct s_sprite_cast
{
	double	sprite_x;
	double	sprite_y;
	double	transform_x;
	double	transform_y;
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
	int			map[MAP_MAX_ROWS][MAP_MAX_COLS];
	t_player	player;
	t_ray		rays[NUM_RAYS];
	t_texture	texture[NUM_TEXTURES];
	int			floor_color;
	int			ceiling_color;
	double		*z_buffer;
}	t_data;

#endif