/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:29:56 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 03:35:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin_function(t_data *data, t_treenode *node, \
t_function_type func_type)
{
	if (func_type == CD_BUILTIN)
		execute_cd(data, node);
	else if (func_type == ECHO_BUILTIN)
		execute_echo(node);
	else if (func_type == ENV_BUILTIN)
		execute_env(data->env_list);
	else if (func_type == EXIT_BUILTIN)
		execute_exit(node, data->token.pipe_flag);
	else if (func_type == EXPORT_BUILTIN)
		execute_export(data, node);
	else if (func_type == PWD_BUILTIN)
		execute_pwd(data->env_list);
	else if (func_type == UNSET_BUILTIN)
		execute_unset(data->env_list, node);
}
