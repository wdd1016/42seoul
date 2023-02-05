/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:50:42 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 01:14:24 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(t_data *all, int colortype)
{
	int	color;
	int	plus;
	int	i;

	if (colortype == GREEN)
	{
		color = 0x00ff00;
		plus = (25 << 16) + (25);
	}
	else if (colortype == BLUE)
	{
		color = 0x0000ff;
		plus = (25 << 16) + (25 << 8);
	}
	else
	{
		color = 0xff0000;
		plus = (25 << 8) + (25);
	}
	i = -1;
	while (++i < 10)
	{
		(all->colorset)[i] = color;
		color += plus;
	}
}
