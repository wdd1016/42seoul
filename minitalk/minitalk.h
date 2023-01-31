/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/01 03:41:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	struct sigaction	act;
	pid_t				opponent_pid;
	char				*string;
}	t_data;

t_data	g_data;

int		ft_print_pid(int n);
void	ft_cut_in_error(int *count);
void	ft_change_sigaction(void (*sigact)(int, siginfo_t *, void *));
void	ft_check_client(int signo, siginfo_t *info, void *content);

#endif