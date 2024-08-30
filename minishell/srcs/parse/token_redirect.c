/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 02:50:35 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 21:41:00 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		find_redirect_argument(t_data *dt);
static void		parse_redirect_error(t_data *data, char *line, size_t idx);

void	redirect_token(t_data *data)
{
	t_type		type;

	add_token(data, COMMAND);
	if (ft_strncmp(data->line + data->token.end, "<<", 2) == 0)
		type = RE_HERE;
	else if (ft_strncmp(data->line + data->token.end, ">>", 2) == 0)
		type = RE_APPEND;
	else if ((data->line)[data->token.end] == '<')
		type = RE_IN;
	else
		type = RE_OUT;
	data->token.end += 1;
	if (type == RE_HERE || type == RE_APPEND)
		data->token.end += 1;
	find_redirect_argument(data);
	if (type == RE_HERE)
		heredoc(data, data->token.start, data->token.end - data->token.start);
	else
		add_token(data, type);
}

static void	find_redirect_argument(t_data *dt)
{
	while (dt->line[dt->token.end] && ft_isspace(dt->line[dt->token.end]))
		(dt->token.end)++;
	dt->token.start = dt->token.end;
	while (dt->token.end < dt->line_length)
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
	if (dt->token.start == dt->token.end)
		return (parse_redirect_error(dt, dt->line, dt->token.end));
}

static void	parse_redirect_error(t_data *data, char *line, size_t idx)
{
	if (line[idx] == '\0')
		parse_error(data, "newline");
	else if (ft_strncmp(line + idx, "||", 2) == 0)
		parse_error(data, "||");
	else if (ft_strncmp(line + idx, "&&", 2) == 0)
		parse_error(data, "&&");
	else if (line[idx] == '|')
		parse_error(data, "|");
	else if (line[idx] == '&')
		parse_error(data, "&");
	else if (line[idx] == '(')
		parse_error(data, "(");
	else if (line[idx] == ')')
		parse_error(data, ")");
	else if (line[idx] == '<')
		parse_error(data, "<");
	else if (line[idx] == '>')
		parse_error(data, ">");
}
