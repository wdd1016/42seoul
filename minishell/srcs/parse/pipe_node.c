/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:11:55 by danpark           #+#    #+#             */
/*   Updated: 2024/08/17 23:59:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipenode	*create_pipenode(t_parsenode *parse_tree)
{
	t_pipenode	*new_node;

	new_node = (t_pipenode *)malloc(sizeof(t_pipenode));
	new_node->parse_tree = parse_tree;
	new_node->next_pipeline = NULL;
	return (new_node);
}
