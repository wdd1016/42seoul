/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:09:42 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 05:29:13 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "struct.h"

void		directory_execute(DIR *dir, char *command);
void		non_exist_execute(char *command);
void		permission_denied_execute(char *command);
void		not_found_execute(char *command);

void		execute_command(t_data *data, t_treenode *node);

void		execute_commands(t_data *data);

size_t		expansion(t_envnode *env, char **str_ptr, size_t start, \
char *prev_str);
void		cmd_compress(t_treenode *node);

void		symbol_process(t_data *data, t_treenode *node);

void		wildcard_process(t_treenode *node);
void		make_file_list(DIR *dir, t_filelist *head, \
char *target, char *directory);
char		*get_directory(char *target_string);

#endif