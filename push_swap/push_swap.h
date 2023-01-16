/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/17 02:51:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef int t_elemt;

typedef struct s_deque
{
	t_elemt	*data;
	int			front;
	int			rear;
}	t_deque;

typedef struct s_stacks
{
	t_elemt	*array;
	t_deque	*a;
	t_deque	*b;
	int		size;
}	t_stacks;

void	*ft_calloc(size_t count, size_t size);
int		ft_valid_atoi(t_stacks *stk, const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_count_words(const char *str, char set);

void	ft_error_ps(t_stacks *stk);
void	ft_make_array(t_stacks *stk, int argc, char **argv);
void	ft_coor_compression(t_stacks *stk);
int		ft_timsort(t_elemt *arr, int n);

#endif