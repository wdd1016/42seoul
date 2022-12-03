/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_anyway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/03 23:30:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
/*
static int	ft_isspace(int c)
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
*/
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	sum;

	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + minus * (*str - '0');
		str++;
	}
	return (sum);
}
// 9223372039002259500
// 9223372039002259458
int main()
{
	int i = ft_atoi("21474836401");
	char	*str = "214748364915";
	i = 123;
	i = printf("%p\np%p\n%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
//	printf("%p\n", 0);
	printf("%d", i);

}
