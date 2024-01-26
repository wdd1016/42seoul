/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6_16base_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:08:03 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:47:37 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_space_16(unsigned int nbr, t_para *para, int *p_count, int len)
{
	int	count_space;

	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && \
	para->pre_state == P_OFF)
		return (0);
	if (para->precision > len)
		len = para->precision;
	if ((para->flag & FLAG_SHARP) == FLAG_SHARP && nbr > 0)
		len += 2;
	count_space = para->width - len;
	if (count_space > 0)
	{
		if (ft_write_spacezero(count_space, ' ') < 0)
			return (-1);
		(*p_count) += count_space;
	}
	return (1);
}

static int	ft_bonus_utox(unsigned int nbr, t_para *para, int *p_count, int len)
{
	int	count_zero;

	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && \
	para->pre_state == P_OFF)
	{
		if (para->precision > len)
			len = para->precision;
		if ((para->flag & FLAG_SHARP) == FLAG_SHARP && nbr > 0)
			len += 2;
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
		if (ft_ulltox(nbr, p_count, para) < 0)
			return (-1);
	return (1);
}

int	ft_sign_16base(unsigned int nbr, t_para *para, int *print_count)
{
	if ((para->flag & FLAG_SHARP) == FLAG_SHARP && nbr > 0)
	{
		if (para->format == 'x')
		{
			if (write(1, "0x", 2) < 0)
				return (-1);
		}
		else
		{
			if (write(1, "0X", 2) < 0)
				return (-1);
		}
		(*print_count) += 2;
	}
	return (1);
}

int	ft_write_16base(va_list ap, t_para *para, int *print_count)
{
	unsigned int	nbr;
	unsigned int	len;

	nbr = va_arg(ap, unsigned int);
	len = ft_len_of_x(nbr);
	if (para->pre_state == P_OVERFLOW)
		return (-1);
	if (para->pre_state == P_ON && nbr == 0)
		len = 0;
	if ((para->flag & FLAG_MINUS) == 0)
		if (ft_space_16(nbr, para, print_count, len) == -1)
			return (-1);
	if (ft_sign_16base(nbr, para, print_count) < 0)
		return (-1);
	if (ft_bonus_utox(nbr, para, print_count, len) == -1)
		return (-1);
	if ((para->flag & FLAG_MINUS) == FLAG_MINUS)
		if (ft_space_16(nbr, para, print_count, len) == -1)
			return (-1);
	return (1);
}
