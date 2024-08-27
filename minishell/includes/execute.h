/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:09:42 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 02:49:13 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "struct.h"

void	directory_execute(DIR *dir, char *command);
void	non_exist_execute(char *command);
void	permission_denied_execute(char *command);
void	not_found_execute(char *command);

void	execute_command(t_data *data, t_treenode *node);

void	execute_commands(t_data *data);

#endif