/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:39:04 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 02:37:15 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_error(t_data *data, char *msg)
{
	write(STDERR_FILENO, "minishell: syntax error near unexpected token `", 47);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\'\n", 2);
	g_exit_status = 258;
	data->token.syntax_flag = ON;
	free_tokens(data);
}

void	system_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	eof_exit(char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	exit(g_exit_status);
}

void	execve_error(char *command)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": command not exectuted\n", 24);
	exit(1);
}
