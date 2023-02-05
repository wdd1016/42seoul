/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:10:10 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/05 21:17:22 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_image(t_data *image)
{
	int	x, y;

	for (x=200; x<500; x++)
	{
		for (y=100; y<300; y++)
		{
			ft_mlx_pixel_put(image, x, y, 0x00FF0000);
		}
	}
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
