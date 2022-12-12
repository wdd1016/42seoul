/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_bouns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:37:39 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 23:27:20 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_minus_int(t_para *para, int *p_count, int total_len)
{
	unsigned long long	sum;
	unsigned int		temp;

	sum = para->precision;
	sum += *p_count;
	if (sum >= 9223372036854775807)
	{
		temp = (unsigned int)sum;
		if (temp >= 2147483647)
			return (-1);
		para->width = temp - *p_count;
	}
	else if (sum >= 2147483647)
		return (-1);
	else
		para->width = sum - *p_count;
	temp = 0;
	while (temp++ < (para->width - total_len))
		if (write(1, " ", 1) < 0)
			return (-1);
	return (1);
}

static int	ft_itoa_bonus(int nbr, t_para *para, int *print_count)
{
	if ((para->flag & 24) > 0 && nbr >= 0)
	{
		if ((para->flag & 24) >= 16)
			if (write(1, "+", 1) < 0)
				return (-1);
		if ((para->flag & 24) == 8)
			if (write(1, " ", 1) < 0)
				return (-1);
		(*print_count)++;
		if (ft_itoa(nbr, print_count) < 0)
			return (-1);
	}
	else
	{
		if (ft_itoa(nbr, print_count) < 0)
			return (-1);
	}
	return (1);
}

int	ft_precision_filtering(t_para *para, int nbr)
{
	unsigned long long	previous;
	unsigned int		temp;
	int					nbr_len;

	previous = para->precision;
	nbr_len = ft_len_of_int(nbr);
	if (previous > 4294967295)
	{
		temp = (unsigned int)previous;
		if (temp - nbr_len > 2147483647)
			para->precision = 0;
		else
			para->precision = temp;
	}
	else if (previous - nbr_len > 2147483647)
		para->precision = 0;
	else if (previous == 2147483647)
		return (-1);
	return (1);
}

int	ft_space_or_zero(int nbr, t_para *para, int *p_count, int total_len)
{
	char			ch;
	unsigned int	max;

	if ((para->flag & 3) == 2)
		ch = '0';
	else
		ch = ' ';
	if (ft_precision_filtering(para, nbr) == -1)
		return (-1);
}

int	ft_write_int(va_list ap, t_para *para, int *print_count)
{
	int	i;
	int	len;

	i = va_arg(ap, int);
	len = ft_len_of_int(i);
	if ((para->flag & 24) > 0 && i >= 0)
		len++;
	if (para->minus == -1)
	{
		if (ft_itoa_bonus(i, para, print_count) == -1)
			return (-1);
		if (ft_minus_int(para, print_count, len) == -1)
			return (-1);
	}
	if ((para->flag & 1) == 1)
		if (ft_itoa_bonus(i, para, print_count) == -1)
			return (-1);
	if (ft_space_or_zero(i, para, print_count, len) == -1)
		return (-1);
	if ((para->flag & 1) == 0)
		if (ft_itoa_bonus(i, para, print_count) == -1)
			return (-1);
	return (1);
}
