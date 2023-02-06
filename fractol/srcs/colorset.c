/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:50:42 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 23:07:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(t_data *all, int colortype)
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
