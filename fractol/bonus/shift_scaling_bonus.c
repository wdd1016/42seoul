/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_scaling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:16:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/07 18:19:50 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
		*min -= (double)0.2 * (*range);
	else if (change > 0)
		*min += (double)0.2 * (*range);
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
/* every expand/reduct wheel, 1 -> 3/4 or 1 -> 4/3 */

void	ft_reduct_fractal(t_data *all, int x, int y)
{
	double	real;
	double	in;

	real = all->coor->rmin + ((double)x / (double)WIDTH) * all->coor->rrange;
	in = all->coor->imin + ((double)y / (double)HEIGHT) * all->coor->irange;
	all->coor->rmin -= ((double)1.0 / 3.0) * (real - all->coor->rmin);
	all->coor->rrange *= ((double)4.0 / 3.0);
	all->coor->imin -= ((double)1.0 / 3.0) * (in - all->coor->imin);
	all->coor->irange *= ((double)4.0 / 3.0);
}
