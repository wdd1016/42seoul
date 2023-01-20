/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_compression.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:56:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 12:18:54 by juyojeon         ###   ########.fr       */
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
	i = 0;
	while (++i < stk->size)
		if (temparr[i] < temparr[i - 1])
			break;
	if (i == stk->size)
	{
		free(temparr);
		free(stk->array);
		exit(0);
	}
	if (ft_timsort(temparr, stk->size) == 0)
	{
		free(temparr);
		ft_error_ps(stk);
	}
	i = 0;
	while (++i < stk->size)
		if (temparr[i] == temparr[i-1])
		{
			free(temparr);
			ft_error_ps(stk);
		}
	i = -1;
	while (++i < stk->size)
		(stk->array)[i] = ft_binsearch(temparr, (stk->array)[i], stk->size);
	free(temparr);
}
// an array of n -> (0 ~ n-1 value) coordination compression

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
// mid = index (0 ... n-1)