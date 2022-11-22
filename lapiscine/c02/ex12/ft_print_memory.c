/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:04:55 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/08 10:53:49 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_write(unsigned char num)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (num < 16)
		write(1, hexa + num, 1);
	else
	{
		write(1, hexa + (num / 16), 1);
		write(1, hexa + (num % 16), 1);
	}
}

void	ft_string_printable_write(unsigned char *string)
{
	int		i;

	i = 0;
	while (i < 16 && *(string + i) != '\0')
	{
		if (*(string + i) < ' ' || *(string + i) > '~')
			write(1, ".", 1);
		else
			write(1, string + i, 1);
		i++;
	}
	if (i < 16 && *(string + i) == '\0')
		write(1, ".", 1);
}

void	ft_string_hex_write(unsigned char *string)
{
	int	i;
	int	null_count;

	i = 0;
	null_count = 0;
	while (i < 16)
	{
		if (null_count == 0 && *(string + i) == 0)
		{
			write(1, "00", 2);
			null_count++;
		}
		else if (null_count > 0)
			write(1, "  ", 2);
		else if (*(string + i) >= 16)
			hex_write(*(string + i));
		else
		{
			write(1, "0", 1);
			hex_write(*(string + i));
		}
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	memory_address_write(unsigned long long address)
{
	unsigned char	mod;

	if (address < 16)
	{
		mod = address;
		hex_write(mod);
	}
	else
	{
		memory_address_write(address / 16);
		mod = address % 16;
		hex_write(mod);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	address;
	unsigned int		i;
	unsigned char		*ch_addr;

	ch_addr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		address = (unsigned long long)ch_addr + 16 * i;
		memory_address_write(address);
		write(1, ": ", 2);
		ft_string_hex_write(ch_addr + 16 * i);
		ft_string_printable_write(ch_addr + 16 * i);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
