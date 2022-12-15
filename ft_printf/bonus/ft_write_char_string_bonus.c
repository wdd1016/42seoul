/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char_string_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:03:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 22:58:06 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_write_char(va_list ap, t_para *para, int *print_count)
{
	char	c;
	int		i;

	c = va_arg(ap, int);
	if ((para->flag & FLAG_MINUS) == 1)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
	}
	i = 0;
	while (++i < para->width)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
	}
	if ((para->flag & FLAG_MINUS) == 0)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
	}
	(*print_count) += para->width;
	return (1);
}

static int	ft_bonus_string(const char *str, t_para *para, int *p_count)
{
	int	len;
	int	i;
	int	count_space;

	len = ft_strlen(str);
	if (len > para->precision && para->pre_state == P_ON)
		len = para->precision;
	if ((para->flag & FLAG_MINUS) == 1 && len > 0)
		if (write(1, str, len) < 0)
			return (-1);
	i = 0;
	count_space = para->width - len;
	while (i++ < count_space)
		if (write(1, " ", 1) < 0)
			return (-1);
	if ((para->flag & FLAG_MINUS) == 0 && len > 0)
		if (write(1, str, len) < 0)
			return (-1);
	(*p_count) += para->width;
	return (1);
}

int	ft_write_string(va_list ap, t_para *para, int *print_count)
{
	const char	*str;

	str = va_arg(ap, const char *);
	if (!str)
	{
		if (write(1, ("(null)"), 6) < 0)
			return (-1);
		(*print_count) += 6;
	}
	else
	{
		if (ft_bonus_string(str, para, print_count) == -1)
			return (-1);
	}
	return (1);
} 
