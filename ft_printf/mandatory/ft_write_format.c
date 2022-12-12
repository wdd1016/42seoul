/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:14:08 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 20:35:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_mandatory.h"

int	ft_write_char(va_list ap, int *print_count)
{
	char	c;

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
	len = ft_strlen(str);
	if (write(1, str, len) < 0)
		return (-1);
	(*print_count) += len;
	return (1);
}

int	ft_write_int(va_list ap, int *print_count)
{
	int		i;

	i = va_arg(ap, int);
	if (ft_itoa(i, print_count) == -1)
		return (-1);
	else
		return (1);
}
