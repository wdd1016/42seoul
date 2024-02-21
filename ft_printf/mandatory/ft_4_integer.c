/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:37:39 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:48:12 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sign_int(int nbr, t_para *para, int *print_count)
{
	if (nbr < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		(*print_count)++;
	}
	else if ((para->flag & (FLAG_SPACE + FLAG_PLUS)) > 0 && nbr >= 0)
	{
		if ((para->flag & (FLAG_SPACE + FLAG_PLUS)) == FLAG_SPACE)
		{
			if (write(1, " ", 1) < 0)
				return (-1);
		}
		else
			if (write(1, "+", 1) < 0)
				return (-1);
		(*print_count)++;
	}
	return (1);
}

static int	ft_space_for_int(int nbr, t_para *para, int *p_count, int total_len)
{
	int		count_space;

	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && \
	para->pre_state == P_OFF)
		return (0);
	if (para->precision > total_len)
		total_len = para->precision;
	if ((para->flag & (FLAG_SPACE + FLAG_PLUS)) > 0 || nbr < 0)
		total_len++;
	count_space = para->width - total_len;
	if (count_space > 0)
	{
		if (ft_write_spacezero(count_space, ' ') < 0)
			return (-1);
		(*p_count) += count_space;
	}
	return (1);
}

static int	ft_b_itoa(int nbr, t_para *para, int *print_count, int len)
{
	int	count_zero;

	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && \
	para->pre_state == P_OFF)
	{
		if ((para->flag & (FLAG_SPACE + FLAG_PLUS)) > 0 || nbr < 0)
			len++;
		if (para->precision > len)
			len = para->precision;
		count_zero = para->width - len;
	}
	else
		count_zero = para->precision - len;
	if (count_zero > 0)
	{
		if (ft_write_spacezero(count_zero, '0') < 0)
			return (-1);
		(*print_count) += count_zero;
	}	
	if (len > 0)
		if (ft_abstoa(nbr, print_count) < 0)
			return (-1);
	return (1);
}

int	ft_write_int(va_list ap, t_para *para, int *print_count)
{
	int	nbr;
	int	abs_len;

	nbr = va_arg(ap, int);
	abs_len = ft_len_of_abs(nbr);
	if (para->pre_state == P_OVERFLOW)
		return (-1);
	if (para->pre_state == P_ON && nbr == 0)
		abs_len = 0;
	if ((para->flag & FLAG_MINUS) == 0)
		if (ft_space_for_int(nbr, para, print_count, abs_len) == -1)
			return (-1);
	if (ft_sign_int(nbr, para, print_count) < 0)
		return (-1);
	if (ft_b_itoa(nbr, para, print_count, abs_len) == -1)
		return (-1);
	if ((para->flag & FLAG_MINUS) == FLAG_MINUS)
		if (ft_space_for_int(nbr, para, print_count, abs_len) == -1)
			return (-1);
	return (1);
}
