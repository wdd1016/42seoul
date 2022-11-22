/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:38:32 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/19 15:22:49 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_space(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == ' ')
		return (1);
	else if (*str == '\f' || *str == '\r' || *str == '\v')
		return (1);
	else
		return (0);
}

int	ft_sum_atoi(char *str, int minus)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	if (minus > 0)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			sum *= 10;
			sum += str[i] - '0';
			i++;
		}
	}
	else if (minus < 0)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			sum *= 10;
			sum -= str[i] - '0';
			i++;
		}
	}
	return (sum);
}

int	ft_atoi(char *str)
{
	int	minus;

	minus = 1;
	while (ft_is_space(str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	return (ft_sum_atoi(str, minus));
}

void	ft_putnbr(int nb)
{
	char	num;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb < 10)
	{
		num = (nb % 10) + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		num = (nb % 10) + '0';
		write(1, &num, 1);
	}
}
