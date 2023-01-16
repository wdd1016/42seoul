/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/17 04:18:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_stacks(t_stacks *stk);

int	main(int argc, char *argv[])
{
	t_stacks	stk;

	stk.array = NULL;
	stk.a = NULL;
	stk.b = NULL;
	ft_make_array(&stk, argc, argv);
	ft_coor_compression(&stk);
	ft_make_stacks(&stk);
	ft_qdsort(&stk, 0, stk.size - 1);
	return (0);
}

void	ft_error_ps(t_stacks *stk)
{
	write(2, "Error\n", 6);
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
	exit(1);
}

static void	ft_make_stacks(t_stacks *stk)
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
	stk->b->data = (t_elemt *)malloc(sizeof(t_elemt) * stk->size);
	if (stk->b->data == NULL)
		ft_error_ps(stk);
	stk->b->front = 0;
	stk->b->rear = 0;
}