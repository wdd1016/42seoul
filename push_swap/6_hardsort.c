/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_hardsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:53:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/19 03:39:32 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_hardsorting3a(t_stacks *stk, t_elemt *data, int first);
static void	ft_hardsorting3b(t_stacks *stk, t_elemt *data, int first);
static void	ft_hardsorting45a(t_stacks *stk, t_procstk now, int count);
static void	ft_hardsorting45b(t_stacks *stk, t_procstk now, int count);

void	ft_hardsorting(t_stacks *stk, int name, int count, t_procstk now)
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
	else if (count == 4 && name == A)
		ft_hardsorting4a(stk, now, count);
	else if (count == 4 && name == B)
		ft_hardsorting4b(stk, now, count);
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
		rotateorder(stk, RB, stk->b);
		swaporder(stk, SB, stk->b);
		pushorder(stk, PA, stk->b, stk->a);
		if (data[first] < data[third])
		{
			pushorder(stk, PA, stk->b, stk->a);
			reverseorder(stk, RRB, stk->b);
			pushorder(stk, PA, stk->b, stk->a);
		}
		else
		{
			reverseorder(stk, RRB, stk->b);
			pushorder(stk, PA, stk->b, stk->a);
			pushorder(stk, PA, stk->b, stk->a);
		}
	}
}

static void	ft_hardsorting45a(t_stacks *stk, t_procstk now, int count)
{
	int	pivot;
	int	big_count;
	int	i;

	pivot = now.min + count / 2;
	big_count = now.max - pivot + 1;
	i = -1;
	while (++i < count)
	{
		if ((stk->a->data)[stk->a->front] < pivot)
			pushorder(stk, PB, stk->a, stk->b);
		else
			rotateorder(stk, RA, stk->a);
	}
	i = -1;
	while (++i < big_count)
		reverseorder(stk, RRA, stk->a);
	ft_hardsorting(stk, A, big_count, now);
	ft_hardsorting(stk, B, 2, now);
}

static void	ft_hardsorting45b(t_stacks *stk, t_procstk now, int count)
{
	int	pivot;
	int	big_count;
	int	i;

	pivot = now.min + count / 2;
	big_count = now.max - pivot + 1;
	i = -1;;
	while (++i < count)
	{
		if ((stk->b->data)[stk->b->front] >= pivot)
			pushorder(stk, PA, stk->b, stk->a);
		else
			rotateorder(stk, RB, stk->b);
	}
	i = -1;
	while (++i < 2)
		reverseorder(stk, RRB, stk->b);
	ft_hardsorting(stk, A, big_count, now);
	ft_hardsorting(stk, B, 2, now);
}