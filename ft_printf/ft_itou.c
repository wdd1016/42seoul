/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:55:45 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/02 22:43:43 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_to_c(char *str, unsigned int nbr, unsigned int nbr_len)
{
	if (nbr > 0)
	{
		str[nbr_len - 1] = '0' + (nbr % 10);
		ft_convert_to_c(str, nbr / 10, nbr_len - 1);
	}
}

unsigned int	ft_len_of_unsigned_int(unsigned int nbr)
{
	unsigned int	nbr_len;

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

char	*ft_itou(unsigned int n)
{
	char			*str_u;
	unsigned int	nbr_len;

	nbr_len = ft_len_of_unsigned_int(n);
	str_u = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str_u)
		return (0);
	str_u[nbr_len] = '\0';
	ft_convert_to_c(str_u, n, nbr_len);
	if (n == 0)
		*str_u = '0';
	return (str_u);
}
