/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_smallsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 04:24:14 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 05:41:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallsort(t_stacks *stk)
{
	if (stk->size <= 3)
		ft_hardsorting(stk, A, stk->size);
	else if (stk->size == 4)
		ft_sorting_four();
	else if (stk->size == 5)
		ft_sorting_five();
}
