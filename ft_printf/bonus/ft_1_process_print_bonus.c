/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_process_print_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:46:11 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 05:35:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_format(va_list ap, t_para *para, int *print_count)
{
	int	i;

	if (para->format == 'c' || para->format == '%')
		i = ft_write_char(ap, para, print_count);
	else if (para->format == 's')
		i = ft_write_string(ap, para, print_count);
	else if (para->format == 'd' || para->format == 'i')
		i = ft_write_int(ap, para, print_count);
	else if (para->format == 'u')
		i = ft_write_unsigned(ap, para, print_count);
	else if (para->format == 'x' || para->format == 'X')
		i = ft_write_16base(ap, para, print_count);
	else if (para->format == 'p')
		i = ft_write_ptr(ap, para, print_count);
	else
		i = 0;
	return (i);
}

static int	ft_find_format(const char *str)
{
	while (ft_strchr("-0# +.123456789", *str))
		str++;
	if (*str == '\0')
		return (0);
	else if (ft_strchr("cspdiuxX%", *str))
		return (1);
	else
		return (0);
}

int	ft_process_print(va_list ap, const char **str, t_para *para, int *p_count)
{
	if (**str == '\0')
		return (0);
	ft_memset(para, 0, sizeof(t_para));
	if (ft_find_format(*str))
	{
		if (ft_make_struct(str, para) == -1)
			return (-1);
		if (ft_print_format(ap, para, p_count) == -1)
			return (-1);
	}
	return (1);
}
