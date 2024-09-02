/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:20:47 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/02 19:12:56 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_double_vertical_bar(t_data *data, t_treenode *node)
{
	execute_tree_consider_no_command(data, node->left_child);
	if (g_exit_status != 0)
		execute_tree_consider_no_command(data, node->right_child);
	else if (node->right_child && (node->right_child->type == D_AMPERSAND \
				|| node->right_child->type == D_VERTICAL))
		execute_tree_consider_no_command(data, node->right_child->right_child);
}

void	execute_double_ampersand(t_data *data, t_treenode *node)
{
	execute_tree_consider_no_command(data, node->left_child);
	if (g_exit_status == 0)
		execute_tree_consider_no_command(data, node->right_child);
	else if (node->right_child && (node->right_child->type == D_AMPERSAND \
				|| node->right_child->type == D_VERTICAL))
		execute_tree_consider_no_command(data, node->right_child->right_child);
}
