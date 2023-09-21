/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:35:55 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/24 21:46:39 by jiyeolee         ###   ########.fr       */
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

static unsigned int	minimap_color(char type)
{
	unsigned int	color;

	color = 0;
	if (type == '0')
		color = 0xECEE81;
	else if (type == '1')
		color = 0x8DDFCB;
	else if (type == '2')
		color = 0xEDB7ED;
	else if (type == '3')
		color = 0xBC7AF9;
	else if (type == ' ')
		color = 0x82A0D8;
	return (color);
}

void	input_minimap(t_data *data)
{
	t_minimap	mmap;

	mmap.row = -1;
	while (++(mmap.row) < data->minimap_height)
	{
		mmap.col = -1;
		while (++(mmap.col) < data->minimap_width)
		{
			mmap.x = data->map_width / (double)data->minimap_width * mmap.col;
			mmap.y = data->map_height / (double)data->minimap_height * mmap.row;
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
