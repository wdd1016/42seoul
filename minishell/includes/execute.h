/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:09:42 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 06:03:32 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "struct.h"

void	directory_execute(DIR *dir, char *command);
void	non_exist_execute(char *command);
void	permission_denied_execute(char *command);
void	not_found_execute(char *command);

int		execute_command(t_data *data, t_treenode *node);

void	execute_double_vertical_bar(t_data *data, t_treenode *node);
void	execute_double_ampersand(t_data *data, t_treenode *node);

void	execute_commands(t_data *data);
int		execute_tree_consider_no_command(t_data *data, t_treenode *node);
int		execute_tree(t_data *data, t_treenode *node);

size_t	expansion(t_envnode *env, char **str_ptr, size_t start, char *prev_str);

void	execute_pipe(t_data *data, t_treenode *node);

int		execute_redirect(t_data *data, t_treenode *node);

void	symbol_process(t_data *data, t_treenode *node);

void	wildcard_process(t_treenode *node);

void	make_file_list(DIR *dir, t_filelist *head, char *target, char *dpath);

#endif