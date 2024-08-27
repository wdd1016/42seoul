/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:29:56 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 00:39:30 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin_function(t_data *data, t_treenode *node, \
t_function_type func_type)
{
	if (func_type == CD_BUILTIN)
		execute_cd(data, node);
	else if (func_type == ECHO_BUILTIN)
		execute_echo(data, node);
	else if (func_type == ENV_BUILTIN)
		execute_env(data, node);
	else if (func_type == EXIT_BUILTIN)
		execute_exit(data, node);
	else if (func_type == EXPORT_BUILTIN)
		execute_export(data, node);
	else if (func_type == PWD_BUILTIN)
		execute_pwd(data, node);
	else if (func_type == UNSET_BUILTIN)
		execute_unset(data, node);
}
