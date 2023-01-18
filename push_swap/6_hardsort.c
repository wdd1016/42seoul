/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_hardsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:53:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/18 18:49:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hardsorting(t_stacks *stk, int info, int count)
{
	int	temp;

	if (count == 1 && info == B)
		pushorder(stk, PA, stk->b, stk->a);
	else if (count == 2 && info == A)
	{
		temp = (stk->a->front + 1) % stk->size;
		if ((stk->a->data)[stk->a->front] > (stk->a->data)[temp])
			swaporder(stk, SA, stk->a);
	}
	else if (count == 2 && info == B)
	{
		temp = (stk->b->front + 1) % stk->size;
		if ((stk->b->data)[stk->b->front] < (stk->b->data)[temp])
			swaporder(stk, PB, stk->b);
		pushorder(stk, PA, stk->b, stk->a);
		pushorder(stk, PA, stk->b, stk->a);
	}
}
