/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:55:17 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 02:57:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_bar_token(t_data *data)
{
	add_token(data, COMMAND);
	if (data->token.command_flag == OFF)
	{
		if (data->line[data->token.start] == '|')
			return (parse_error(data, "||"));
		else
			return (parse_error(data, "&&"));
	}
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
		return (parse_error(data, "|"));
	data->token.end += 1;
	add_token(data, PIPE);
	data->token.pipe_flag = ON;
}

void	priority_token(t_data *data)
{
	add_token(data, COMMAND);
	data->token.end += 1;
	if (data->line[data->token.start] == '(')
	{
		if (data->token.command_flag == ON)
			return (parse_error(data, "("));
		add_token(data, PRIORITY_START);
		data->token.bracket_count++;
	}
	else
	{
		if (data->token.command_flag == OFF)
			return (parse_error(data, ")"));
		add_token(data, PRIORITY_END);
		data->token.bracket_count--;
	}
}
// dual bracket : arithmetic comparison

void	priority_test(t_data *data)
{
	t_type	type;

	data->token.temp = data->token.head;
	while (data->token.temp)
	{
		if (data->token.temp->type == PRIORITY_END && data->token.temp->next)
		{
			while (data->token.temp->next)
			{
				type = data->token.temp->next->type;
				if (type == COMMAND || type == PRIORITY_START)
					return (parse_error(data, "bracket"));
				else if (type == PIPE || type == D_VERTICAL || \
							type == D_AMPERSAND)
					break ;
				else
					data->token.temp = data->token.temp->next;
			}
		}
		data->token.temp = data->token.temp->next;
	}
}
