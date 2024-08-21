/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:51:14 by danpark           #+#    #+#             */
/*   Updated: 2024/08/21 23:49:56 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parsenode	*create_parsenode(t_type type, char **cmd)
{
	t_parsenode	*new_node;

	new_node = (t_parsenode *)malloc_s(sizeof(t_parsenode));
	new_node->type = type;
	new_node->cmd = cmd;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	return (new_node);
}
