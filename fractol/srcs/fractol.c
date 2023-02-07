/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:40:36 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/07 18:42:23 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_data(t_data *data, int argc, char *argv[]);
static int	ft_check_type(t_data *data, char *argv[]);

int	main(int argc, char *argv[])
{
	t_data	all;

	ft_init_data(&all, argc, argv);
	all.mlx = mlx_init();
	if (!(all.mlx))
		ft_error(&all, ENOMEM);
	all.win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "flactol_project");
	if (!(all.win))
		ft_error(&all, ENOMEM);
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, \
	&all.line_length, &all.endian);
	ft_hook_setup(&all);
	ft_print_image(&all);
	mlx_loop(all.mlx);
	return (0);
}

static void	ft_init_data(t_data *data, int argc, char *argv[])
{
	if (argc == 1 || ft_check_type(data, argv) == 0)
	{
		write(2, "Put in the possible parameters below.\n", 38);
		write(2, "mandelbrot\n", 11);
		write(2, "julia [c_rnum] [c_inum]\n", 24);
		write(2, "For comfortable view, -1 < [c_rnum], [c_inum] < 1\n", 50);
		write(2, "burningship\n", 12);
		exit(1);
	}
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->coor = (t_coor *)malloc(sizeof(t_coor));
	if (!(data->coor))
		ft_error(data, ENOMEM);
	ft_colorsetting(data, GREEN);
	data->coor->rmin = -2.0;
	data->coor->imin = -2.0;
	data->coor->rrange = 4.0;
	data->coor->irange = 4.0;
}

static int	ft_check_type(t_data *data, char *argv[])
{
	if (ft_strnstr(argv[1], "mandelbrot", 10))
		data->type = MANDEL;
	else if (ft_strnstr(argv[1], "julia", 5))
	{
		data->type = JULIA;
		data->rnum = ft_atod(argv[2]);
		data->inum = ft_atod(argv[3]);
		if (data->rnum > 9.0 || data->inum > 9.0)
			return (0);
	}
	else if (ft_strnstr(argv[1], "burningship", 11))
		data->type = BURN;
	else
		return (0);
	return (1);
}

void	ft_colorsetting(t_data *all, int colortype)
{
	int	color;
	int	plus;
	int	i;

	color = 0xffffff;
	if (colortype == GREEN)
		plus = (20 << 16) + 20;
	else if (colortype == BLUE)
		plus = (20 << 16) + (20 << 8);
	else
		plus = (20 << 8) + 20;
	i = -1;
	while (++i < 10)
	{
		(all->colorset)[i] = color;
		color -= plus;
	}
}
