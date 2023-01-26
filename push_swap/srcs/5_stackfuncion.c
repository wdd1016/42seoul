/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_stackfuncion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:36:42 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 22:06:36 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_stacks(t_stacks *stk)
{
	stk->a = (t_deque *)malloc(sizeof(t_deque));
	if (stk->a == NULL)
		ft_error_ps(stk);
	stk->a->data = stk->array;
	stk->a->front = 0;
	stk->a->rear = stk->size - 1;
	stk->b = (t_deque *)malloc(sizeof(t_deque));
	if (stk->b == NULL)
		ft_error_ps(stk);
	stk->b->data = (int *)malloc(sizeof(int) * stk->size);
	if (stk->b->data == NULL)
		ft_error_ps(stk);
	stk->b->front = 0;
	stk->b->rear = -1;
	stk->stack = (t_procstk *)malloc(sizeof(t_procstk) * stk->size);
	stk->top = -1;
}
// when PB, front -= -1, therefore init b->front "1" && b ->rear "0"

void	ft_pushstack(t_stacks *stk, int n_location, int n_min, int n_max)
{
	t_procstk	*topstack;

	stk->top += 1;
	topstack = &((stk->stack)[stk->top]);
	topstack->location = n_location;
	topstack->max = n_max;
	topstack->min = n_min;
}

int	ft_is_sortedstack(t_stacks *stk, t_deque *stack, t_procstk now)
{
	int	current;
	int	next;
	int	count;

	count = now.max - now.min + 1;
	current = stack->front;
	while (count-- > 0)
	{
		next = (current + 1) % stk->size;
		if (now.location == A)
		{
			if ((stack->data)[current] > (stack->data)[next])
				return (0);
		}
		else
			if ((stack->data)[current] < (stack->data)[next])
				return (0);
		current = next;
	}
	if (count == 0)
		return (TRUE);
	return (0);
}

void	ft_insert_info(t_procstk now, t_info *info)
{
	info->rra = 0;
	info->rrb = 0;
	info->pivot1 = now.min + (now.max - now.min) / 3;
	info->pivot2 = now.max - (now.max - now.min) / 3;
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
