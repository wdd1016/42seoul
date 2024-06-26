/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:20:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/22 16:06:28 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void			set_tex_struct(t_data *data, t_ray *ray, t_texture *tex);
static void			input_background(t_data *data, int start, int end, int i);
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
	set_tex_struct(data, ray, &tex);
	tex.step = tex.curr_img->height / (double)(tex.line_height);
	tex.pos = (row_idx + (tex.line_height - WINDOW_HEIGHT) / 2) * tex.step;
	end_idx = (WINDOW_HEIGHT + tex.line_height) / 2;
	if (end_idx >= WINDOW_HEIGHT)
		end_idx = WINDOW_HEIGHT - 1;
	input_background(data, row_idx, end_idx, i);
	while (row_idx <= end_idx)
	{
		dst = img->addr + row_idx * img->size_l + i * (img->bpp / 8);
		if (i >= data->minimap_width || row_idx >= data->minimap_height)
			*((unsigned int *)dst) = texture_color(ray, &tex);
		tex.pos += tex.step;
		row_idx++;
	}
}

static void	set_tex_struct(t_data *data, t_ray *ray, t_texture *tex)
{
	double	wall_x;

	if (ray->texture_type == '2')
		tex->curr_img = &(data->texture)[DOOR];
	else if (ray->side == 0 && ray->ray_dir_x >= 0)
		tex->curr_img = &(data->texture)[WEST];
	else if (ray->side == 0)
		tex->curr_img = &(data->texture)[EAST];
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		tex->curr_img = &(data->texture)[SOUTH];
	else
		tex->curr_img = &(data->texture)[NORTH];
	if (ray->side == 0)
		wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex->x = (int)(wall_x * tex->curr_img->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex->x = tex->curr_img->width - tex->x - 1;
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		tex->x = tex->curr_img->width - tex->x - 1;
}

static void	input_background(t_data *data, int start, int end, int x)
{
	int		color;
	char	*dst;
	int		i;

	dst = data->img.addr;
	color = data->ceiling_color;
	i = -1;
	while (++i < start)
	{
		if ((x < data->minimap_width && i < data->minimap_height))
			continue ;
		dst = data->img.addr + i * data->img.size_l + x * (data->img.bpp / 8);
		*(unsigned int *)dst = color;
	}
	color = data->floor_color;
	i = end + 1;
	while (i < WINDOW_HEIGHT)
	{
		dst = data->img.addr + i * data->img.size_l + x * (data->img.bpp / 8);
		*(unsigned int *)dst = color;
		i++;
	}
}

static unsigned int	texture_color(t_ray *ray, t_texture *tex)
{
	int				tex_y;
	char			*tex_color;
	unsigned int	color;

	tex_y = (int)(tex->pos);
	if (tex_y > tex->curr_img->height - 1)
		tex_y = tex->curr_img->height - 1;
	tex_color = tex->curr_img->addr + (tex_y * tex->curr_img->size_l + \
				tex->x * (tex->curr_img->bpp / 8));
	color = *((unsigned int *)tex_color);
	if (ray->side == 1)
		color = (color >> 1) & 0b011111110111111101111111;
	return (color);
}
