/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:40:36 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/03 23:34:02 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_data(t_data *data, int argc, char *argv[]);
void	ft_print_image(t_data *all);

int main(int argc, char *argv[])
{
	t_data	all;

	ft_init_data(&all, argc, argv);
	all.mlx = mlx_init();
	if (!(all.mlx))
	{
		perror(strerror(ENOMEM));
		exit(1);		
	}
	all.win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "flactol_project");
	if (!(all.win))
	{
		free(all.mlx);
		perror(strerror(ENOMEM));
		exit(1);
	}
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, \
	&all.line_length, &all.endian);
	ft_hook_setup(&all);
	ft_print_image(&all);
	mlx_put_image_to_window(all.mlx, all.win, all.img, 0, 0);
	mlx_loop(all.mlx);
}

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

static void	ft_init_data(t_data *data, int argc, char *argv[])
{
	if (argc == 1 || ft_check_type(data, argc, argv) == 0)
	{
		write(2, "Put in the possible parameters below.\n", 38);
		write(2, "mandelbrot\n", 11);
		write(2, "julia [c_rnum] [c_inum]\n", 24);
		write(2, "newton", 6);
		exit(0);
	}
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
}

static int	ft_check_type(t_data *data, int argc, char *argv[])
{
	if (ft_strcmp(argv[1], "mandelbrot"))
	{
		data->type = MANDEL;
		return (1);
	}
	else if (ft_strcmp(argv[1], "julia"))
	{
		data->type = JULIA;
		???
	}
	else if (ft_strcmp(argv[1], "newton"))
	{
		data->type = NEWTON;
		return (1);
	}
	else
		return (0);
}
