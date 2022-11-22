/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:33:20 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/11 15:27:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_num_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base [i + j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_base_write(int nbr, char *base, int base_num)
{
	if (nbr == -2147483648)
	{
		ft_base_write(nbr / base_num, base, base_num);
		write(1, base - (nbr % base_num), 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_base_write(-nbr, base, base_num);
	}
	else if (nbr < base_num)
		write(1, base + nbr, 1);
	else
	{
		ft_base_write(nbr / base_num, base, base_num);
		write(1, base + (nbr % base_num), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_number;

	base_number = ft_base_num_valid(base);
	if (base_number > 0)
		ft_base_write(nbr, base, base_number);
}
