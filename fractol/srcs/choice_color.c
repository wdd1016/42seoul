/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:25:48 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 23:00:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelbrot(t_data *all, double rvalue, double ivalue);
static int	ft_julia(t_data *all, double rvalue, double ivalue);
static int	ft_newton(t_data *all, double rvalue, double ivalue);

int	ft_choicecolor(t_data *all, t_unit unit)
{
	int	(*ft_colornum[3])(t_data *, double, double);
	double	rvalue;
	double	ivalue;

	ft_colornum[MANDEL] = ft_mandelbrot;
	ft_colornum[JULIA] = ft_julia;
	ft_colornum[NEWTON] = ft_newton;
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
	int		max_iter;

	x = rvalue;
	y = ivalue;
	iter = 0;
	max_iter = 70;
	while (((x * x) + (y * y) < 4.0) && iter < max_iter)
	{
		xnext = (x * x) - (y * y) + all->rnum;
		y = (2.0 * x * y) + all->inum;
		x = xnext;
		iter++;
	}
	if (iter == max_iter)
		return (0x0);
	else
		return ((all->colorset)[iter / 7]);
}

static int	ft_newton(t_data *all, double rvalue, double ivalue)
{
	
	return (0x0);
}
