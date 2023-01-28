/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:26:40 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/29 00:56:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_is_sorted_stack(t_stacks *stk);
static void	ft_ok_ko(t_stacks *stk, int flag);

int	main(int argc, char **argv)
{
	t_stacks	stk;

	stk.array = NULL;
	stk.a = NULL;
	stk.b = NULL;
	stk.size = 0;
	ft_make_array(&stk, argc, argv);
	ft_is_valid_stack(&stk);
	ft_make_stacks(&stk);
	ft_play_command(&stk);
	ft_is_sorted_stack(&stk);
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

static void	ft_is_sorted_stack(t_stacks *stk)
{
	int	pre;
	int	next;

	if (stk->b->rear != -1)
		ft_ok_ko(stk, KO);
	else
	{
		pre = stk->a->front;
		while (pre != stk->a->rear)
		{
			next = (pre + 1) % stk->size;
			if ((stk->a->data)[pre] > (stk->a->data)[next])
				ft_ok_ko(stk, KO);
			pre = next;
		}
		ft_ok_ko(stk, OK);
	}
}

static void	ft_ok_ko(t_stacks *stk, int flag)
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
	if (flag == OK)
		write(1, "OK\n", 3);
	else if (flag == KO)
		write(1, "KO\n", 3);
	exit(0);
}
