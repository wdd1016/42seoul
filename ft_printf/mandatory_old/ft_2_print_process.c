/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:30:48 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 01:04:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list ap, t_para *para, int *print_count)
{
	int	i;

	i = 0;
	if (para->format == 'c')
		i = ft_write_char(ap, print_count);
	else if (para->format == 's')
		i = ft_write_string(ap, print_count);
	else if (para->format == 'd' || para->format == 'i' || para->format == 'u')
		i = ft_write_int(ap, print_count, para);
	else if (para->format == 'x' || para->format == 'X')
		i = ft_write_16base(ap, print_count, para);
	else if (para->format == 'p')
		i = ft_write_ptr(ap, print_count, para);
	else if (para->format == '%')
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		(*print_count)++;
	}
	return (i);
}

int	ft_process_print(va_list ap, const char **str, t_para *para, int *p_count)
{
	(*str)++;
	if (**str == '\0')
		return (0);
	ft_memset(para, 0, sizeof(t_para));
	para->format = **str;
	(*str)++;
	if (ft_print_format(ap, para, p_count) == -1)
		return (-1);
	return (1);
}
