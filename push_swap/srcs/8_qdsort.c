/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_qdsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 04:20:13 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/25 21:45:22 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_asorting(t_stacks *stk, t_procstk now);
static void	ft_aordering(t_stacks *stk, t_info *info, int count);
static void	ft_bsorting(t_stacks *stk, t_procstk now, int count);
static void	ft_bordering(t_stacks *stk, t_info *info, int count);

void	ft_qdsort(t_stacks *stk, int aim)
{
	t_procstk	temp;

	while (stk->top > aim)
	{
		temp = (stk->stack)[stk->top];
		stk->top -= 1;
		if (temp.location == A)
			ft_asorting(stk, temp);
		else
			ft_bsorting(stk, temp, temp.max - temp.min + 1);
	}
}
// (stk->stack)[stk->top] && stk->top -= 1 -> pop data in stack

static void	ft_asorting(t_stacks *stk, t_procstk now)
{
	t_info	info;
	int		count;

	count = now.max - now.min + 1;
	if (ft_is_sortedstack(stk, stk->a, now) == TRUE)
		return ;
	else if (count <= 3)
		ft_hardsorting(stk, A, count);
	else
	{
		ft_insert_info(now, &info);
		ft_aordering(stk, &info, count);
		count = -1;
		while (++count < ft_min(info.rra, info.rrb))
			doubleorder(stk, RRR);
		if (info.rra > info.rrb)
			while (count++ < info.rra)
				reverseorder(stk, RRA, stk->a);
		else if (info.rra < info.rrb)
			while (count++ < info.rrb)
				reverseorder(stk, RRB, stk->b);
		ft_pushstack(stk, B, now.min, info.pivot1 - 1);
		ft_pushstack(stk, B, info.pivot1, info.pivot2 - 1);
		ft_pushstack(stk, A, info.pivot2, now.max);
	}
}
// pivot1 : take middle-value stack
// pivot2 : take big-value stack

static void	ft_aordering(t_stacks *stk, t_info *info, int count)
{
	while (count-- > 0)
	{
		if ((stk->a->data)[stk->a->front] < info->pivot1)
			pushorder(stk, PB, stk->a, stk->b);
		else if ((stk->a->data)[stk->a->front] < info->pivot2)
		{
			pushorder(stk, PB, stk->a, stk->b);
			if (count > 0 && (stk->a->data)[stk->a->front] >= info->pivot2)
			{
				doubleorder(stk, RR);
				count--;
				(info->rra)++;
				(info->rrb)++;
				continue ;
			}
			rotateorder(stk, RB, stk->b);
			(info->rrb)++;
		}
		else
		{
			rotateorder(stk, RA, stk->a);
			(info->rra)++;
		}
	}
}

static void	ft_bsorting(t_stacks *stk, t_procstk now, int count)
{
	t_info	info;

	if (ft_is_sortedstack(stk, stk->b, now) == TRUE)
		while (count-- > 0)
			pushorder(stk, PA, stk->b, stk->a);
	else if (count <= 3)
		ft_hardsorting(stk, B, count);
	else
	{
		ft_insert_info(now, &info);
		ft_bordering(stk, &info, count);
		ft_pushstack(stk, A, info.pivot2, now.max);
		ft_qdsort(stk, stk->top - 1);
		count = -1;
		while (++count < ft_min(info.rra, info.rrb))
			doubleorder(stk, RRR);
		if (info.rra > info.rrb)
			while (count++ < info.rra)
				reverseorder(stk, RRA, stk->a);
		else if (info.rra < info.rrb)
			while (count++ < info.rrb)
				reverseorder(stk, RRB, stk->b);
		ft_pushstack(stk, B, now.min, info.pivot1 - 1);
		ft_pushstack(stk, A, info.pivot1, info.pivot2 - 1);
	}
}
// pivot1 : take middle-value stack
// pivot2 : take big-value stack

static void	ft_bordering(t_stacks *stk, t_info *info, int count)
{
	while (count-- > 0)
	{
		if ((stk->b->data)[stk->b->front] < info->pivot1)
		{
			rotateorder(stk, RB, stk->b);
			(info->rrb)++;
		}
		else if ((stk->b->data)[stk->b->front] < info->pivot2)
		{
			pushorder(stk, PA, stk->b, stk->a);
			if (count > 0 && (stk->b->data)[stk->b->front] < info->pivot1)
			{
				doubleorder(stk, RR);
				count--;
				(info->rra)++;
				(info->rrb)++;
				continue ;
			}
			rotateorder(stk, RA, stk->a);
			(info->rra)++;
		}
		else
			pushorder(stk, PA, stk->b, stk->a);
	}
}
