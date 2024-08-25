/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:57:17 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 22:36:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			finalize_tokens(t_data *data);
static t_tokennode	*command_combination(t_tokennode *node);
static t_tokennode	*combine_node(t_tokennode *main, t_tokennode *node, \
t_tokennode *prev);

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

static void	finalize_tokens(t_data *data)
{
	t_tokennode	*tmp;

	if (data->token.syntax_flag == ON)
		return ;
	else if (!(data->token.command_flag) || data->token.bracket_count)
		return (parse_error(data, "syntax error\n"));
	else
		add_token(data, COMMAND);
	command_combination(data->token.head);
	tmp = data->token.head;
	while (tmp->next)
	{
		if (tmp->type == COMMAND)
			command_symbol_process(data, tmp);
		else if (tmp->type == IO_FILE)
			file_symbol_process(data, tmp);
		tmp = tmp->next;
	}
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
	char	*temp;
	char	*final_data;

	temp = ft_strjoin(main->parsed_data, " ");
	final_data = ft_strjoin(temp, node->parsed_data);
	free(main->parsed_data);
	free(node->parsed_data);
	free(temp);
	main->parsed_data = final_data;
	prev->next = node->next;
	free(node);
	return (prev);
}
