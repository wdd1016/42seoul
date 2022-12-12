/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format_un_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:03:16 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 22:58:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_write_unsigned(va_list ap, t_para *para, int *print_count)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (ft_utoa(i, print_count) == -1)
		return (-1);
	else
		return (1);
}

int	ft_write_16base_us_int_small(va_list ap, t_para *para, int *print_count)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (ft_utosx(i, print_count) == -1)
		return (-1);
	else
		return (1);
	return (1);
}

int	ft_write_16base_us_int_big(va_list ap, t_para *para, int *print_count)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (ft_utobx(i, print_count) == -1)
		return (-1);
	else
		return (1);
	return (1);
}

int	ft_write_ptr(va_list ap, t_para *para, int *print_count)
{
	size_t	i;

	i = (size_t)va_arg(ap, void *);
	if (i == 0)
	{
		if (write(1, "0x0", 3) < 0)
			return (-1);
		(*print_count) += 3;
		return (1);
	}
	else
	{
		if (ft_ulltox(i, print_count) == -1)
			return (-1);
	}
	return (1);
}
