/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:56:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 19:41:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void ft_is_alreadysort(t_stacks *stk, int *temparr);
static void ft_is_duplicate(t_stacks *stk, int *temparr);
static int	ft_binarysearch(int *arr, int key, int arrsize);

void	ft_checkarray(t_stacks *stk)
{
	int	*temparr;
	int	i;

	temparr = (int *)malloc(sizeof(int) * stk->size);
	if (!temparr)
		ft_error_ps(stk);
	i = -1;
	while (++i < stk->size)
		temparr[i] = (stk->array)[i];
	ft_is_alreadysort(stk, temparr);
	if (ft_timsort(temparr, stk->size) == 0)
	{
		free(temparr);
		ft_error_ps(stk);
	}
	ft_is_duplicate(stk, temparr);
	free(temparr);
}
// an array of n -> (0 ~ n-1 value) coordination compression

static void ft_is_alreadysort(t_stacks *stk, int *temparr)
{
	int	i;

	i = 0;
	while (++i < stk->size)
		if (temparr[i] < temparr[i - 1])
			break;
	if (i == stk->size)
	{
		free(temparr);
		free(stk->array);
		exit(0);
	}
}

static void ft_is_duplicate(t_stacks *stk, int *temparr)
{
	int	i;

	i = 1;
	while (i < stk->size)
	{
		if (temparr[i] == temparr[i-1])
		{
			free(temparr);
			ft_error_ps(stk);
		}
		i++;
	}
}
