/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_hardsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:53:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 05:31:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_hardsorting3a(t_stacks *stk, t_elemt *data, int first);
static void	ft_hardsorting3b(t_stacks *stk, t_elemt *data, int first);

void	ft_hardsorting(t_stacks *stk, int name, int count)
{
	int	temp;

	if (count == 1 && name == B)
		pushorder(stk, PA, stk->b, stk->a);
	else if (count == 2 && name == A)
	{
		temp = (stk->a->front + 1) % stk->size;
		if ((stk->a->data)[stk->a->front] > (stk->a->data)[temp])
			swaporder(stk, SA, stk->a);
	}
	else if (count == 2 && name == B)
	{
		temp = (stk->b->front + 1) % stk->size;
		if ((stk->b->data)[stk->b->front] < (stk->b->data)[temp])
			swaporder(stk, SB, stk->b);
		pushorder(stk, PA, stk->b, stk->a);
		pushorder(stk, PA, stk->b, stk->a);
	}
	else if (count == 3 && name == A)
		ft_hardsorting3a(stk, stk->a->data, stk->a->front);
	else if (count == 3 && name == B)
		ft_hardsorting3b(stk, stk->b->data, stk->b->front);
}

static void	ft_hardsorting3a(t_stacks *stk, t_elemt *data, int first)
{
	int	sec;
	int	third;

	sec = (first + 1) % stk->size;
	third = (first + 2) % stk->size;
	if (data[first] > data[sec] && data[first] > data[third])
	{
		swaporder(stk, SA, stk->a);
		rotateorder(stk, RA, stk->a);
		swaporder(stk, SA, stk->a);
		reverseorder(stk, RRA, stk->a);
	}
	if (data[sec] > data[first] && data[sec] > data[third])
	{
		rotateorder(stk, RA, stk->a);
		swaporder(stk, SA, stk->a);
		reverseorder(stk, RRA, stk->a);
	}
	if (data[first] > data[sec])
		swaporder(stk, SA, stk->a);
}

static void	ft_hardsorting3b(t_stacks *stk, t_elemt *data, int first)
{
	int	sec;
	int	third;

	sec = (first + 1) % stk->size;
	third = (first + 2) % stk->size;
	if (data[sec] > data[first] && data[sec] > data[third])
		swaporder(stk, SB, stk->b);
	if (data[first] > data[sec] && data[first] > data[third])
	{
		pushorder(stk, PA, stk->b, stk->a);
		if (data[sec] < data[third])
			swaporder(stk, SB, stk->b);
		pushorder(stk, PA, stk->b, stk->a);
		pushorder(stk, PA, stk->b, stk->a);
	}
	else
	{
		if (data[first] > data[sec])
			swaporder(stk, SB, stk->b);
		reverseorder(stk, RRB, stk->b);
		pushorder(stk, PA, stk->b, stk->a);
		pushorder(stk, PA, stk->b, stk->a);
		pushorder(stk, PA, stk->b, stk->a);
	}
}
