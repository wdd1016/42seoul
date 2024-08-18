/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:11:51 by danpark           #+#    #+#             */
/*   Updated: 2024/08/18 01:20:09 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, signal_handler_quit);
}

void	signal_handler(int sig)
{
	char	*tmp;

	g_exit_status = 1;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	signal_handler_parent(int sig)
{
	g_exit_status = 1;
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler_heredoc(int sig)
{
	// (void)sig;
	// ft_putstr_fd("\n", STDERR_FILENO);
	// exit(1);
}

void	signal_handler_quit(int sig)
{
	char	*tmp;

	tmp = ft_itoa(g_exit_status);
	if (!tmp) ft_allocation_error();
	ft_putstr_fd("Quit: ", STDERR_FILENO);
	ft_putstr_fd(tmp, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(tmp);
	exit(1);
}
