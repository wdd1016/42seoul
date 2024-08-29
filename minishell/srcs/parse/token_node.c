/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:57:17 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 02:56:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_data *dt, t_type type)
{
	t_tokennode	*token;

	while (dt->line[dt->token.start] && ft_isspace(dt->line[dt->token.start]))
		(dt->token.start)++;
	if (dt->token.start == dt->token.end)
		return ;
	token = create_tokennode(type);
	if (type == COMMAND || type == IO_FILE)
	{
		dt->token.command_flag = ON;
		token->parsed_data = ft_substr(dt->line, dt->token.start, \
										dt->token.end - dt->token.start);
	}
	else if (type == PIPE || type == D_VERTICAL || type == D_AMPERSAND || \
		type == PRIORITY_START)
		dt->token.command_flag = OFF;
	if (!dt->token.head)
		dt->token.head = token;
	else
		dt->token.temp->next = token;
	dt->token.temp = token;
	if (type == RE_IN || type == RE_OUT || type == RE_APPEND || type == RE_HERE)
		add_token(dt, IO_FILE);
	dt->token.start = dt->token.end;
}
// Start index : first character of the token
// End Index: position after the last character of the token.

t_tokennode	*create_tokennode(t_type type)
{
	t_tokennode	*new_node;

	new_node = (t_tokennode *)malloc_s(sizeof(t_tokennode));
	new_node->type = type;
	new_node->parsed_data = NULLPOINTER;
	new_node->next = NULLPOINTER;
	return (new_node);
}

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
