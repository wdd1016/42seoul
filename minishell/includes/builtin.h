/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:33:21 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 00:38:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "struct.h"

void	execute_builtin_function(t_data *data, t_treenode *node, \
t_function_type func_type);
void	execute_cd(t_data *data, t_treenode *node);
void	execute_echo(t_data *data, t_treenode *node);
void	execute_env(t_data *data, t_treenode *node);
void	execute_exit(t_data *data, t_treenode *node);
void	execute_export(t_data *data, t_treenode *node);
void	execute_pwd(t_data *data, t_treenode *node);
void	execute_unset(t_data *data, t_treenode *node);

#endif