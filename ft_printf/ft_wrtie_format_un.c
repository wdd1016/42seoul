/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrtie_format_un.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:50:26 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/03 00:00:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_unsigned(va_list ap, int *print_count)
{
	char			*str_u;
	unsigned int	i;
	int				len;

	i = va_arg(ap, unsigned int);
	len = ft_len_of_unsigned_int(i);
	str_u = ft_itou(i);
	if (!str_u)
		return (-1);
	if (write(1, str_u, len) < 0)
		return (-1);
	free(str_u);
	(*print_count) += len;
	return (1);
}

int	ft_write_16base_us_int_small(va_list ap, int *print_count)
{
	char			*str_x;
	unsigned int	i;
	int				len;

	i = va_arg(ap, unsigned int);
	len = ft_len_of_x(i);
	str_x = ft_ulltox(i);
	if (!str_x)
		return (-1);
	i = 0;
	if (write(1, str_x, len) < 0)
		return (-1);
	free(str_x);
	(*print_count) += len;
	return (1);
}

int	ft_write_16base_us_int_big(va_list ap, int *print_count)
{
	char			*str_x;
	unsigned int	i;
	int				len;

	i = va_arg(ap, unsigned int);
	len = ft_len_of_xx(i);
	str_x = ft_ulltoxx(i);
	if (!str_x)
		return (-1);
	if (write(1, str_x, len) < 0)
		return (-1);
	free(str_x);
	(*print_count) += len;
	return (1);
}

int	ft_write_ptr(va_list ap, int *print_count)
{
	char	*str_x;
	size_t	i;
	int		len;

	i = va_arg(ap, size_t);
	if (i == 0)
	{
		if (write(1, "0x0", 3) < 0)
			return (-1);
		(*print_count) += 3;
		return (1);
	}
	len = ft_len_of_x(i);
	str_x = ft_ulltox(i);
	if (!str_x)
		return (-1);
	if (write(1, "0x", 2) < 0)
		return (-1);
	if (write(1, str_x, len) < 0)
		return (-1);
	free(str_x);
	(*print_count) += len + 2;
	return (1);
}
