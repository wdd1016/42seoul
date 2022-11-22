/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:36:34 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/02 18:30:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_print_4words(int x, int y)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0' + x / 10;
	b = '0' + x % 10;
	c = '0' + y / 10;
	d = '0' + y % 10;
	ft_print(a);
	ft_print(b);
	ft_print(' ');
	ft_print(c);
	ft_print(d);
	if (x != 98)
	{
		ft_print(',');
		ft_print(' ');
	}
}

int	check_combination(int fir, int sec)
{
	if (fir < sec)
		return (1);
	else
		return (0);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 100)
	{
		while (y < 100)
		{
			if (check_combination(x, y) == 1)
				ft_print_4words(x, y);
			y++;
		}
		x++;
		if (y == 100)
			y = x + 1;
	}
}
