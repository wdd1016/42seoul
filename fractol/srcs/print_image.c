/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:10:10 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 01:50:56 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_print_image(t_data *all)
{
	int	(*ft_set[3])(t_data *, int, int);
	int	x;
	int	y;

	ft_set[MANDEL] = ft_mandelbrot;
	ft_set[JULIA] = ft_julia;
	ft_set[NEWTON] = ft_newton;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			ft_mlx_pixel_put(all, x, y, ft_set[all->type]);
		}
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + ((HEIGHT - y) * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
