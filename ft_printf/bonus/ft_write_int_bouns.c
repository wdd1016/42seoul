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

static int	ft_space_for_int(int nbr, t_para *para, int *p_count, int nbr_len)
{
	char	ch;
	int		temp;

	if ((para->flag & (FLAG_SPACE + FLAG_PLUS)) > 0 && nbr >= 0)
		nbr_len++;
	if (para->width - para->precision < nbr_len)
		return (0);
	if ((para->flag & (FLAG_MINUS + FLAG_ZERO)) == FLAG_ZERO && para->pre_state == P_OFF)
		ch = '0';
	else
		ch = ' ';
	temp = para->width - para->precision - nbr_len;
	while (temp-- > 0)
	{
		if (write(1, &ch, 1) < 0)
			return (-1);
		(*p_count)++;
	}
	return (1);
}

static int	ft_itoa_bonus(int nbr, t_para *para, int *print_count, int nbr_len)
{
	int count_zero;

	if ((para->flag & (FLAG_SPACE + FLAG_PLUS)) > 0 && nbr >= 0)
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
	count_zero = para->precision - nbr_len;
	while (count_zero-- > 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		(*print_count)++;
	}
	if (nbr_len > 0)
		if (ft_itoa(nbr, print_count) < 0)
			return (-1);
	return (1);
}

int	ft_write_int(va_list ap, t_para *para, int *print_count)
{
	int	nbr;
	int	nbr_len;

	nbr = va_arg(ap, int);
	nbr_len = ft_len_of_int(nbr);
	if (para->pre_state == P_OVERFLOW)
		return (-1);
	if (para->pre_state == P_ON && nbr == 0)
		nbr_len = 0;
	if ((para->flag & FLAG_MINUS) == 0)
		if (ft_space_for_int(nbr, para, print_count, nbr_len) == -1)
			return (-1);
	if (ft_itoa_bonus(nbr, para, print_count, nbr_len) == -1)
		return (-1);
	if ((para->flag & FLAG_MINUS) == 1)
		if (ft_space_for_int(nbr, para, print_count, nbr_len) == -1)
			return (-1);
	return (1);
}
