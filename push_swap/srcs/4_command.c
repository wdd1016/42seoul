/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:31 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 13:09:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaporder(t_stacks *stk, int order, t_deque *target)
{
	int	next;
	int	temp;

	next = (target->front + 1) % stk->size;
	temp = (target->data)[target->front];
	(target->data)[target->front] = (target->data)[next];
	(target->data)[next] = temp;
	if (order == SA)
	{
		if (write(1, "sa\n", 3) < 3)
			ft_error_ps(stk);
	}
	else if (order == SB)
	{
		if (write(1, "sb\n", 3) < 3)
			ft_error_ps(stk);
	}
}

void	pushorder(t_stacks *stk, int order, t_deque *from, t_deque *to)
{
	to->front = (to->front - 1 + stk->size) % stk->size;
	(to->data)[to->front] = (from->data)[from->front];
	from->front = (from->front + 1) % stk->size;
	if (order == PA)
	{
		if (write(1, "pa\n", 3) < 3)
			ft_error_ps(stk);		
	}
	else if (order == PB)
	{
		if (write(1, "pb\n", 3) < 3)
			ft_error_ps(stk);
	}
}

void	rotateorder(t_stacks *stk, int order, t_deque *target)
{
	target->rear = (target->rear + 1) % stk->size;
	(target->data)[target->rear] = (target->data)[target->front];
	target->front = (target->front + 1) % stk->size;
	if (order == RA)
	{
		if (write(1, "ra\n", 3) < 3)
			ft_error_ps(stk);
	}
	else if (order == RB)
	{
		if (write(1, "rb\n", 3) < 3)
			ft_error_ps(stk);		
	}
}

void	reverseorder(t_stacks *stk, int order, t_deque *target)
{
	target->front = (target->front - 1 + stk->size) % stk->size;
	(target->data)[target->front] = (target->data)[target->rear];
	target->rear = (target->rear - 1 + stk->size) % stk->size;
	if (order == RRA)
	{
		if (write(1, "rra\n", 4) < 4)
			ft_error_ps(stk);
	}
	else if (order == RRB)
	{
		if (write(1, "rrb\n", 4) < 4)
			ft_error_ps(stk);
	}
}

void	doubleorder(t_stacks *stk, int order)
{
	if (order == RR)
	{
		rotateorder(stk, DOUB, stk->a);
		rotateorder(stk, DOUB, stk->b);
		if (write(1, "rr\n", 3) < 3)
			ft_error_ps(stk);
	}
	else if (order == RRR)
	{
		reverseorder(stk, DOUB, stk->a);
		reverseorder(stk, DOUB, stk->b);
		if (write(1, "rrr\n", 4) < 4)
			ft_error_ps(stk);
	}
}
