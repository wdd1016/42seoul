/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:31 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/17 22:27:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaporder(t_stacks *stk, int order)
{
	t_elemt	temp;
	t_deque	*a;
	t_deque	*b;

	a = stk->a;
	b = stk->b;
	if (order == SA)
	{
		(a->data)[a->front] = temp;
		(a->data)[a->front] = (a->data)[a->front + 1];
		(a->data)[a->front + 1] = temp;
	}
	else if (order == SB)
	{
		(b->data)[b->front] = temp;
		(b->data)[b->front] = (b->data)[b->front + 1];
		(b->data)[b->front + 1] = temp;	
	}
}

void	pushorder(t_stacks *stk, int order)
{
	t_deque	*a;
	t_deque	*b;

	a = stk->a;
	b = stk->b;
	if (order == PA)
	{
		a->front = (a->front - 1 + stk->size) % stk->size;
		(a->data)[a->front] = (b->data)[b->front];
		b->front = (b->front + 1) % stk->size;
	}
	else if (order == PB)
	{
		b->front = (b->front - 1 + stk->size) % stk->size;
		(b->data)[b->front] = (a->data)[a->front];
		a->front = (a->front + 1) % stk->size;
	}
}

void	rotateorder(t_stacks *stk, int order)
{
	t_deque	*a;
	t_deque	*b;

	a = stk->a;
	b = stk->b;
	if (order == RA || order == RAA)
	{
		a->rear = (a->rear + 1) % stk->size;
		(a->data)[a->rear] = (a->data)[a->front];
		a->front = (a->front + 1) % stk->size;
	}
	else if (order == RB || order == RBB)
	{
		b->rear = (b->rear + 1) % stk->size;
		(b->data)[b->rear] = (b->data)[b->front];
		b->front = (b->front + 1) % stk->size;
	}
}

void	reverseorder(t_stacks *stk, int order)
{
	t_deque	*a;
	t_deque	*b;

	a = stk->a;
	b = stk->b;
	if (order == RRA)
	{
		a->front = (a->front - 1 + stk->size) % stk->size;
		(a->data)[a->front] = (a->data)[a->rear];
		a->rear = (a->rear - 1 + stk->size) % stk->size;
	}
	else if (order == RRB)
	{
		b->front = (b->front - 1 + stk->size) % stk->size;
		(b->data)[b->front] = (b->data)[b->rear];
		b->rear = (b->rear - 1 + stk->size) % stk->size;
	}
}

void	doubleorder(t_stacks *stk, int order)
{
	if (order == RR)
	{
		rotateorder(stk, RAA);
		rotateorder(stk, RBB);
	}
	else if (order == RRR)
	{
		reverseorder(stk, RRAA);
		reverseorder(stk, RRBB);
	}
}