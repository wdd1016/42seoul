/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:20:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/16 20:00:13 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void			set_tex_struct(t_data *data, t_ray *ray, t_texture *tex);
static unsigned int	texture_color(t_ray *ray, t_texture *tex);

void	input_vertical_line(t_data *data, t_img *img, t_ray *ray, int i)
{
	t_texture	tex;
	int			row_idx;
	int			end_idx;
	char		*dst;

	tex.line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	row_idx = (WINDOW_HEIGHT - tex.line_height) / 2;
	if (row_idx < 0)
		row_idx = 0;
	tex.step = TEXTURE_HEIGHT / (double)(tex.line_height);
	tex.pos = (row_idx + (tex.line_height - WINDOW_HEIGHT) / 2) * tex.step;
	set_tex_struct(data, ray, &tex);
	end_idx = (WINDOW_HEIGHT + tex.line_height) / 2;
	if (end_idx >= WINDOW_HEIGHT)
		end_idx = WINDOW_HEIGHT - 1;
	while (row_idx <= end_idx)
	{
		dst = img->addr + row_idx * img->size_l + i * (img->bpp / 8);
		*((unsigned int *)dst) = texture_color(ray, &tex);
		row_idx++;
	}
}

static void	set_tex_struct(t_data *data, t_ray *ray, t_texture *tex)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex->x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex->x = TEXTURE_WIDTH - tex->x - 1;
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		tex->x = TEXTURE_WIDTH - tex->x - 1;
	if (ray->side == 0 && ray->ray_dir_x >= 0)
		tex->curr_img = &(data->texture)[WEST];
	else if (ray->side == 0)
		tex->curr_img = &(data->texture)[EAST];
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		tex->curr_img = &(data->texture)[SOUTH];
	else
		tex->curr_img = &(data->texture)[NORTH];
}

static unsigned int	texture_color(t_ray *ray, t_texture *tex)
{
	int				tex_y;
	char			*tex_color;
	unsigned int	color;

	tex_y = (int)(tex->pos) & (TEXTURE_HEIGHT - 1);
	tex->pos += tex->step;
	tex_color = tex->curr_img->addr + (tex_y * tex->curr_img->size_l + \
				tex->x * (tex->curr_img->bpp / 8));
	color = *((unsigned int *)tex_color);
	if (ray->side == 1)
		color = (color >> 1) & 0b011111110111111101111111;
	return (color);
}
