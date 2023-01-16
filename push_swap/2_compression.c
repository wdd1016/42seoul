/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_compression.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:56:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/17 02:49:29 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elemt	ft_binsearch(t_elemt *arr, t_elemt key, int arrsize);

void	ft_coor_compression(t_stacks *stk)
{
	t_elemt	*temparr;
	int		i;

	temparr = (t_elemt *)malloc(sizeof(t_elemt) * stk->size);
	if (!temparr)
		ft_error_ps(stk);
	i = 0;
	while (i < stk->size)
	{
		temparr[i] = (stk->array)[i];
		i++;
	}
	if (ft_timsort(temparr, stk->size) == 0)
		ft_error_ps(stk);
	i = 0;
	while (i < stk->size)
	{
		(stk->array)[i] = ft_binsearch(temparr, (stk->array)[i], stk->size);
		i++;
	}
	free(temparr);
}

static t_elemt	ft_binsearch(t_elemt *arr, t_elemt key, int arrsize)
{
	int	low;
	int	high;
	int mid;

	low = 0;
	high = arrsize - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key)
			return (mid);
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}