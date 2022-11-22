/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:33:11 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/02 17:41:58 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print__char(char c)
{
	write(1, &c, 1);
}

void	ft_print_string(int com[], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = com[i] + '0';
		print__char(c);
		i++;
	}
	if (com[0] != 10 - n)
	{
		print__char(',');
		print__char(' ');
	}
}

void	ft_show_combn(int n, int com[], int order, int last_number)
{
	int	number;
	int	max;

	max = 10 - n + order;
	number = last_number + 1;
	if (order == n)
	{
		ft_print_string(com, n);
	}
	else
	{
		while (number <= max)
		{
			com[order] = number;
			ft_show_combn(n, com, order + 1, number);
			number++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	com[10];
	int	num;

	num = 0;
	while (num < n)
	{
		com[num] = 0;
		num++;
	}
	ft_show_combn(n, com, 0, -1);
}
