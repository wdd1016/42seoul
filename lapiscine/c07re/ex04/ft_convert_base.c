/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:41:59 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/14 21:19:10 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	ft_atoi_base(char *str, char *base);
extern int	base_num_valid(char *base);

int	ft_nbr_len(int nbr_int, int base_num)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr_int <= 0)
		nbr_len++;
	while (nbr_int)
	{
		nbr_int /= base_num;
		nbr_len++;
	}
	return (nbr_len);
}

void	ft_int_convert(int *array, int nbr_int, int nbr_len, int base_num)
{
	if (nbr_int < 0)
	{
		array[nbr_len - 1] = -(nbr_int % base_num);
		ft_int_convert(array, nbr_int / base_num, nbr_len - 1, base_num);
	}
	else if (nbr_int > 0)
	{
		array[nbr_len - 1] = (nbr_int % base_num);
		ft_int_convert(array, nbr_int / base_num, nbr_len - 1, base_num);
	}
}

void	ft_str_convert_to_base(char *str, int *array, char *base, int nbr_len)
{
	int	i;

	i = 0;
	if (array[0] == -1)
	{
		str[0] = '-';
		i++;
	}
	while (i < nbr_len)
	{
		str[i] = base[array[i]];
		i++;
	}
	str[nbr_len] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str_convert;
	int		*i_array;
	int		nbr_len;
	int		nbr_int;
	int		base_num;

	if (!base_num_valid(base_from) || !base_num_valid(base_to))
		return (0);
	nbr_int = ft_atoi_base(nbr, base_from);
	base_num = base_num_valid(base_to);
	nbr_len = ft_nbr_len(nbr_int, base_num);
	i_array = (int *)malloc(sizeof(int) * nbr_len);
	ft_int_convert(i_array, nbr_int, nbr_len, base_num);
	if (nbr_int == 0)
		i_array[0] = 0;
	if (nbr_int < 0)
		i_array[0] = -1;
	str_convert = (char *)malloc(sizeof(char) * (nbr_len + 1));
	ft_str_convert_to_base(str_convert, i_array, base_to, nbr_len);
	free(i_array);
	return (str_convert);
}
/*
#include <stdio.h>

int	main ()
{
	char *strnum;
	char *base1;
	char *base2;

	strnum = "     --+--54923562";
	base1 = "0123456789";
	base2 = "0123456789abcdef";
	printf("%s\n", ft_convert_base(strnum, base1, base2));
	return 0;
}
*/