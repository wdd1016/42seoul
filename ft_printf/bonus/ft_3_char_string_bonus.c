/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_char_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:03:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:54:49 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_write_spacezero(int count, char target)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(sizeof(char) * (count + 1));
	if (!arr)
		return (-1);
	i = 0;
	while (i < count)
		arr[i++] = target;
	arr[i] = '\0';
	if (write(1, arr, count) < 0)
	{
		free(arr);
		return (-1);
	}
	free(arr);
	return (1);
}

int	ft_write_char(va_list ap, t_para *para, int *print_count)
{
	char	ch;

	ch = '%';
	if (para->format == 'c')
		ch = va_arg(ap, int);
	if ((para->flag & FLAG_MINUS) == FLAG_MINUS)
	{
		if (write(1, &ch, 1) < 0)
			return (-1);
	}
	if (para->width > 1)
	{
		if (ft_write_spacezero(para->width - 1, ' ') < 0)
			return (-1);
		(*print_count) += para->width - 1;
	}
	if ((para->flag & FLAG_MINUS) == 0)
	{
		if (write(1, &ch, 1) < 0)
			return (-1);
	}
	(*print_count)++;
	return (1);
}

static int	ft_bonus_string(const char *str, t_para *para, int *p_count)
{
	int	len;
	int	count_space;

	len = ft_strlen(str);
	if (len > para->precision && para->pre_state == P_ON)
		len = para->precision;
	if ((para->flag & FLAG_MINUS) == FLAG_MINUS && len > 0)
		if (write(1, str, len) < 0)
			return (-1);
	count_space = para->width - len;
	if (count_space > 0)
	{
		if (ft_write_spacezero(count_space, ' ') < 0)
			return (-1);
		(*p_count) += para->width;
	}
	else
		(*p_count) += len;
	if ((para->flag & FLAG_MINUS) == 0 && len > 0)
		if (write(1, str, len) < 0)
			return (-1);
	return (1);
}

int	ft_write_string(va_list ap, t_para *para, int *print_count)
{
	const char	*str;

	str = va_arg(ap, const char *);
	if (!str)
		str = "(null)";
	if (ft_bonus_string(str, para, print_count) == -1)
		return (-1);
	return (1);
}
