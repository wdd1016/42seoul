/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:20:35 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/02 22:46:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_para	parameter;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
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
/* 완료시 문자수, 실패시 -1 반환 */