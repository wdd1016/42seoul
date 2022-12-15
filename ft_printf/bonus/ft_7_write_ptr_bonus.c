/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7_write_ptr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:05:12 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:54:55 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_space_for_ptr(t_para *para, int *print_count, int len_addr)
{
	int	count_space;

	if (para->precision > len_addr)
		len_addr = para->precision;
	len_addr += 2;
	count_space = para->width - len_addr;
	if (count_space > 0)
	{
		if (ft_write_spacezero(count_space, ' ') < 0)
			return (-1);
		(*print_count) += count_space;
	}
	return (1);
}

static int	ft_bonus_ulltox(size_t addr, t_para *para, int *p_count, int len_ad)
{
	int	count_zero;

	if (write(1, "0x", 2) < 0)
		return (-1);
	(*p_count) += 2;
	count_zero = para->precision - len_ad;
	if (count_zero > 0)
	{
		if (ft_write_spacezero(count_zero, '0') < 0)
			return (-1);
		(*p_count) += count_zero;
	}	
	if (len_ad > 0)
		if (ft_ulltox(addr, p_count, para) < 0)
			return (-1);
	return (1);
}

int	ft_write_ptr(va_list ap, t_para *para, int *print_count)
{
	size_t	addr;
	size_t	len_addr;

	addr = (size_t)va_arg(ap, void *);
	len_addr = ft_len_of_x(addr);
	if (para->pre_state == P_OVERFLOW)
		return (-1);
	if (para->pre_state == P_ON && addr == 0)
		len_addr = 0;
	if ((para->flag & FLAG_MINUS) == 0)
		if (ft_space_for_ptr(para, print_count, len_addr) == -1)
			return (-1);
	if (ft_bonus_ulltox(addr, para, print_count, len_addr) == -1)
		return (-1);
	if ((para->flag & FLAG_MINUS) == FLAG_MINUS)
		if (ft_space_for_ptr(para, print_count, len_addr) == -1)
			return (-1);
	return (1);
}
