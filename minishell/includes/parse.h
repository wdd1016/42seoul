/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:06:15 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 03:33:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

t_treenode	*build_tree(t_data *data);

t_envnode	*init_envlist(const char **envp);

void		heredoc(t_data *data, size_t start, size_t end);

void		add_token(t_data *dt, t_type type);
t_tokennode	*create_tokennode(t_type type);
void		double_bar_token(t_data *data);
void		pipe_token(t_data *data);
void		priority_token(t_data *data);

void		redirect_token(t_data *data);

void		tokenize(t_data *dt);
size_t		quote(t_data *data, char *string, char character, size_t end);

#endif
