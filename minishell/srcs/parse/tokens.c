/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:58:28 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 01:35:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	finalize_redirect_with_argument(t_data *dt);

void	redirect_token(t_data *dt)
{
	add_token(dt, COMMAND);
	if (ft_strncmp(dt->line + dt->token.end, "<<", 2) == 0)
	{
		dt->token.end += 2;
		finalize_redirect_with_argument(dt);
		heredoc(dt, dt->token.start, dt->token.end - dt->token.start);
	}
	else if (ft_strncmp(dt->line + dt->token.end, ">>", 2) == 0)
	{
		dt->token.end += 2;
		finalize_redirect_with_argument(dt);
		add_token(dt, RE_APPEND);
	}
	else if (dt->line[dt->token.end] == '<')
	{
		dt->token.end += 1;
		finalize_redirect_with_argument(dt);
		add_token(dt, RE_IN);
	}
	else
	{
		dt->token.end += 1;
		finalize_redirect_with_argument(dt);
		add_token(dt, RE_OUT);
	}
}

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
	add_token(data, PIPE);
	data->token.end += 1;
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
		if (data->token.bracket_count != 0)
			return (parse_error(data, "syntax error\n"));
		add_token(data, PRIORITY_END);
		data->token.bracket_count--;
	}
}
// dual bracket : arithmetic comparison

static void	finalize_redirect_with_argument(t_data *dt)
{
	while (dt->line[dt->token.end] && ft_isspace(dt->line[dt->token.end]))
		(dt->token.end)++;
	dt->token.start = dt->token.end;
	while (dt->token.end < dt->line_length && dt->token.syntax_flag == OFF)
	{
		if (ft_strchr("<>|&() ", dt->line[dt->token.end]))
			break ;
		else if (dt->line[dt->token.end] == '\'')
			dt->token.end = quote(dt, dt->line, '\'', dt->token.end);
		else if (dt->line[dt->token.end] == '\"')
			dt->token.end = quote(dt, dt->line, '\"', dt->token.end);
		else
			(dt->token.end)++;
	}
	if (dt->token.start == dt->token.end && dt->token.syntax_flag == OFF)
		return (parse_error(dt, "syntax error\n"));
}
