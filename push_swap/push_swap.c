/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/15 00:26:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stk;

	stk = (t_stacks *)ft_calloc(1, sizeof(t_stacks));
	if (!stk)
		ft_error_ps(stk);
	ft_make_array(stk, argc, argv);
	ft_coor_compression(stk);
	ft_make_stack(stk);
	ft_qsort_ps(stk, 0, stk->size - 1);
	return (0);
}

void	ft_error_ps(t_stacks *stk)
{
	write(2, "Error\n", 6);
	if (stk)
	{
		if (stk->array)
			free(stk->array);
		if (stk->a)
		{
			if (stk->a->data)
				free(stk->a->data);
			free(stk->a);
		}
		if (stk->b)
		{
			if (stk->b->data)
				free(stk->b->data);
			free(stk->b);
		}
		free(stk);
	}
	exit(1);
}