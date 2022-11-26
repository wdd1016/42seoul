/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:48:31 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/26 17:22:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_para_flag(const char **str, t_para *para, int *len_count)
{
	para->flag = *ft_strchr("-0# +", *str);
	(*len_count)++;
	(*str)++;
}

int	ft_para_width(va_list ap, const char *str, t_para *para, int *len_count)
{
	int i;

	if (*str == '*')
	{
		va_arg(ap, int);
	}
}

int ft_para_precision(const char *str, t_para *para, int *len_count)
{
	
}

int	ft_make_struct(va_list ap, const char *str, t_para *para, int *len_count)
{
	int	temp;

	if (*str == '-' || *str == '0' || *str == '#' || *str == ' ' || *str == '+')
		ft_para_flag(&str, para, len_count);
	if ((*str >= '1' && *str <= '9') || *str == '*')
	{
		temp = ft_para_width(ap, str, para, len_count);
		if (temp == -1)
			return (-1);
		str += temp;
	}
	if (*str == '.')
	{
		str++;
		str = str + ft_para_precision(str, para, len_count);
	}
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd' || \
	*str == 'i' || *str == 'u' || *str == 'x')
	{
		para->format = *str;
		(*len_count)++;
	}
}
