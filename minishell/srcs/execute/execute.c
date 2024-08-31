/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:46:09 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 02:45:21 by juyojeon         ###   ########.fr       */
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

int	execute_tree_consider_no_command(t_data *data, t_treenode *node)
{
	if (node == NULLPOINTER)
		return (OFF);
	else if (node->type == RE_IN || node->type == RE_HERE || \
				node->type == RE_OUT || node->type == RE_APPEND)
	{
		if (execute_redirect(data, node) == ERROR)
			return (ERROR);
		else
			set_exit_status(0);
	}
	else if (node->type == COMMAND)
		execute_command(data, node);
	else if (node->type == D_VERTICAL)
		execute_double_vertical_bar(data, node);
	else if (node->type == D_AMPERSAND)
		execute_double_ampersand(data, node);
	else if (node->type == PIPE)
		execute_pipe(data, node);
	return (ON);
}

int	execute_tree(t_data *data, t_treenode *node)
{
	if (node == NULLPOINTER)
		return (OFF);
	else if (node->type == RE_IN || node->type == RE_HERE || \
				node->type == RE_OUT || node->type == RE_APPEND)
		return (execute_redirect(data, node));
	else if (node->type == COMMAND)
		execute_command(data, node);
	else if (node->type == D_VERTICAL)
		execute_double_vertical_bar(data, node);
	else if (node->type == D_AMPERSAND)
		execute_double_ampersand(data, node);
	else if (node->type == PIPE)
		execute_pipe(data, node);
	return (ON);
}
