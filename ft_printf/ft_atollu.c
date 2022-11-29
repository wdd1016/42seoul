/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:33:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/29 02:35:00 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

unsigned long long	ft_atollu(const char *str)
{
	unsigned long long	sum;

	while (ft_isspace(*str))
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum);
}

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	printf("%llu\n", ft_atollu("922337203685477580789"));
	return 0;
}
