/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 01:03:10 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 01:03:23 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int sig)
{
	char	*tmp;

	g_exit_status = 1;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}
/* The signal_handler function has an integer parameter sig,
and it should update the global g_exit_status accordingly. */

void	signal_handler_parent(int sig)
{
	g_exit_status = 1;
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler_heredoc(int sig)
{
	(void)sig;
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	signal_handler_quit(int sig)
{
	char	*tmp;

	tmp = ft_itoa(g_exit_status);
	if (!tmp)
		ft_allocation_error();
	write(STDERR_FILENO, "Quit: ", 6);
	write(STDERR_FILENO, tmp, ft_strlen(tmp));
	write(STDERR_FILENO, "\n", 1);
	free(tmp);
	exit(1);
}
