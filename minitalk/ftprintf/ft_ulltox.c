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

static size_t	ft_len_of_x(size_t nbr);
static void	ft_convert_to_small(char *str, size_t nbr, size_t nbr_len);
static void	ft_convert_to_big(char *str, size_t nbr, size_t nbr_len);

int	ft_ulltox(size_t n, int *print_count, t_para *para)
{
	char	*str_x;
	size_t	nbr_len;

	nbr_len = ft_len_of_x(n);
	str_x = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str_x)
		return (-1);
	str_x[nbr_len] = '\0';
	if (para->format == 'p' || para->format == 'x')
		ft_convert_to_small(str_x, n, nbr_len);
	else
		ft_convert_to_big(str_x, n, nbr_len);
	if (write(1, str_x, nbr_len) < 0)
	{
		free(str_x);
		return (-1);
	}
	free(str_x);
	(*print_count) += nbr_len;
	return (1);
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

static void	ft_convert_to_small(char *str, size_t nbr, size_t nbr_len)
{
	size_t		nbr_idx;
	const char	*base = "0123456789abcdef";

	nbr_idx = nbr_len - 1;
	if (nbr > 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[nbr % 16];
			nbr_idx--;
			nbr /= 16;
		}
	}
	else
		str[0] = '0';
}

static void	ft_convert_to_big(char *str, size_t nbr, size_t nbr_len)
{
	size_t		nbr_idx;
	const char	*base = "0123456789ABCDEF";

	nbr_idx = nbr_len - 1;
	if (nbr > 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[nbr % 16];
			nbr_idx--;
			nbr /= 16;
		}
	}
	else
		str[0] = '0';
}
