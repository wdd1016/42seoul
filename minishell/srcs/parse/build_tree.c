/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:00:05 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 02:49:24 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_treenode	*insert_node(t_treenode *head, t_treenode *child);
static int			priority_level(t_treenode *child);
static t_treenode	*insert_child(t_treenode *parent, t_treenode *child, \
t_treenode *head);
static t_treenode	*create_pnode(t_tokennode *node);

t_treenode	*build_tree(t_data *data)
{
	t_treenode		*node;
	t_treenode		*temp;

	node = NULLPOINTER;
	while (data->token.temp)
	{
		if (data->token.temp->type == PRIORITY_START)
		{
			data->token.temp = data->token.temp->next;
			temp = build_tree(data);
			temp->subshell_flag = ON;
			node = insert_node(node, temp);
		}
		else if (data->token.temp->type == PRIORITY_END)
			return (node);
		else
			node = insert_node(node, create_pnode(data->token.temp));
		data->token.temp = data->token.temp->next;
	}
	return (node);
}

static t_treenode	*insert_node(t_treenode *head, t_treenode *child)
{
	t_treenode	*temp;

	if (!head)
		return (child);
	else if (priority_level(head) > priority_level(child))
	{
		child->left_child = head;
		return (child);
	}
	temp = head;
	while (temp)
	{
		if (temp->right_child == NULLPOINTER || \
			priority_level(temp->right_child) > priority_level(child))
			return (insert_child(temp, child, head));
		else
			temp = temp->right_child;
	}
	return (head);
}

static int	priority_level(t_treenode *child)
{
	if (child->subshell_flag == ON)
		return (6);
	else if (child->type == COMMAND || child->type == IO_FILE)
		return (5);
	else if (child->type == RE_IN || child->type == RE_HERE)
		return (4);
	else if (child->type == RE_OUT || child->type == RE_APPEND)
		return (3);
	else if (child->type == PIPE)
		return (2);
	else if (child->type == D_AMPERSAND || child->type == D_VERTICAL)
		return (1);
	else
		return (0);
}

static t_treenode	*insert_child(t_treenode *parent, t_treenode *child, \
t_treenode *head)
{
	if (parent->left_child == NULLPOINTER && \
		(child->type == COMMAND || child->type == IO_FILE))
		parent->left_child = child;
	else if (parent->right_child == NULLPOINTER)
		parent->right_child = child;
	else
	{
		child->left_child = parent->right_child;
		parent->right_child = child;
	}
	return (head);
}

static t_treenode	*create_pnode(t_tokennode *node)
{
	t_treenode	*new_node;

	new_node = (t_treenode *)malloc_s(sizeof(t_treenode));
	new_node->type = node->type;
	new_node->subshell_flag = OFF;
	new_node->cmd = NULLPOINTER;
	new_node->parsed_data = NULLPOINTER;
	if (new_node->type == COMMAND || IO_FILE)
		new_node->parsed_data = node->parsed_data;
	new_node->left_child = NULLPOINTER;
	new_node->right_child = NULLPOINTER;
	return (new_node);
}
