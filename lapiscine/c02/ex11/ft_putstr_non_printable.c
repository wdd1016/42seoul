/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:04:02 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/08 10:13:38 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_non_printable(char *str_now)
{
	char	*hexa;
	int		i;
	char	bslash;

	bslash = '\\';
	hexa = "0123456789abcdef";
	i = (unsigned char)*str_now;
	write(1, &bslash, 1);
	if (i < 16)
	{
		write(1, "0", 1);
		write(1, hexa + i, 1);
	}
	else
	{
		write(1, hexa + (i / 16), 1);
		write(1, hexa + (i % 16), 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= ' ' && *(str + i) <= '~')
			write(1, str + i, 1);
		else
			write_non_printable(str + i);
		i++;
	}
}
