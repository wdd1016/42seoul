/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_make_struct_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:48:31 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:54:46 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_para_flag(const char **str, t_para *para)
{
	int	i;

	if (**str == '-' && ((para->flag & FLAG_MINUS) == 0))
		i = 1;
	else if (**str == '0' && ((para->flag & FLAG_ZERO) == 0))
		i = 2;
	else if (**str == '#' && ((para->flag & FLAG_SHARP) == 0))
		i = 4;
	else if (**str == ' ' && ((para->flag & FLAG_SPACE) == 0))
		i = 8;
	else if (**str == '+' && ((para->flag & FLAG_PLUS) == 0))
		i = 16;
	else
		i = 0;
	para->flag += i;
	(*str)++;
}

static void	ft_overflow(t_para *para)
{
	para->pre_state = P_OVERFLOW;
	para->precision = 0;
}

static void	ft_atopre(const char **str, t_para *para)
{
	unsigned long long	sum;
	unsigned int		temp;

	sum = 0;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		sum = (sum * 10) + (**str - '0');
		(*str)++;
	}
	if (sum >= 9223372036854775807)
	{
		temp = (unsigned int)sum;
		if (temp >= 2147483647)
			ft_overflow(para);
		else
			para->precision = temp;
	}
	else if (sum >= 2147483647)
		ft_overflow(para);
	else
		para->precision = sum;
}

static int	ft_atowidth(const char **str, t_para *para)
{
	unsigned long long	sum;
	unsigned int		temp;

	sum = 0;
	while (**str >= '0' && **str <= '9')
	{
		sum = (sum * 10) + (**str - '0');
		(*str)++;
	}
	if (sum >= 9223372036854775807)
	{
		temp = (unsigned int)sum;
		if (temp >= 2147483647)
			return (-1);
		para->width = temp;
	}
	else if (sum >= 2147483647)
		return (-1);
	else
		para->width = sum;
	return (1);
}

int	ft_make_struct(const char **str, t_para *para)
{
	while (1)
	{
		if (ft_strchr("-0# +", **str))
			ft_para_flag(str, para);
		else if (**str >= '1' && **str <= '9')
		{
			if (ft_atowidth(str, para) < 0)
				return (-1);
		}
		else if (**str == '.')
		{
			(*str)++;
			para->pre_state = P_ON;
			if ((**str >= '0' && **str <= '9') || **str == '-' || **str == '+')
				ft_atopre(str, para);
		}
		else
			break ;
	}
	para->format = **str;
	(*str)++;
	return (1);
}
