/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_scaling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:16:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 22:46:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_shift_axis(t_data *all, int axis, int change)
{
	double	*min;
	double	*range;

	min = &(all->coor->rmin);
	range = &(all->coor->rrange);
	if (axis == IMAGINARY)
	{
		min = &(all->coor->imin);
		range = &(all->coor->irange);
	}
	if (change < 0)
	{
		*min -= (double)0.1 * (*range);
		if (*min < -2.0)
			*min = -2.0;
	}
	else if (change > 0)
	{
		*min += (double)0.1 * (*range);
		if (*min + (*range) > 2.0)
			*min = (double)2.0 - (*range);
	}
}

void	ft_expand_fractal(t_data *all, int x, int y)
{
	double	real;
	double	in;

	real = all->coor->rmin + ((double)x / (double)WIDTH) * all->coor->rrange;
	in = all->coor->imin + ((double)y / (double)HEIGHT) * all->coor->irange;
	all->coor->rmin += (double)0.25 * (real - all->coor->rmin);
	all->coor->rrange *= (double)0.75;
	all->coor->imin += (double)0.25 * (in - all->coor->imin);
	all->coor->irange *= (double)0.75;
}
//every expand/reduct wheel, 1 -> 3/4 or 1 -> 4/3

void	ft_reduct_fractal(t_data *all, int x, int y)
{
	double	real;
	double	in;

	real = all->coor->rmin + ((double)x / (double)WIDTH) * all->coor->rrange;
	in = all->coor->imin + ((double)y / (double)HEIGHT) * all->coor->irange;
	all->coor->rmin -= ((double)1.0 / 3.0) * (real - all->coor->rmin);
	if (all->coor->rmin < -2.0)
		all->coor->rmin = -2.0;
	all->coor->rrange *= ((double)4.0 / 3.0);
	if (all->coor->rrange > 4.0)
		all->coor->rrange = 4.0;
	all->coor->imin -= ((double)1.0 / 3.0) * (in - all->coor->imin);
	if (all->coor->imin < -2.0)
		all->coor->imin = -2.0;
	all->coor->irange *= ((double)4.0 / 3.0);
	if (all->coor->irange > 4.0)
		all->coor->irange = 4.0;
}
