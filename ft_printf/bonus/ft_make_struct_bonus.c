/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:48:31 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/02 22:33:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static unsigned long long	ft_atollu(const char **str)
{
	unsigned long long	sum;

	sum = 0;
	while (**str >= '0' && **str <= '9')
	{
		sum = (sum * 10) + (**str - '0');
		(*str)++;
	}
	return (sum);
}

void	ft_make_struct(const char **str, t_para *para)
{
	while (1)
	{
		if (ft_strchr("-0# +", **str))
			ft_para_flag(str, para);
		else if (**str >= '1' && **str <= '9')
			para->width = ft_atollu(str);
		else if (**str == '.')
		{
			(*str)++;
			if (**str >= '1' && **str <= '9')
				para->precision = ft_atollu(str);
			else
				para->precision = 0;
		}
		else
			break ;
	}
	if (ft_strchr("cspdiuxX", **str))
	{
		para->format = **str;
		(*str)++;
	}
}
