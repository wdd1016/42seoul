/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/24 21:05:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	init_img(t_img *img, t_data *data, int width, int height);
static void	player_init(t_data *data);
static void	door_init(t_data *data);
static void	sprite_init(t_data *data);

void	data_mlx_init(t_data *data)
{
	int	i;

	data->map = 0;
	data->tempmap = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->mouse_mode_flag = FALSE;
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit("Error : mlx_init failed\n", data);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!data->win)
		error_exit("Error : mlx_new_window failed\n", data);
	init_img(&data->img, data, WINDOW_WIDTH, WINDOW_HEIGHT);
	i = 0;
	while (i <= EAST)
		init_img(&data->texture[i++], data, WALL_WIDTH, WALL_HEIGHT);
	init_img(&data->texture[i++], data, DOOR_WIDTH, DOOR_HEIGHT);
	while (i < NUM_TEXTURES)
		init_img(&data->texture[i++], data, SPRITE_WIDTH, SPRITE_HEIGHT);
	player_init(data);
	door_init(data);
	sprite_init(data);
}

static void	init_img(t_img *img, t_data *data, int width, int height)
{
	img->img = mlx_new_image(data->mlx, width, height);
	if (!img->img)
		error_exit("Error : mlx_new_image failed\n", data);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
	if (!img->addr)
		error_exit("Error : mlx_get_data_addr failed\n", data);
}

static void	player_init(t_data *data)
{
	data->player.x = 0.0;
	data->player.y = 0.0;
	data->player.dir_x = 0.0;
	data->player.dir_y = 0.0;
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.0;
	data->player.walk_speed = WALK_SPEED;
	data->player.turn_speed = TURN_SPEED;
	data->minimap_height = ceil(WINDOW_HEIGHT * MINIMAP_SCALE);
	data->minimap_width = ceil(WINDOW_WIDTH * MINIMAP_SCALE);
}

static void	door_init(t_data *data)
{
	int	i;

	i = 0;
	data->num_doors = 0;
	while (i < DOOR_SIZE)
	{
		(data->door[i]).x = -1;
		(data->door[i]).y = -1;
		i++;
	}
}

static void	sprite_init(t_data *data)
{
	int	i;

	i = 0;
	data->num_sprites = 0;
	while (i < SPRITE_SIZE)
	{
		data->sprite[i].x = -1.0;
		data->sprite[i].y = -1.0;
		data->sprite[i].dist = -1.0;
		i++;
	}
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		data->z_buffer[i] = -1.0;
		i++;
	}
}
