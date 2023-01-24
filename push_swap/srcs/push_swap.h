/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/25 02:14:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define A 0
# define B 1
# define ASCEND 1
# define DESCEND -1

enum command
{
	DOUB, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
};

typedef struct s_deque
{
	int	*data;
	int	front;
	int	rear;
}	t_deque;

typedef struct s_procstk
{
	int	min;
	int max;
	int location;
}	t_procstk;

typedef struct s_stacks
{
	int			*array;
	t_deque		*a;
	t_deque		*b;
	int			size;
	t_procstk	*stack;
	int			top;
}	t_stacks;

typedef struct	s_info
{
	int	pivot1;
	int	pivot2;
	int		rra;
	int		rrb;
}	t_info;

char	**ft_split(char const *s, char c);
size_t	ft_count_words(const char *str, char set);
void	ft_error_ps(t_stacks *stk);
void	ft_make_array(t_stacks *stk, int argc, char **argv);
void	ft_coor_compression(t_stacks *stk);
int		ft_timsort(int *arr, int n);
void	swaporder(t_stacks *stk, int order, t_deque *target);
void	pushorder(t_stacks *stk, int order, t_deque *from, t_deque *to);
void	rotateorder(t_stacks *stk, int order, t_deque *target);
void	reverseorder(t_stacks *stk, int order, t_deque *target);
void	doubleorder(t_stacks *stk, int order);
void	ft_make_stacks(t_stacks *stk);
void	ft_pushstack(t_stacks *stk, int n_location, int n_min, int n_max);
void	ft_insert_info(t_stacks *stk, t_procstk now, t_info *info);
int		ft_is_sortedstack(t_deque *stack, t_procstk now);
void	ft_smallsort(t_stacks *stk);
void	ft_hardsorting(t_stacks *stk, int name, int count, t_procstk now);
void	ft_qdsort(t_stacks *stk, int aim);

#endif