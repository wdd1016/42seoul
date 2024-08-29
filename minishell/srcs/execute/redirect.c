/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 03:49:40 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 05:28:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_preprocess(t_data *data, t_treenode *node)
{
	symbol_process(data, node);
	wildcard_process(node);
	cmd_compress(node);
	if (node->cmd[0] == NULLPOINTER || node->cmd[1])
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, node->parsed_data, ft_strlen(node->parsed_data));
		write(STDERR_FILENO, ": ambiguous redirect\n", 21);
		g_exit_status = 1;
		return (ERROR);
	}
	return (ON);
}

void	execute_in_redirect(t_data *data, t_treenode *node)
{
	if (redirect_preprocess(data, node) == ERROR)
		return ;
}

void	execute_out_redirect(t_data *data, t_treenode *node)
{
	if (redirect_preprocess(data, node) == ERROR)
		return ;
}