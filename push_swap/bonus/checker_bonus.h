/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:27:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/20 12:29:33 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef int t_elemt;

typedef struct s_deque
{
	t_elemt	*data;
	int		front;
	int		rear;
}	t_deque;

typedef struct s_stacks
{
	t_elemt		*array;
	t_deque		*a;
	t_deque		*b;
	int			size;
}	t_stacks;

#endif