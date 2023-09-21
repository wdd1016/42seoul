/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:35:55 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/22 00:39:09 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

typedef struct s_minimap
{
	int		row;
	int		col;
	double	x;
	double	y;
	char	*dst;
}	t_minimap;

static unsigned int	minimap_color(char type);

void	input_minimap(t_data *data)
{
	t_minimap	mmap;

	mmap.row = -1;
	while (++(mmap.row) < data->minimap_height)
	{
		mmap.col = -1;
		while (++(mmap.col) < data->minimap_width)
		{
			mmap.x = data->map_width * mmap.col / (double)data->minimap_width;
			mmap.y = data->map_height * mmap.row / (double)data->minimap_height;
			mmap.dst = data->img.addr + mmap.row * data->img.size_l \
				+ mmap.col * (data->img.bpp / 8);
			if (pow(mmap.x - data->player.x, 2) * 0.625 \
				+ pow(mmap.y - data->player.y, 2) < 0.125)
				*(unsigned int *)(mmap.dst) = 0x09FBD3;
			else
				*(unsigned int *)(mmap.dst) \
				= minimap_color(data->map[(int)mmap.y][(int)mmap.x]);
		}
	}
}

static unsigned int	minimap_color(char type)
{
	unsigned int	rgb;

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
