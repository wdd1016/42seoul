/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:26:40 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 21:01:30 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	ft_play_commend(&stk);
	ft_is_sorted_stack(&stk);
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
