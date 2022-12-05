/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:55:45 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/05 20:51:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_to_c(char *str, int nbr, int nbr_len)
{
	if (nbr < 0)
	{
		str[nbr_len - 1] = '0' - (nbr % 10);
		ft_convert_to_c(str, nbr / 10, nbr_len - 1);
	}
	else if (nbr > 0)
	{
		str[nbr_len - 1] = '0' + (nbr % 10);
		ft_convert_to_c(str, nbr / 10, nbr_len - 1);
	}
}

static int	ft_len_of_int(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_itoa(int n, int *print_count)
{
	char	*str_int;
	int		nbr_len;

	nbr_len = ft_len_of_int(n);
	str_int = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str_int)
		return (-1);
	str_int[nbr_len] = '\0';
	ft_convert_to_c(str_int, n, nbr_len);
	if (n == 0)
		*str_int = '0';
	else if (n < 0)
		*str_int = '-';
	if (write(1, str_int, nbr_len) < 0)
	{
		free(str_int);
		return (-1);
	}
	(*print_count) += nbr_len;
	free(str_int);
	return (1);
}
