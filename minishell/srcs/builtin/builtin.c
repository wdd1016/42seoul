/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:29:56 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 18:05:13 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_function_type(char *command)
{
	if (ft_str_alphabet_cmp(command, "cd") == 0)
		return (CD_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "echo") == 0)
		return (ECHO_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "env") == 0)
		return (ENV_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "exit") == 0)
		return (EXIT_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "export") == 0)
		return (EXPORT_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "pwd") == 0)
		return (PWD_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "unset") == 0)
		return (UNSET_BUILTIN);
	else
		return (EXTERN_FUNCTION);
}

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
