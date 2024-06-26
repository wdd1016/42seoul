/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macro_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:06:31 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/24 21:43:55 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACRO_BONUS_H
# define CUB3D_MACRO_BONUS_H

# define WALK_SPEED 0.25
# define TURN_SPEED 0.125

# define NUM_TEXTURES 9

# define WALL_WIDTH 64
# define WALL_HEIGHT 64
# define DOOR_WIDTH 512
# define DOOR_HEIGHT 512
# define SPRITE_WIDTH 140
# define SPRITE_HEIGHT 140
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 768

# define SUCCESS 0
# define FAILURE 1
# define FALSE 0
# define TRUE 1
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define DOOR 4
# define SP1 5
# define SP2 6
# define SP3 7
# define SP4 8
# define FLOOR 9
# define CEILING 10

# define NBIT 0b00000000001
# define SBIT 0b00000000010
# define WBIT 0b00000000100
# define EBIT 0b00000001000
# define DBIT 0b00000010000
# define S1BT 0b00000100000
# define S2BT 0b00001000000
# define S3BT 0b00010000000
# define S4BT 0b00100000000
# define FLOOR_BIT 0b01000000000
# define CEILING_BIT 0b10000000000
# define COMPLETE_BIT 0b11111111111

# define MINIMAP_SCALE 0.3
# define SPRITE_SIZE 50
# define DOOR_SIZE 50

enum e_xevent
{
	KEY_EXIT = 17,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_N = 45,
	KEY_M = 46,
	KEY_SPACE = 49,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_PRESS = 2,
	KEY_ESC = 53
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	perp_wall_dist;
	char	texture_type;
}	t_ray;

typedef struct s_texture
{
	int		line_height;
	double	step;
	double	pos;
	int		x;
	t_img	*curr_img;
}	t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	walk_speed;
	double	turn_speed;
}	t_player;

typedef struct s_map
{
	char			*line;
	int				len;
	struct s_map	*next;
}	t_map;

typedef struct s_door
{
	int	x;
	int	y;
}	t_door;

typedef struct s_sprite
{
	double	x;
	double	y;
	double	dist;
}	t_sprite;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		texture[NUM_TEXTURES];
	char		**map;
	t_map		*tempmap;
	int			map_width;
	int			map_height;
	int			minimap_width;
	int			minimap_height;
	t_player	player;
	int			floor_color;
	int			ceiling_color;
	int			mouse_mode_flag;
	t_door		door[DOOR_SIZE];
	int			num_doors;
	t_sprite	sprite[SPRITE_SIZE];
	int			num_sprites;
	double		z_buffer[WINDOW_WIDTH];
}	t_data;

#endif