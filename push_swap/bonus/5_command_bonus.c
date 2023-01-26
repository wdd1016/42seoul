/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_command_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:31 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 22:20:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swaporder(t_stacks *stk, t_deque *target)
{
	int	next;
	int	temp;

	if (target->front == target->rear || target->rear == -1)
		return ;
	next = (target->front + 1) % stk->size;
	temp = (target->data)[target->front];
	(target->data)[target->front] = (target->data)[next];
	(target->data)[next] = temp;
}

void	pushorder(t_stacks *stk, t_deque *from, t_deque *to)
{
	if (from->rear == -1)
		return ;
	to->front = (to->front - 1 + stk->size) % stk->size;
	(to->data)[to->front] = (from->data)[from->front];
	if (to->rear == -1)
		to->rear = to->front;
	if (from->front == from->rear)
		from->rear = -1;
	else
		from->front = (from->front + 1) % stk->size;
}

void	rotateorder(t_stacks *stk, t_deque *target)
{
	if (target->rear == -1)
		return ;
	target->rear = (target->rear + 1) % stk->size;
	(target->data)[target->rear] = (target->data)[target->front];
	target->front = (target->front + 1) % stk->size;
}

void	reverseorder(t_stacks *stk, t_deque *target)
{
	if (target->rear == -1)
		return ;
	target->front = (target->front - 1 + stk->size) % stk->size;
	(target->data)[target->front] = (target->data)[target->rear];
	target->rear = (target->rear - 1 + stk->size) % stk->size;
}

void	doubleorder(t_stacks *stk, int order)
{
	if (order == SS)
	{
		swaporder(stk, stk->a);
		swaporder(stk, stk->b);
	}
	else if (order == RR)
	{
		rotateorder(stk, stk->a);
		rotateorder(stk, stk->b);
	}
	else if (order == RRR)
	{
		reverseorder(stk, stk->a);
		reverseorder(stk, stk->b);
	}
}
