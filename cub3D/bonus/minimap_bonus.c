/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:35:55 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/21 21:22:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	minimap_color(char type)
{
	int	rgb;

	rgb = 0;
	if (type == '0')
		rgb = 236 << 16 | 238 << 8 | 129;
	else if (type == '1')
		rgb = 141 << 16 | 223 << 8 | 203;
	else if (type == '2')
		rgb = 166 << 16 | 255 << 8 | 150;
	else if (type == '3')
		rgb = 237 << 16 | 183 << 8 | 237;
	else if (type == ' ')
		rgb = 130 << 16 | 160 << 8 | 216;
	return (rgb);
}

static void	input_square(t_data *data, char type, int x, int y)
{	
	int		i;
	int		j;
	char	*dst;
	t_img	*img;

	img = &data->img;
	i = 0;
	while (i < (int)TILE_SIZE * MINIMAP_SCALE)
	{
		j = 0;
		while (j < (int)TILE_SIZE * MINIMAP_SCALE)
		{
			dst = img->addr + (int)(y * WINDOW_WIDTH) + j * img->size_l \
				+ x + i * (img->bpp / 8);
			*((unsigned int *)dst) = minimap_color(type);
			j++;
		}
		i++;
	}	
}

static unsigned int	player_color(int i, int j, t_img *img)
{
	unsigned int	color;
	char			*tex_color;

	tex_color = img->addr + j * img->size_l + i * (img->bpp / 8);
	color = *((unsigned int *)tex_color);
	return (color);
}

static void	input_player(t_data *data, int x, int y)
{	
	int		i;
	int		j;
	char	*dst;
	t_img	*img;

	img = &data->img;
	i = 0;
	while (i < (int)TILE_SIZE * MINIMAP_SCALE)
	{
		j = 0;
		while (j < (int)TILE_SIZE * MINIMAP_SCALE)
		{
			dst = img->addr + (int)(y * WINDOW_WIDTH) + j * img->size_l \
				+ x + i * (img->bpp / 8);
			*((unsigned int *)dst) = player_color(i, j, &(data->texture)[DOOR]);
			j++;
		}
		i++;
	}
}

// void	input_ray(t_data *data)
// {


// }

void	input_minimap(t_data *data)
{
	int	row;
	int	col;

	col = 0;
	while (col < data->map_width)
	{
		row = 0;
		while (row < data->map_height)
		{
			if ((int)data->player.x == col && (int)data->player.y == row)
				input_player(data, (int)TILE_SIZE * MINIMAP_SCALE * col, (int)TILE_SIZE * MINIMAP_SCALE * row);
			else
				input_square(data, data->map[row][col], \
							(int)TILE_SIZE * MINIMAP_SCALE * col, (int)TILE_SIZE * MINIMAP_SCALE * row);
			row++;
		}
		col++;
	}
	// input_ray(data);
}
