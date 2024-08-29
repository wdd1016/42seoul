/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:58:28 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 01:38:46 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_type	get_redirect_type(char *line);
static void		finalize_redirect_with_argument(t_data *dt);
static void		parse_redirect_error(t_data *data, char *line, size_t idx);
static int		handle_redirect_wildcard(t_data *data);

void	redirect_token(t_data *data)
{
	t_tokennode	*file_token;
	t_type		type;

	add_token(data, COMMAND);
	type = get_redirect_type(data->line + data->token.end);
	data->token.end += 1;
	if (type == RE_HERE || type == RE_APPEND)
		data->token.end += 1;
	finalize_redirect_with_argument(data);
	if (type == RE_HERE)
		heredoc(data, data->token.start, data->token.end - data->token.start);
	else
		add_token(data, type);
	if (type != RE_HERE && handle_redirect_wildcard(data) == ERROR)
		return (parse_error(data, "*"));
	file_token = create_tokennode(IO_FILE);
	file_token->parsed_data = data->token.temp->parsed_data;
	data->token.temp->parsed_data = NULLPOINTER;
	data->token.temp->next = file_token;
	data->token.temp = file_token;
}

static t_type	get_redirect_type(char *line)
{
	if (ft_strncmp(line, "<<", 2) == 0)
		return (RE_HERE);
	else if (ft_strncmp(line, ">>", 2) == 0)
		return (RE_APPEND);
	else if (line[0] == '<')
		return (RE_IN);
	else
		return (RE_OUT);
}

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

static int	handle_redirect_wildcard(t_data *data)
{
	char		*file;
	t_filelist	*file_list;
	int			count;

	file = data->token.temp->parsed_data;
	if (ft_strchr(file, '*') == 0)
		return (OFF);
	count = 0;
	file_list = find_wildcard_files(file);
	if (!file_list)
		return (OFF);
	else if (file_list->total_count > 1)
	{
		free_file_list(file_list);
		return (ERROR);
	}
	free(data->token.temp->parsed_data);
	data->token.temp->parsed_data = file_list->file_name;
	free(file_list);
	return (ON);
}
