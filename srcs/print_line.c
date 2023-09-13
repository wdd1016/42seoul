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

static void	set_tex_step_pos_x(t_player *player, t_ray *ray, t_texture *tex);
static unsigned int	texture_color(t_data *data, t_ray *ray, t_texture *tex);

void	input_vertical_line(t_data *data, t_img *img, t_ray *ray, int i)
{
	t_texture	tex;
	int 		row_idx;
	int 		end_idx;
	char		*dst;

	tex->line_height = (int)(WINDOW_HEIGHT / ray->perpwall_dist);
	row_idx = (WINDOW_HEIGHT - tex->line_height) / 2;
    if (row_idx < 0)
		row_idx = 0;
	set_tex_pos_x(&data->player, ray, &tex);
	end_idx = (WINDOW_HEIGHT + tex->line_height) / 2;
    if (end_idx >= WINDOW_HEIGHT)
		end_idx = WINDOW_HEIGHT - 1;
	while (row_idx <= end)
	{
		dst = img->addr + (row_idx * img->size_l + i * (img->bpp / 8));
		*((unsigned int *)dst) = texture_color(data, ray, &tex);
		row_idx++;
	}
}

static void	set_tex_step_pos_x(t_player *player, t_ray *ray, t_texture *tex)
{
	double	wall_x;

	tex->step = TEXTURE_HEIGHT / (double)(tex->line_height);
	tex->pos = (row_idx + (tex->line_height - WINDOW_HEIGHT) / 2) * tex->step;
	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex->x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex->x = TEXTURE_WIDTH - tex->x - 1;
	else if (side == 1 && ray->ray_dir_y < 0)
		tex->x = TEXTURE_WIDTH - tex->x - 1;
}

static unsigned int	texture_color(t_data *data, t_ray *ray, t_texture *tex)
{
	int				tex_y;
	t_img			*curr_tex;
	unsigned int	color;

	tex_y = (int)(tex->pos) & (TEXTURE_HEIGHT - 1);
	tex->pos += tex->step;
	if (ray->side == 0 && ray->ray_dir_x >= 0)
		curr_tex = &(data->texture)[WEST];
	else if (ray->side == 0)
		curr_tex = &(data->texture)[EAST];
	else if (ray->side == 1 && ray->ray_dir_y >= 0)
		curr_tex = &(data->texture)[SOUTH];
	else
		curr_tex = &(data->texture)[NORTH];
	color = ((unsigned int *)(curr_tex->addr))[TEXTURE_HEIGHT * tex->x + tex_y];
	if (ray->side == 1)
		color = (color >> 1) & 0b011111110111111101111111;
	return (color);
}

