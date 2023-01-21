/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:27:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 22:31:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_deque
{
	int	*data;
	int	front;
	int	rear;
}	t_deque;

typedef struct s_stacks
{
	int		*array;
	t_deque	*a;
	t_deque	*b;
	int		size;
}	t_stacks;

void	ft_make_array(t_stacks *stk, int argc, char **argv);
void	ft_error_ps(t_stacks *stk);
void	ft_checkarray(t_stacks *stk);

#endif