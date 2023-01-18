/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/19 03:13:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_stacks(t_stacks *stk);

int	main(int argc, char *argv[])
{
	t_stacks	stk;

	// argc = 2;
	// char *test[] = {"./sdf", "524"};
	stk.array = NULL;
	stk.a = NULL;
	stk.b = NULL;
	stk.stack = NULL;
	stk.size = 0;
	ft_make_array(&stk, argc, argv);
	// ft_make_array(&stk, argc, test);
	ft_coor_compression(&stk);
	ft_make_stacks(&stk);
	ft_pushstack(&stk, A, 0, stk.size - 1);
	ft_qdsort(&stk, -1);
	if (stk.array)
		free(stk.array);
	if (stk.a)
		free(stk.a);
	if (stk.b)
	{
		if (stk.b->data)
			free(stk.b->data);
		free(stk.b);
	}
	if (stk.stack)
		free(stk.stack);
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
	if (stk->stack)
		free(stk->stack);
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
	stk->stack = (t_procstk *)malloc(sizeof(t_procstk) * stk->size);
	stk->top = -1;
}

void	ft_pushstack(t_stacks *stk, int n_location, int n_min, int n_max)
{
	t_procstk	*topstack;

	stk->top += 1;
	topstack = &((stk->stack)[stk->top]);
	topstack->location = n_location;
	topstack->max = n_max;
	topstack->min = n_min;
}

t_procstk	ft_popstack(t_stacks *stk)
{
	stk->top -= 1;
	return ((stk->stack)[stk->top + 1]);
}
