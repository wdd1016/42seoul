/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 02:21:08 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 20:01:41 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_commands(t_data *data)
{
	tokenize(data);
	data->token.temp = data->token.head;
	if (data->token.temp)
		data->parse_tree = build_tree(data);
}

void	parse_error(t_data *data, char *msg)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	g_exit_status = 258;
	data->token.syntax_flag = ON;
	free_tokens(data);
}
