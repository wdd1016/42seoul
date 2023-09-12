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

void	input_vertical_line(t_data *data, t_img *img, t_ray *ray, int i)
{
	int 	line_height;
	int 	row_idx;
	int 	end_idx;
	char	*dst;

	line_height = (int)(WINDOW_HEIGHT / ray->perpwall_dist);
	row_idx = -line_height / 2 + WINDOW_HEIGHT / 2;
    if (row_idx < 0)
		row_idx = 0;
	end_idx = line_height / 2 + WINDOW_HEIGHT / 2;
    if (end_idx >= WINDOW_HEIGHT)
		end_idx = WINDOW_HEIGHT - 1;
	ray->step = TEXTURE_HEIGHT / (double)line_height;
	ray->texpos = (row_idx - WINDOW_HEIGHT / 2 + line_height / 2) * ray->step;
	while (row_idx <= end)
	{
		dst = img->addr + (row_idx * img->size_l + i * (img->bpp / 8));
		*(unsigned int *)dst = texture_color(&data->texture, &data->player, ray, i);
		row_idx++;
	}
}

int	texture_color(t_img *texture, t_player *player, t_ray *ray, int i)
{
	int		color;
	int		tex_y;
	int		tex_x;
	double	wallX; //where exactly the wall was hit

      //calculate value of wallX
      if (ray->side == 0)
		wallX = player->y + ray->perpwall_dist * ray->raydir_y;
      else
	  	wallX = player->x + ray->perpwall_dist * ray->raydir_x;
      wallX -= floor(wallX);
      if(ray->side == 0 && ray->raydir_x > 0)
	  	tex_x = TEXTURE_WIDTH - wallX * (double)TEXTURE_WIDTH - 1;
      if(ray->side == 1 && ray->raydir_y < 0)
	  	tex_x = TEXTURE_WIDTH - wallX * (double)TEXTURE_WIDTH - 1;
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		tex_y = (int)ray->texpos & (TEXTURE_HEIGHT - 1);
        ray->texpos += ray->step;
		if (ray->side == 0)
		{
			if (ray->raydir_x >= 0)
				color = texture[EAST].addr + TEXTURE_HEIGHT * tex_x + tex_y;
			else
				color = texture[WEST].addr + TEXTURE_HEIGHT * tex_x + tex_y;
		}
		else
		{
			if (ray->raydir_y >= 0)
				color = texture[SOUTH].addr + TEXTURE_HEIGHT * tex_x + tex_y;
			else
				color = texture[NORTH].addr + TEXTURE_HEIGHT * tex_x + tex_y;
		}
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(ray->side == 1)
			color = (color >> 1) & 8355711;
	return (color);
}

