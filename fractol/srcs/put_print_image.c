/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_print_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:25:48 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/07 02:32:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_choicecolor(t_data *all, t_unit unit);
static int	ft_mandelbrot(t_data *all, double rvalue, double ivalue);
static int	ft_julia(t_data *all, double rvalue, double ivalue);
static int	ft_buringship(t_data *all, double rvalue, double ivalue);

void	ft_print_image(t_data *all)
{
	t_unit	unit;
	int		color;
	char	*dst;
	
	unit.x = 0;
	unit.runit = all->coor->rrange / (double)WIDTH;
	unit.iunit = all->coor->irange / (double)HEIGHT;
	while (unit.x < WIDTH)
	{
		unit.y = 0;
		while (unit.y < HEIGHT)
		{
			color = ft_choicecolor(all, unit);
			dst = all->addr + unit.y * all->line_length + \
			unit.x * (all->bits_per_pixel / 8);
			*(unsigned int *)dst = color;
			(unit.y)++;
		}
		(unit.x)++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

static int	ft_choicecolor(t_data *all, t_unit unit)
{
	int	(*ft_colornum[3])(t_data *, double, double);
	double	rvalue;
	double	ivalue;

	ft_colornum[MANDEL] = ft_mandelbrot;
	ft_colornum[JULIA] = ft_julia;
	ft_colornum[NEWTON] = ft_buringship;
	rvalue = all->coor->rmin + (double)unit.x * unit.runit;
	ivalue = all->coor->imin + (double)unit.y * unit.iunit;
	return (ft_colornum[all->type](all, rvalue, ivalue));
}

static int	ft_mandelbrot(t_data *all, double rvalue, double ivalue)
{
	double	x;
	double	y;
	double	xnext;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (((x * x) + (y * y) < 4.0) && iter < MAX_ITER)
	{
		xnext = (x * x) - (y * y) + rvalue;
		y = (2.0 * x * y) + ivalue;
		x = xnext;
		iter++;
	}
	if (iter == MAX_ITER)
		return (0x0);
	else
		return ((all->colorset)[iter / 10]);
}

static int	ft_julia(t_data *all, double rvalue, double ivalue)
{
	double	x;
	double	y;
	double	xnext;
	int		iter;

	x = rvalue;
	y = ivalue;
	iter = 0;
	while (((x * x) + (y * y) < 4.0) && iter < MAX_ITER)
	{
		xnext = (x * x) - (y * y) + all->rnum;
		y = (2.0 * x * y) + all->inum;
		x = xnext;
		iter++;
	}
	if (iter == MAX_ITER)
		return (0x0);
	else
		return ((all->colorset)[iter / 10]);
}

static int	ft_buringship(t_data *all, double rvalue, double ivalue)
{
	double	x;
	double	y;
	double	xnext;
	int		iter;

	x = rvalue;
	y = ivalue;
	iter = 0;
	while (((x * x) + (y * y) < 4.0) && iter < MAX_ITER)
	{
		xnext = (x * x) - (y * y) + x;
		y = fabs(2 * x * y) + y;
		x = xnext;
		iter++;
	}
	if (iter == MAX_ITER)
		return (0x0);
	else
		return ((all->colorset)[iter / 10]);
}
