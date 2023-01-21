/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_stackfuncion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:36:42 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/21 01:10:05 by juyojeon         ###   ########.fr       */
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
	stk->b->front = 1;
	stk->b->rear = 0;
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

void	ft_min_or_max(int a, int b, int flag)
{

}
