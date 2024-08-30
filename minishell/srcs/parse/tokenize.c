/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:57:17 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 22:51:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			finalize_tokens(t_data *data);
static t_tokennode	*command_combination(t_tokennode *node);
static t_tokennode	*combine_node(t_tokennode *main, t_tokennode *node, \
t_tokennode *prev);

void	tokenize(t_data *dt)
{
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
		else
			dt->token.end++;
	}
	if (dt->token.syntax_flag == OFF)
		finalize_tokens(dt);
}

size_t	quote(t_data *data, char *string, char character, size_t end)
{
	end++;
	while (string[end] && string[end] != character)
		end++;
	if (string[end] == character)
		end++;
	else
	{
		if (character == '\'')
			parse_error(data, "single quote");
		else
			parse_error(data, "double quote");
	}
	return (end);
}

static void	finalize_tokens(t_data *data)
{
	add_token(data, COMMAND);
	if (data->token.command_flag == OFF && data->token.head)
		return (parse_error(data, "command"));
	else if (data->token.bracket_count)
		return (parse_error(data, "bracket"));
	command_combination(data->token.head);
}

static t_tokennode	*command_combination(t_tokennode *node)
{
	t_tokennode	*prev;
	t_tokennode	*main;
	int			command_flag;

	command_flag = OFF;
	while (node)
	{
		if (node->type == COMMAND && command_flag == OFF)
		{
			command_flag = ON;
			main = node;
		}
		else if (node->type == COMMAND && command_flag == ON)
			node = combine_node(main, node, prev);
		else if (node->type == PIPE || node->type == D_VERTICAL || \
				node->type == D_AMPERSAND)
			command_flag = OFF;
		else if (node->type == PRIORITY_START)
			node = command_combination(node->next);
		else if (node->type == PRIORITY_END)
			return (node);
		prev = node;
		node = node->next;
	}
	return (node);
}

static t_tokennode	*combine_node(t_tokennode *main, t_tokennode *node, \
t_tokennode *prev)
{
	char	*final_data;

	final_data = ft_strjoin3(main->parsed_data, " ", node->parsed_data);
	free(main->parsed_data);
	free(node->parsed_data);
	main->parsed_data = final_data;
	prev->next = node->next;
	free(node);
	return (prev);
}
