/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:50:42 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/06 20:45:06 by juyojeon         ###   ########.fr       */
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
		plus = (25 << 16) + 25;
	else if (colortype == BLUE)
		plus = (25 << 16) + (25 << 8);
	else
		plus = (25 << 8) + 25;
	i = -1;
	while (++i < 10)
	{
		(all->colorset)[i] = color;
		color -= plus;
	}
}
