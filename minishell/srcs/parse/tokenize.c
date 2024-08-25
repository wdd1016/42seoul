/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:57:17 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/24 23:58:33 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	finalize_tokens(t_data *data);

void	tokenize(t_data *dt)
{
	dt->line[ft_strlen(dt->line) - 1] = '\0';
	dt->line_length = ft_strlen(dt->line);
	while (dt->token.end < dt->line_length && dt->token.syntax_flag == OFF)
	{
		if (dt->line[dt->token.end] == '\'')
			dt->token.end = quote(dt, dt->line, '\'', dt->token.end);
		else if (dt->line[dt->token.end] == '\"')
			dt->token.end = quote(dt, dt->line, '\"', dt->token.end);
		else if (ft_strchr("><", dt->line[dt->token.end]))
			redirect_token(dt);
		else if (!ft_strncmp(dt->line + dt->token.end, "&&", 2) \
		|| !ft_strncmp(dt->line + dt->token.end, "||", 2))
			double_bar_token(dt);
		else if (dt->line[dt->token.end] == '|')
			pipe_token(dt);
		else if (ft_strchr("()", dt->line[dt->token.end]))
			priority_token(dt);
	}
	finalize_tokens(dt);
}

void	add_token(t_data *dt, t_type type)
{
	t_tokennode	*token;

	while (dt->line[dt->token.start] && ft_isspace(dt->line[dt->token.start]))
		(dt->token.start)++;
	if (dt->token.start == dt->token.end)
		return ;
	token = (t_tokennode *)malloc_s(sizeof(t_tokennode));
	token->type = type;
	token->cmd = NULL;
	token->next = NULL;
	if (type == COMMAND || type == RE_IN || type == RE_OUT || \
		type == RE_APPEND || type == RE_HERE)
		dt->token.command_flag = ON;
	if (type == PIPE || type == D_VERTICAL || type == D_AMPERSAND || \
		type == PRIORITY_START)
		dt->token.command_flag = OFF;
	token->parsed_data = ft_substr(dt->line, dt->token.start, \
									dt->token.end - dt->token.start);
	if (!dt->token.head)
		dt->token.head = token;
	else
		dt->token.tail->next = token;
	dt->token.tail = token;
	dt->token.start = dt->token.end;
}
// Start index : first character of the token
// End Index: position after the last character of the token.

static void	finalize_tokens(t_data *data)
{
	t_tokennode	*tmp;

	if (data->token.syntax_flag == ON)
		return ;
	else if (data->token.command_flag == OFF)
		return (parse_error(data, "syntax error\n"));
	else if (data->token.bracket_count != 0)
		return (parse_error(data, "syntax error\n"));
	else
		add_token(data, COMMAND);
	tmp = data->token.head;
	while (tmp->next)
	{
		if (tmp->type == COMMAND || tmp->type == RE_IN || tmp->type == RE_OUT \
			|| tmp->type == RE_APPEND || tmp->type == RE_HERE)
			cmd_with_symbol_process(data, tmp);
		tmp = tmp->next;
	}
}
