/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:18:28 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 00:28:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_commands(t_data *data)
{
	int	stdin_dup;
	int	stdout_dup;

	stdin_dup = dup(STDIN_FILENO);
	stdout_dup = dup(STDOUT_FILENO);
	execute_tree(data, data->parse_tree);
	dup2(stdin_dup, STDIN_FILENO);
	dup2(stdout_dup, STDOUT_FILENO);
	close(stdin_dup);
	close(stdout_dup);
}

static void	execute_tree(t_data *data, t_treenode *node)
{
	if (node->type == COMMAND)
		execute_command(data, node);
	else if (node->type == RE_IN)
		execute_redirect_input(data, node);
	else if (node->type == RE_HERE)
		execute_redirect_heredoc(data, node);
	else if (node->type == RE_OUT)
		execute_redirect_output(data, node);
	else if (node->type == RE_APPEND)
		execute_redirect_append(data, node);
	else if (node->type == D_VERTICAL)
		execute_double_vertical_bar(data, node);
	else if (node->type == D_AMPERSAND)
		execute_double_ampersand(data, node);
	else if (node->type == PIPE)
		execute_pipe(data, node);
}