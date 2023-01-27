/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/27 14:39:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freeall(t_stacks *stk);

int	main(int argc, char *argv[])
{
	t_stacks	stk;

	stk.array = NULL;
	stk.a = NULL;
	stk.b = NULL;
	stk.stack = NULL;
	stk.size = 0;
	ft_make_array(&stk, argc, argv);
	ft_coor_compression(&stk);
	ft_make_stacks(&stk);
	if (stk.size <= 5)
		ft_smallsort(&stk);
	else
	{
		ft_pushstack(&stk, A, 0, stk.size - 1);
		ft_qdsort(&stk, -1);
	}
	ft_freeall(&stk);
	return (0);
}

void	ft_error_ps(t_stacks *stk)
{
	write(2, "Error\n", 6);
	ft_freeall(stk);
	exit(1);
}

static void	ft_freeall(t_stacks *stk)
{
	if (stk->array)
		free(stk->array);
	if (stk->a)
		free(stk->a);
	if (stk->b)
	{
		if (stk->b->data)
			free(stk->b->data);
		free(stk->b);
	}
	if (stk->stack)
		free(stk->stack);
}
