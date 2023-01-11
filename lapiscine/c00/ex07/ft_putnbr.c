/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:02:08 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/08 09:23:18 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_number(int n)
{
	char	digit;

	digit = (n % 10) + '0';
	if (n < 10)
		print_char(digit);
	else
	{
		print_number(n / 10);
		print_char(digit);
	}
}

void	ft_putnbr(int nb)
{
	int		absol;

	if (nb >= 0)
	{
		absol = nb;
		print_number(absol);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		absol = -nb;
		print_char('-');
		print_number(absol);
	}
}
