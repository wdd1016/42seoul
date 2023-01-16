/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:56:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/16 20:08:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_coor_compression(t_stacks *stk)
{
	element	*temparr;
	int		i;

	temparr = (element *)malloc(sizeof(element) * stk->size);
	if (!temparr)
		ft_error_ps(stk);
	i = -1;
	while (++i < stk->size)
		temparr[i] = (stk->array)[i];
	ft_timsort(temparr, 0, stk->size - 1);

}