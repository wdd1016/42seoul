/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:04:12 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/14 23:52:12 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	arr_size;
	char	*temp;
	void	*ptr;

	arr_size = size * count;
	ptr = malloc(arr_size);
	if (!ptr)
		return (0);
	i = 0;
	temp = (char *)ptr;
	while (i < arr_size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_valid_atoi(t_stacks *stk, const char *str)
{
	int			minus;
	long long	sum;

	minus = 1;
	while (*str == ' ')
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
		if (sum < -2147483648 || sum > 2147483647)
			ft_error_ps(stk);
		str++;
	}
	return ((int)sum);
}