/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/12 18:50:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef int element;

typedef struct s_deque
{
	element	*data;
	int		front;
	int		rear;
}	t_deque;

typedef struct s_stacks
{
	element	*array;
	t_deque	*a;
	t_deque	*b;
	int		size;
}	t_stacks;

void	*ft_calloc(size_t count, size_t size);
int		ft_valid_atoi(t_stacks *stk, const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_count_words(const char *str, char set);

void	ft_make_array(t_stacks *stk, int argc, char **argv);
void	ft_error_ps(t_stacks *stk);

#endif