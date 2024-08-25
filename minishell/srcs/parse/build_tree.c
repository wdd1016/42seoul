/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:00:05 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 23:12:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_treenode	*build_tree(t_data *data)
{
	t_treenode		*node;
	t_treenode		*temp;

	node = NULL;
	while (data->token.temp)
	{
		if (data->token.temp->type == PRIORITY_START)
		{
			temp = build_tree(data);
			temp->subshell_flag = ON;
			node = insert_node(node, temp);
			data->token.temp = data->token.temp->next;
		}
		else if (data->token.temp->type == PRIORITY_END)
			return (node);
		else
			node = insert_node(node, create_pnode(data->token.temp));
		data->token.temp = data->token.temp->next;
	}
	return (node);
}

t_treenode	*insert_node(t_treenode *head, t_treenode *child)
{
	t_treenode	*temp;

	if (!head)
		return (child);
	else if (child->type == COMMAND)
		return (insert_command(head, child));
	else if (child->type == IO_FILE)
		return (insert_iofile(head, child));
	temp = head;
	while (precedence(head->type) <= precedence(child->type))
	{
		if (!head->right_child)
			head->right_child = child;

	}

}

int	precedence(t_type type)
{
	if (type == PRIORITY_START || type == PRIORITY_END || type == SUB_SHELL)
		return (1);
	return (0);
}

t_treenode	*create_pnode(t_tokennode *node)
{
	t_treenode	*new_node;

	new_node = (t_treenode *)malloc_s(sizeof(t_treenode));
	new_node->type = type;
	if (type == COMMAND)
		new_node->cmd = cmd;
	else
		new_node->cmd = NULL;
	if (type == IO_FILE)
		new_node->file = file;
	else
		new_node->file = NULL;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	if (type == RE_IN || type == RE_HERE)
		new_node->left_child = create_pnode(IO_FILE, NULL, file);
	else if (type == RE_OUT || type == RE_APPEND)
		new_node->right_child = create_pnode(IO_FILE, NULL, file);
	return (new_node);
}
