/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:58:28 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/21 23:53:27 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	finalize_redirect_with_argument(t_data *dt, t_type type);

void	redirect_token(t_data *data)
{
	add_token(data, COMMAND);
	if (ft_strncmp(data->line + data->token.end, "<<", 2) == 0)
		heredoc(data);
	else if (ft_strncmp(data->line + data->token.end, ">>", 2) == 0)
	{
		data->token.end += 2;
		finalize_redirect_with_argument(data, RE_APPEND);
		add_token(data, RE_APPEND);
	}
	else if (data->line[data->token.end + 1] == '<')
	{
		data->token.end += 1;
		finalize_redirect_with_argument(data, RE_IN);
		add_token(data, RE_IN);
	}
	else
	{
		data->token.end += 1;
		finalize_redirect_with_argument(data, RE_OUT);
		add_token(data, RE_OUT);
	}
}

static void	finalize_redirect_with_argument(t_data *dt, t_type type)
{
	while (dt->line[dt->token.start] && ft_isspace(dt->line[dt->token.end]))
		(dt->token.end)++;
	dt->token.start = dt->token.end;
	while (dt->token.end < dt->line_length)
	{
		if (ft_strchr("<>|&() ", dt->line[dt->token.end]))
			break ;
		else if (dt->line[dt->token.end] == '\'')
			single_quote(dt);
		else if (dt->line[dt->token.end] == '\"')
			double_quote(dt);
		else if (dt->line[dt->token.end] == '$' && dt->line[dt->token.end + 1] \
				!= '\0' && ft_strchr(" \\", dt->line[dt->token.end + 1]) == 0)
			expansion(dt);
		else
			(dt->token.end)++;
	}
	if (dt->token.start == dt->token.end)
		return (parse_error(dt, "syntax error\n"));
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
