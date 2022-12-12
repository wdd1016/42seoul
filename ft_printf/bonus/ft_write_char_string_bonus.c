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
	char			c;
	unsigned int	i;

	c = va_arg(ap, int);
	if (para->width >= 2147483647)
		return (-1);
	if ((para->flag & 1) == 1)
		if (write(1, &c, 1) < 0)
			return (-1);
	i = 0;
	while (++i < para->width)
		if (write(1, " ", 1) < 0)
			return (-1);
	if ((para->flag & 1) == 0)
		if (write(1, &c, 1) < 0)
			return (-1);
	(*print_count)++;
	return (1);
}

static int	ft_minus_string(t_para *para, int *p_count)
{
	unsigned long long	sum;
	unsigned int		temp;

	sum = para->precision;
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
	temp = 0;
	while (temp++ < para->width)
		if (write(1, " ", 1) < 0)
			return (-1);
	return (1);
}

static int	ft_bonus_string(char *str, t_para *para, int *p_count)
{
	size_t			len;
	unsigned int	i;

	len = ft_strlen(str);
	if (len > para->precision && para->minus != 0)
		len = para->precision;
	i = 0;
	if ((para->flag & 1) == 1)
		if (write(1, str, len) < 0)
			return (-1);
	while (i++ < (para->width - len))
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		(*p_count)++;
	}
	if ((para->flag & 1) == 0)
		if (write(1, str, len) < 0)
			return (-1);
	(*p_count) += len;
	return (1);
}

int	ft_write_string(va_list ap, t_para *para, int *print_count)
{
	char			*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		if (write(1, ("(null)"), 6) < 0)
			return (-1);
		(*print_count) += 6;
	}
	else if (para->minus == -1)
	{
		if (ft_minus_string(para, print_count) == -1)
			return (-1);
		(*print_count) += para->width;
	}
	else
	{
		if (ft_bonus_string(str, para, print_count) == -1)
			return (-1);
	}
	return (1);
}
