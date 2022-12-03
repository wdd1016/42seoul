/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:58:36 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/03 23:59:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_to_c(char *str, size_t nbr, size_t nbr_len)
{
	if (nbr > 0)
	{
		if (nbr % 16 > 9)
			str[nbr_len - 1] = 'a' + (nbr % 16) - 10;
		else
			str[nbr_len - 1] = '0' + (nbr % 16);
		ft_convert_to_c(str, nbr / 16, nbr_len - 1);
	}
}

static size_t	ft_len_of_x(size_t nbr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 16;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_ulltox(size_t n, int *print_count)
{
	char	*str_x;
	size_t	nbr_len;

	nbr_len = ft_len_of_x(n);
	str_x = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str_x)
		return (-1);
	str_x[nbr_len] = '\0';
	ft_convert_to_c(str_x, n, nbr_len);
	if (n == 0)
		*str_x = '0';
	if (write(1, "0x", 2) < 0 || write(1, str_x, nbr_len) < 0)
	{
		free(str_x);
		return (-1);
	}
	free(str_x);
	(*print_count) += nbr_len + 2;
	return (1);
}
