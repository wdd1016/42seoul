/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:27:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 00:02:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10
# define SS 0
# define RR 1
# define RRR 2

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

typedef struct s_buffer
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_fdlist
{
	t_buffer		*buflist;
	int				fdnumber;
	size_t			strlen;
	struct s_fdlist	*next;
}	t_fdlist;

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
ssize_t	ft_strchrindex(char *s, int c);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_gnlfree_all(t_fdlist *firlist, char *str_rtn);
void	*ft_gnlfree_use(t_fdlist *firlist, t_fdlist *uselist, char *str_rtn);
char	*get_next_line(int fd);

#endif