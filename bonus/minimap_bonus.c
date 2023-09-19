/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:35:55 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/18 20:25:16 by jiyeolee         ###   ########.fr       */
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
		rgb = 130 << 16 | 160 << 8 | 216;
	else if (type == '3')
		rgb = 237 << 16 | 183 << 8 | 237;
	return (rgb);
}

static void	input_square(t_data *data, char type, int x, int y)
{	
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < TILE_SIZE * MINIMAP_SCALE)
	{
		j = 0;
		while (j < TILE_SIZE * MINIMAP_SCALE)
		{
			dst = data->img.addr + WINDOW_WIDTH / 2 * (x + i) + y + j;
			*((unsigned int *)dst) = minimap_color(type);
			j++;
		}
		i++;
	}
	
}

void	input_minimap(t_data *data)
{
	int	row;
	int	col;
	
	row = 0;
	while (row < data->map_width)
	{
		col = 0;
		while (col < data->map_height)
		{
			input_square(data, data->map[col][row], MINIMAP_SCALE * col * TILE_SIZE, MINIMAP_SCALE * row * TILE_SIZE);

			// input_square(data, data->map[y][x], TILE_SIZE * MINIMAP_SCALE * x, \
			// 			TILE_SIZE * MINIMAP_SCALE * y);
			col++;
		}
		row++;
	}
}