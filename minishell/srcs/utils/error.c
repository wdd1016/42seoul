/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:39:04 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/26 23:40:15 by juyojeon         ###   ########.fr       */
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
