/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:20:35 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/18 20:09:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_para	parameter;
	int		count;

	count = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_process_print(ap, &str, &parameter, &count) == -1)
				return (-1);
		}
		else
		{
			if (write(1, str, 1) < 0)
				return (-1);
			count++;
			str++;
		}
	}
	va_end(ap);
	return (count);
}
