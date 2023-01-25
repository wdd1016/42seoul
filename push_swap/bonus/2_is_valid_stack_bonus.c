/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_is_valid_stack_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:56:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/25 22:15:12 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_is_duplicate(t_stacks *stk, int *temparr);

void	ft_is_valid_stack(t_stacks *stk)
{
	int	*temparr;
	int	i;

	temparr = (int *)malloc(sizeof(int) * stk->size);
	if (!temparr)
		ft_error_ps(stk);
	i = -1;
	while (++i < stk->size)
		temparr[i] = (stk->array)[i];
	if (ft_timsort(temparr, stk->size) == 0)
	{
		free(temparr);
		ft_error_ps(stk);
	}
	ft_is_duplicate(stk, temparr);
	free(temparr);
}
// an array of n -> (0 ~ n-1 value) coordination compression

static void	ft_is_duplicate(t_stacks *stk, int *temparr)
{
	int	i;

	i = 1;
	while (i < stk->size)
	{
		if (temparr[i] == temparr[i - 1])
		{
			free(temparr);
			ft_error_ps(stk);
		}
		i++;
	}
}
