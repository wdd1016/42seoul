/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:20:35 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/26 17:01:27 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str_count(const char *str, int *count)
{
	if (write(1, *str, 1) < 0)
		return (-1);
	(*count)++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_para	parameter;
	int		count;
	int		temp;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			temp = ft_process_print(ap, str + 1, &parameter, &count);
			if (temp == -1)
				return (-1);
			str += temp;
		}
		else
		{
			if (ft_write_str_count(str, &count) == -1)
				return (-1);
			str++;
		}
	}
	va_end(ap);
	return (count);
}
/* 완료시 문자수, 실패시 -1 반환 */