/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:46:11 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/26 17:09:52 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (para->format == 'u' || para->format == 'x' || para->format == 'X')
		i = ft_write_unsigned(ap, para, print_count);
	else if (para->format == 'p')
		i = ft_write_ptr(ap, para, print_count);
	return (i);
}

int	ft_process_print(va_list ap, const char *str, t_para *para, int *p_count)
{
	int	len_count;
	int	temp;

	len_count = 0;
	if (*str == '\0')
		return (0);
	else if (*str == '%')
	{
		if (ft_write_str_count("%", p_count) == -1)
			return (-1);
		else
			return (1);
	}
	para->flag = 0;
	para->width = 0;
	para->precision = -1;
	para->format = 0;
	temp = ft_make_struct(ap, str, para, &len_count);
	if (temp != -1)
		temp = ft_print_format(ap, para, p_count);
	if (temp == -1)
		return (-1);
	return (len_count);
}
