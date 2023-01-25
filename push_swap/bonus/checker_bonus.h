/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:27:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/25 22:04:46 by juyojeon         ###   ########.fr       */
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

void	ft_make_array(t_stacks *stk, int argc, char **argv);

#endif