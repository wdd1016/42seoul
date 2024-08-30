/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:11:51 by danpark           #+#    #+#             */
/*   Updated: 2024/08/31 03:02:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_default(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	signal_parent(void)
{
	signal(SIGINT, signal_handler_parent);
	signal(SIGQUIT, signal_handler_quit);
}

void	signal_heredoc_parent(void)
{
	signal(SIGINT, signal_handler_parent);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_heredoc_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}
