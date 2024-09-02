#ifndef BUILTIN_H
# define BUILTIN_H

# include "struct.h"

int		execute_builtin_function(t_data *data, t_treenode *node, \
t_function_type func_type);
void	execute_cd(t_data *data, t_treenode *node);
void	execute_echo(t_treenode *node);
void	execute_env(t_envnode *head);
void	execute_exit(t_treenode *node, int pipe_flag);
void	execute_export(t_data *data, t_treenode *node);
void	execute_pwd(t_envnode *head);
void	execute_unset(t_data *data, t_treenode *node);

#endif