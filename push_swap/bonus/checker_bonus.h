/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:27:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/25 22:44:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

enum e_command
{
	DOUB,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_deque
{
	int	*data;
	int	front;
	int	rear;
}	t_deque;

typedef struct s_stacks
{
	int			*array;
	t_deque		*a;
	t_deque		*b;
	int			size;
}	t_stacks;

void	ft_error_ps(t_stacks *stk);
void	ft_make_array(t_stacks *stk, int argc, char **argv);
void	ft_is_valid_stack(t_stacks *stk);
void	ft_make_stacks(t_stacks *stk);
int		ft_min(int a, int b);
void	swaporder(t_stacks *stk, t_deque *target);
void	pushorder(t_stacks *stk, t_deque *from, t_deque *to);
void	rotateorder(t_stacks *stk, t_deque *target);
void	reverseorder(t_stacks *stk, t_deque *target);
void	doubleorder(t_stacks *stk, int order);

#endif