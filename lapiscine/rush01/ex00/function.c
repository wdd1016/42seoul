/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:26:49 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/09 08:50:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	ft_test_four(int *str_in, int *str_out, int order);
extern int	ft_test_last(int *str_in, int *str_out);

void	ft_write_str(int *str_out)
{
	char	out;
	int		i;

	i = 0;
	while (i < 16)
	{
		out = *(str_out + i) + '0';
		write(1, &out, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	i++;
	}
}

void	ft_recursion(int *str_in, int *str_out, int order, int i)
{
	if (order % 4 == 3)
	{
		while (++i <= 4)
		{
			*(str_out + order) = i;
			if (ft_test_four(str_in, str_out, order) == 1)
				ft_recursion(str_in, str_out, order + 1, 0);
		}
	}
	else if (order == 16)
	{
		if (ft_test_last(str_in, str_out) == 1)
		{
			ft_write_str(str_out);
			*str_in = 777;
		}
	}
	else
	{
		while (++i <= 4)
		{
			*(str_out + order) = i;
			ft_recursion(str_in, str_out, order + 1, 0);
		}
	}
}
