/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_command_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:31 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 00:04:36 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swaporder(t_stacks *stk, t_deque *target)
{
	int	next;
	int	temp;

	next = (target->front + 1) % stk->size;
	temp = (target->data)[target->front];
	(target->data)[target->front] = (target->data)[next];
	(target->data)[next] = temp;
}

void	pushorder(t_stacks *stk, t_deque *from, t_deque *to)
{
	to->front = (to->front - 1 + stk->size) % stk->size;
	(to->data)[to->front] = (from->data)[from->front];
	from->front = (from->front + 1) % stk->size;
}

void	rotateorder(t_stacks *stk, t_deque *target)
{
	target->rear = (target->rear + 1) % stk->size;
	(target->data)[target->rear] = (target->data)[target->front];
	target->front = (target->front + 1) % stk->size;
}

void	reverseorder(t_stacks *stk, t_deque *target)
{
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
