/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:06:15 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/29 01:14:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

t_treenode	*build_tree(t_data *data);
void		double_bar_token(t_data *data);
void		pipe_token(t_data *data);
void		priority_token(t_data *data);
t_envnode	*init_envlist(const char **envp);
size_t		expansion(t_envnode *env, char **str_ptr, size_t start, \
char *prev_str);
void		heredoc(t_data *data, size_t start, size_t end);
void		parse_commands(t_data *data);
void		redirect_token(t_data *data);
size_t		quote(t_data *data, char *string, char character, size_t end);
void		file_symbol_process(t_data *data, t_tokennode *temp);
void		command_symbol_process(t_data *data, t_tokennode *temp);
void		add_token(t_data *dt, t_type type);
t_tokennode	*create_tokennode(t_type type);
void		tokenize(t_data *dt);

#endif
