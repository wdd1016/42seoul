/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:06:15 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 22:38:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define PATH_MAX 4096
# define ARG_MAX 262144
# define ON 1
# define OFF 0

typedef struct s_envnode
{
	char				*key;
	char				*value;
	struct s_envnode	*next;
}	t_envnode;
// envp to linked list

typedef enum e_type
{
	COMMAND,
	RE_IN,
	RE_HERE,
	RE_OUT,
	RE_APPEND,
	D_VERTICAL,
	D_AMPERSAND,
	PIPE,
	PRIORITY_START,
	PRIORITY_END,
	SUB_SHELL,
	IO_FILE
}	t_type;

typedef struct s_tokennode
{
	t_type				type;
	char				*parsed_data;
	char				**cmd;
	struct s_tokennode	*next;
}	t_tokennode;
// token list before assembled tree

typedef struct s_treenode
{
	t_type				type;
	int					subshell_flag;
	char				**cmd;
	char				*file;
	struct s_treenode	*left_child;
	struct s_treenode	*right_child;
}	t_treenode;
// parsing data tree

typedef struct s_herenode
{
	char				*file_name;
	int					fd;
	struct s_herenode	*next;
}	t_herenode;

typedef enum e_func_type
{
	EXTERN_FUNC,
	ECHO_FUNC,
	CD_FUNC,
	PWD_FUNC,
	EXPORT_FUNC,
	UNSET_FUNC,
	ENV_FUNC,
	EXIT_FUNC,
	DEFAULT,
}	t_func_type;

t_treenode	*build_tree(t_data *data);

void		double_bar_token(t_data *data);
void		pipe_token(t_data *data);
void		priority_token(t_data *data);

t_envnode	*init_envlist(char **envp);

size_t		expansion(t_envnode *env, char **str_ptr, size_t start, char *prev_str);

void		heredoc(t_data *data, size_t start, size_t end);

void		parse_commands(t_data *data);
void		parse_error(t_data *data, char *msg);

void		redirect_token(t_data *data);

size_t		quote(t_data *data, char *string, char character, size_t end);
void		file_symbol_process(t_data *data, t_tokennode *temp);
void		command_symbol_process(t_data *data, t_tokennode *temp);

void		add_token(t_data *dt, t_type type);
t_tokennode	*create_tokennode(t_type type);

void	tokenize(t_data *dt);

#endif
