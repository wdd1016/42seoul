/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_5_unsigned_int_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:03:16 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:47:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_space_for_unsigned(t_para *para, int *p_count, int total_len)
{
	int	count_space;

	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && \
	para->pre_state == P_OFF)
		return (0);
	if (para->precision > total_len)
		total_len = para->precision;
	if ((para->flag & FLAG_SPACE) > 0)
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

static int	ft_bonus_utoa(unsigned int nbr, t_para *para, int *p_count, int len)
{
	int	count_zero;

	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && \
	para->pre_state == P_OFF)
	{
		if (para->precision > len)
			len = para->precision;
		if ((para->flag & FLAG_SPACE) == FLAG_SPACE)
			len++;
		count_zero = para->width - len;
	}
	else
		count_zero = para->precision - len;
	if (count_zero > 0)
	{
		if (ft_write_spacezero(count_zero, '0') < 0)
			return (-1);
		(*p_count) += count_zero;
	}	
	if (len > 0)
		if (ft_abstoa(nbr, p_count) < 0)
			return (-1);
	return (1);
}

int	ft_write_unsigned(va_list ap, t_para *para, int *print_count)
{
	unsigned int	nbr;
	int				abs_len;

	nbr = va_arg(ap, unsigned int);
	abs_len = ft_len_of_abs(nbr);
	if (para->pre_state == P_OVERFLOW)
		return (-1);
	if (para->pre_state == P_ON && nbr == 0)
		abs_len = 0;
	if ((para->flag & FLAG_MINUS) == 0)
		if (ft_space_for_unsigned(para, print_count, abs_len) == -1)
			return (-1);
	if ((para->flag & FLAG_SPACE) == FLAG_SPACE)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		(*print_count)++;
	}
	if (ft_bonus_utoa(nbr, para, print_count, abs_len) == -1)
		return (-1);
	if ((para->flag & FLAG_MINUS) == FLAG_MINUS)
		if (ft_space_for_unsigned(para, print_count, abs_len) == -1)
			return (-1);
	return (1);
}
