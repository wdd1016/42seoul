/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/18 18:49:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define A 0
# define B 1
# define DOUB 2
# define SA 4
# define SB 8
# define SS 16
# define PA 32
# define PB 64
# define RA 128
# define RB 256
# define RR 512
# define RRA 1024
# define RRB 2048
# define RRR 4096
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef int t_elemt;

typedef struct s_deque
{
	t_elemt	*data;
	int		front;
	int		rear;
}	t_deque;

typedef struct s_procstk
{
	int	min;
	int max;
	int location;
}	t_procstk;

typedef struct s_stacks
{
	t_elemt		*array;
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
	int	rra;
	int	rrb;
}	t_info;

int			ft_valid_atoi(t_stacks *stk, const char *str);
char		**ft_split(char const *s, char c);
size_t		ft_count_words(const char *str, char set);
void		ft_error_ps(t_stacks *stk);
void		ft_pushstack(t_stacks *stk, int n_location, int n_min, int n_max);
t_procstk	ft_popstack(t_stacks *stk);
void		ft_make_array(t_stacks *stk, int argc, char **argv);
void		ft_coor_compression(t_stacks *stk);
int			ft_timsort(t_elemt *arr, int n);
void		swaporder(t_stacks *stk, int order, t_deque *target);
void		pushorder(t_stacks *stk, int order, t_deque *from, t_deque *to);
void		rotateorder(t_stacks *stk, int order, t_deque *target);
void		reverseorder(t_stacks *stk, int order, t_deque *target);
void		doubleorder(t_stacks *stk, int order);
void		ft_qdsort(t_stacks *stk, int aim);
void		ft_hardsorting(t_stacks *stk, int info, int count);

#endif