/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abstoa_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:55:45 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 07:02:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_convert_to_c(char *str, long long nbr, int nbr_len)
{
	int			nbr_idx;
	const char	*base = "0123456789";

	nbr_idx = nbr_len - 1;
	if (nbr < 0)
	{
		nbr *= -1;
		while (nbr != 0)
		{
			str[nbr_idx] = base[nbr % 10];
			nbr_idx--;
			nbr /= 10;
		}
	}
	else if (nbr > 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[nbr % 10];
			nbr_idx--;
			nbr /= 10;
		}
	}
	else
		str[0] = '0';
}

int	ft_len_of_abs(long long nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_abstoa(long long n, int *print_count)
{
	char	*str_int;
	int		nbr_len;

	nbr_len = ft_len_of_abs(n);
	str_int = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str_int)
		return (-1);
	str_int[nbr_len] = '\0';
	ft_convert_to_c(str_int, n, nbr_len);
	if (write(1, str_int, nbr_len) < 0)
	{
		free(str_int);
		return (-1);
	}
	(*print_count) += nbr_len;
	free(str_int);
	return (1);
}
