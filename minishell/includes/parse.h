#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

t_treenode	*build_tree(t_data *data);

t_envnode	*init_envlist(const char **envp);

void		heredoc(t_data *data);

void		add_token(t_data *dt, t_type type);
t_tokennode	*create_tokennode(t_type type);

void		redirect_token(t_data *data);

void		double_bar_token(t_data *data);
void		pipe_token(t_data *data);
void		priority_token(t_data *data);
void		priority_test(t_data *data);

void		tokenize(t_data *dt);
size_t		quote(t_data *data, const char *str, char character, size_t end);

#endif
