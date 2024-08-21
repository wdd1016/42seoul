/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:06:15 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/21 23:51:45 by juyojeon         ###   ########.fr       */
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
	PRIORITY_END
}	t_type;

typedef struct s_tokennode
{
	t_type				type;
	char				*parsed_data;
	struct s_tokennode	*next;
}	t_tokennode;
// token list before assembled tree

typedef struct s_parsenode
{
	t_type				type;
	char				**cmd;
	struct s_parsenode	*left_child;
	struct s_parsenode	*right_child;
}	t_parsenode;
// parsing data tree

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

t_envnode	*init_envlist(char **envp);
t_parsenode	*create_parsenode(t_type type, char **cmd);
void		parse_commands(t_data *data);
void		parse_error(t_data *data, char *msg);
void		tokenize(t_data *dt);
int			add_token(t_data *ddt, t_type type);
void		redirect_token(t_data *data);
void		double_bar_token(t_data *data);
void		pipe_token(t_data *data);
void		priority_token(t_data *data);

#endif
