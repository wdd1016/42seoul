/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:26:30 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/10 23:12:15 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int n)
{
	char	digit;

	digit = (n % 10) + '0';
	if (n < 10)
		write(1, &digit, 1);
	else
	{
		print_number(n / 10);
		write(1, &digit, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
	{
		print_number(nb);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		write(1, "-", 1);
		print_number(-nb);
	}
}
