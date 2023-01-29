/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:14:08 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/29 19:18:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(va_list ap, int *print_count)
{
	unsigned char	c;

	c = va_arg(ap, int);
	if (write(1, &c, 1) < 0)
		return (-1);
	(*print_count)++;
	return (1);
}

int	ft_write_string(va_list ap, int *print_count)
{
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	if (!str)
	{
		if (write(1, ("(null)"), 6) < 0)
			return (-1);
		(*print_count) += 6;
		return (1);
	}
	len = 0;
	while (str[len])
		len++;
	if (write(1, str, len) < 0)
		return (-1);
	(*print_count) += len;
	return (1);
}

int	ft_write_int(va_list ap, int *print_count, t_para *para)
{
	long long	nbr;

	if (para->format == 'd' || para->format == 'i')
	{
		nbr = va_arg(ap, int);
		if (nbr < 0)
		{
			if (write(1, "-", 1) < 0)
				return (-1);
			(*print_count)++;
		}
	}
	else
		nbr = va_arg(ap, unsigned int);
	if (ft_abstoa(nbr, print_count) == -1)
		return (-1);
	return (1);
}

int	ft_write_16base(va_list ap, int *print_count, t_para *para)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (ft_ulltox(i, print_count, para) == -1)
		return (-1);
	return (1);
}

int	ft_write_ptr(va_list ap, int *print_count, t_para *para)
{
	size_t	i;

	i = (size_t)va_arg(ap, void *);
	if (write(1, "0x", 2) < 0)
		return (-1);
	(*print_count) += 2;
	if (ft_ulltox(i, print_count, para) == -1)
		return (-1);
	return (1);
}
