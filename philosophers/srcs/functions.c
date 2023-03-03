/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:39:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/03 21:17:45 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long	sum;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (0);
	return (sum);
}

size_t	ft_strlen(const char *s)
{
	const char	*copy;

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

