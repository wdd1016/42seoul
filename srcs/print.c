/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:20:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/13 00:00:58 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	input_background(t_data *data);
static void	set_ray(t_player *player, t_ray *r, double camera_i);
static void	digital_differential_analyzer(t_data *data, t_ray *ray);
static void	set_perp_wall_dist(t_player *p, t_ray *ray, int map_x, int map_y);

int	print_image(t_data *data)
{
	t_ray	ray;
	int		i;

	input_background(data);
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		set_ray(&data->player, &ray, 2 * (double)i / (WINDOW_WIDTH - 1) - 1);
		digital_differential_analyzer(data, &ray);
		input_vertical_line(data, &ray, i);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	input_background(t_data *data)
{
	int		color;
	char	*dst;
	int		i;

	dst = data->img.addr;
	color = data->ceiling_color;
	i = 0;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT / 2)
	{
		*(unsigned int *)dst = color;
		dst += data->img.bpp / 8;
		i++;
	}
	color = data->floor_color;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		*(unsigned int *)dst = color;
		dst += data->img.bpp / 8;
		i++;
	}
}

static void	set_ray(t_player *player, t_ray *r, double camera_i)
{
	r->ray_dir_x = player->dir_x + player->plane_x * camera_i;
	r->ray_dir_y = player->dir_y + player->plane_y * camera_i;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (player->x - (int)player->x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = ((int)player->x + 1.0 - player->x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (player->y - (int)player->y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = ((int)player->y + 1.0 - player->y) * r->delta_dist_y;
	}
}

static void	digital_differential_analyzer(t_data *data, t_ray *ray)
{
	int	map_x;
	int	map_y;

	map_x = (int)(data->player.x);
	map_y = (int)(data->player.y);
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[map_y][map_x] > 0)
			break;
	}
	set_perp_wall_dist(&data->player, ray, map_x, map_y);
}

static void	set_perp_wall_dist(t_player *p, t_ray *ray, int map_x, int map_y)
{
	if (ray->side == 0)
		ray->perp_wall_dist = \
		(map_x - p->x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = \
		(map_y - p->y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}
