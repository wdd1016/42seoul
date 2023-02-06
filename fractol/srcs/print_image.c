/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:10:10 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 23:00:43 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
