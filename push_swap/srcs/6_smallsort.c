/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_smallsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 04:24:14 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 13:09:58 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorting_three(t_stacks *stk);
static void	ft_sorting_four(t_stacks *stk, int count, int pivot);
static void	ft_sorting_five(t_stacks *stk, int count, int pivot);

void	ft_smallsort(t_stacks *stk)
{
	if (stk->size <= 2)
		ft_hardsorting(stk, A, stk->size);
	if (stk->size == 3)
		ft_sorting_three(stk);
	else if (stk->size == 4)
		ft_sorting_four(stk, 4, 0);
	else if (stk->size == 5)
		ft_sorting_five(stk, 5, 1);
}
static void	ft_sorting_three(t_stacks *stk)
{
	int	first;
	int	sec;
	int	third;
	int	*data;

	first = stk->a->front;
	sec = (first + 1) % stk->size;
	third = (first + 2) % stk->size;
	data = stk->a->data;
	if (data[first] > data[sec] && data[first] > data[third])
		rotateorder(stk, RA, stk->a);
	else if (data[sec] > data[first] && data[sec] > data[third])
		reverseorder(stk, RRA, stk->a);
	sec = (stk->a->front + 1) % stk->size;
	if (data[stk->a->front] > data[sec])
		swaporder(stk, SA, stk->a);
}

static void	ft_sorting_four(t_stacks *stk, int count, int pivot)
{
	int	*data;

	data = stk->a->data;
	while (count-- > 0)
	{
		if (data[stk->a->front] == pivot)
			pushorder(stk, PB, stk->a, stk->b);
		else
			rotateorder(stk, RA, stk->a);
	}
	ft_sorting_three(stk);
	pushorder(stk, PA, stk->b, stk->a);
}

static void	ft_sorting_five(t_stacks *stk, int count, int pivot)
{
	int	*data;

	data = stk->a->data;
	while (count-- > 0)
	{
		if (data[stk->a->front] <= pivot)
			pushorder(stk, PB, stk->a, stk->b);
		else
			rotateorder(stk, RA, stk->a);
	}
	ft_sorting_three(stk);
	ft_hardsorting(stk, B, 2);
}
