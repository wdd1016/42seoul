/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:51:07 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 05:11:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_data *data)
{
	while (data->token.head)
	{
		data->token.temp = data->token.head;
		data->token.head = data->token.head->next;
		if (data->token.temp->parsed_data)
			free(data->token.temp->parsed_data);
		free(data->token.temp);
	}
	data->token.temp = NULLPOINTER;
	data->token.start = 0;
	data->token.end = 0;
	data->token.bracket_count = 0;
	data->token.command_flag = OFF;
	data->token.syntax_flag = OFF;
	data->token.pipe_flag = OFF;
}

void	free_parse_tree(t_treenode *node)
{
	int	i;

	if (!node)
		return ;
	if (node->left_child)
		free_parse_tree(node->left_child);
	if (node->right_child)
		free_parse_tree(node->right_child);
	if (node->cmd)
	{
		i = -1;
		while ((node->cmd)[++i])
			free((node->cmd)[i]);
		free(node->cmd);
	}
	if (node->parsed_data)
		free(node->parsed_data);
	free(node);
}

void	free_env_list(t_data *data)
{
	t_envnode	*temp;

	while (data->env_list)
	{
		temp = data->env_list;
		data->env_list = data->env_list->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void	free_heredoc_list_close_fd(t_data *data)
{
	t_herenode	*temp;

	while (data->heredoc_list)
	{
		temp = data->heredoc_list;
		data->heredoc_list = data->heredoc_list->next;
		close(temp->fd);
		free(temp->file_name);
		free(temp);
	}
}

void	free_file_list(t_filelist *node)
{
	t_filelist	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->file_name);
		free(temp);
	}
}
