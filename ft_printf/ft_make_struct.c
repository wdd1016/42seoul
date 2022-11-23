/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:48:31 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/24 00:26:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_para_flag(const char *str, t_para *para, int *len_count)
{
	if (*str == '-')
		para->flag = '-';
	else if (*str == '0')
		para->flag = '0';
	else if (*str == '#')
		para->flag = '#';
	else if (*str == ' ')
		para->flag = ' ';
	else
		para->flag = '+';
	(*len_count)++;
}

int	ft_para_width(const char *str, t_para *para, int *len_count)
{
	
}

int ft_para_precision(const char *str, t_para *para, int *len_count)
{
	
}

int	ft_make_struct(const char *str, t_para *para, int *len_count)
{
	if (*str == '-' || *str == '0' || *str == '#' || *str == ' ' || *str == '+')
	{
		ft_para_flag(str, para, len_count);
		str++;
	}
	if (*str >= '1', *str <= '9')
	{
		str = str + ft_para_width(str, para, len_count);
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
