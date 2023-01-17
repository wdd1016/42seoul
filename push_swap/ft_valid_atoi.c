/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:04:12 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/18 04:35:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_atoi(t_stacks *stk, const char *str)
{
	int			minus;
	long long	sum;

	minus = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + minus * (*str - '0');
		if (sum < -2147483648 || sum > 2147483647)
			ft_error_ps(stk);
		str++;
	}
	while (*str == ' ')
		str++;
	if (*str != '\0')
		ft_error_ps(stk);
	return ((int)sum);
}
