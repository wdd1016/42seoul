/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_stackfuncion_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:36:42 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 22:06:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
