/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:48:31 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 20:36:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_para_flag(const char **str, t_para *para)
{
	int	i;

	if (**str == '-' && ((para->flag & 1) == 0))
		i = 1;
	else if (**str == '0' && ((para->flag & 2) == 0))
		i = 2;
	else if (**str == '#' && ((para->flag & 4) == 0))
		i = 4;
	else if (**str == ' ' && ((para->flag & 8) == 0))
		i = 8;
	else if (**str == '+' && ((para->flag & 16) == 0))
		i = 16;
	else
		i = 0;
	para->flag += i;
	(*str)++;
}

static int	ft_check_minus(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	else if (**str == '+')
		(*str)++;
	return (1);
}
/*
static int	ft_atoprecision(const char **str, t_para *para, \
int *p_count, unsigned long long sum)
{
	unsigned int	temp;
	int				i;

	i = ft_check_minus(str);
	while (**str >= '0' && **str <= '9')
	{
		sum = (sum * 10) + (**str - '0');
		(*str)++;
	}
	sum += *p_count;
	if (sum >= 9223372036854775807)
	{
		temp = (unsigned int)sum;
		if (temp >= 2147483647)
			return (-1);
		temp -= *p_count;
		para->precision = i * temp;
	}
	else if (sum >= 2147483647)
		return (-1);
	else
		para->precision = i * (sum - *p_count);
	return (1);
}
*/

static void	ft_atopre(const char **str, t_para *para)
{
	unsigned long long	sum;

	sum = 0;
	para->minus = ft_check_minus(str);
	while (**str >= '0' && **str <= '9')
	{
		sum = (sum * 10) + (**str - '0');
		(*str)++;
	}
	para->precision = sum;
}

static int	ft_atowidth(const char **str, t_para *para, int *p_count)
{
	unsigned long long	sum;
	unsigned int		temp;

	sum = 0;
	while (**str >= '0' && **str <= '9')
	{
		sum = (sum * 10) + (**str - '0');
		(*str)++;
	}
	sum += *p_count;
	if (sum >= 9223372036854775807)
	{
		temp = (unsigned int)sum;
		if (temp >= 2147483647)
			return (-1);
		para->width = temp - *p_count;
	}
	else if (sum >= 2147483647)
		return (-1);
	else
		para->width = sum - *p_count;
	return (1);
}

int	ft_make_struct(const char **str, t_para *para, int *p_count)
{
	while (1)
	{
		if (ft_strchr("-0# +", **str))
			ft_para_flag(str, para);
		else if (**str >= '1' && **str <= '9')
		{
			if (ft_atowidth(str, para, p_count) < 0)
				return (-1);
		}
		else if (**str == '.')
		{
			(*str)++;
			if ((**str >= '1' && **str <= '9') || **str == '-' || **str == '+')
				ft_atopre(str, para);
		}
		else
			break ;
	}
	if (ft_strchr("cspdiuxX", **str))
	{
		para->format = **str;
		(*str)++;
	}
	return (1);
}
