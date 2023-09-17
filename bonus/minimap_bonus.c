/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:35:55 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/17 22:28:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	set_minimap_color(char *type)
{
	int	rgb;

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

static void	input_square(t_data *data, char *type, int x, int y)
{	
	int		i;
	int		j;
	char	*dst;

	dst = data->img.addr;
	i = 0;
	while (i < TILE_SIZE * MINIMAP_SCALE)
	{
		j = 0;
		while (j < TILE_SIZE * MINIMAP_SCALE)
		{
			dst = data->img.addr + x * i + y * j;
			*((unsigned int *)dst) = set_minimap_color(type);
			j++;
		}
		i++;
	}
	
}

void	input_minimap(t_data *data)
{
	int	x;
	int	y;
	
	x = 0;
	while (x < data->map_width)
	{
		y = 0;
		while (y < data->map_height)
		{
			input_square(data, data->map[y][x], TILE_SIZE * MINIMAP_SCALE * x, \
						TILE_SIZE * MINIMAP_SCALE * y);
			y++;
		}
		x++;
	}
}