/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_print_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:46:11 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 20:35:54 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_format(va_list ap, t_para *para, int *print_count)
{
	int	i;

	i = 0;
	if (para->format == 'c')
		i = ft_write_char(ap, para, print_count);
	else if (para->format == 's')
		i = ft_write_string(ap, para, print_count);
	else if (para->format == 'd' || para->format == 'i')
		i = ft_write_int(ap, para, print_count);
	else if (para->format == 'u')
		i = ft_write_unsigned(ap, para, print_count);
	else if (para->format == 'x')
		i = ft_write_16base_us_int_small(ap, para, print_count);
	else if (para->format == 'X')
		i = ft_write_16base_us_int_big(ap, para, print_count);
	else if (para->format == 'p')
		i = ft_write_ptr(ap, para, print_count);
	return (i);
}

int	ft_process_print(va_list ap, const char **str, t_para *para, int *p_count)
{
	int	temp;

	if (**str == '\0')
		return (0);
	else if (**str == '%')
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		(*p_count)++;
	}
	para->flag = 0;
	para->width = 0;
	para->precision = 0;
	para->minus = 0;
	para->format = 0;
	temp = ft_make_struct(str, para, p_count);
	if (temp == -1)
		return (-1);
	temp = ft_print_format(ap, para, p_count);
	if (temp == -1)
		return (-1);
	return (1);
}
