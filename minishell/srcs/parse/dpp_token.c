/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpp_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:58:28 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 22:03:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_bar_token(t_data *data)
{
	add_token(data, COMMAND);
	if (data->token.command_flag == OFF)
		return (parse_error(data, "syntax error\n"));
	data->token.end += 2;
	if (data->line[data->token.start] == '|')
		add_token(data, D_VERTICAL);
	else
		add_token(data, D_AMPERSAND);
}

void	pipe_token(t_data *data)
{
	add_token(data, COMMAND);
	if (data->token.command_flag == OFF)
		return (parse_error(data, "syntax error\n"));
	data->token.end += 1;
	add_token(data, PIPE);
}

void	priority_token(t_data *data)
{
	add_token(data, COMMAND);
	data->token.end += 1;
	if (data->line[data->token.start] == '(')
	{
		if (data->token.command_flag == ON)
			return (parse_error(data, "syntax error\n"));
		add_token(data, PRIORITY_START);
		data->token.bracket_count++;
	}
	else
	{
		if (data->token.command_flag == OFF)
			return (parse_error(data, "syntax error\n"));
		add_token(data, PRIORITY_END);
		data->token.bracket_count--;
	}
}
// dual bracket : arithmetic comparison
