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

typedef enum e_type
{
	HEAD,
	RE_INPUT,
	RE_HERE,
	RE_OUTPUT,
	RE_APPEND,
}	t_type;

typedef struct s_tokennode
{
	char				*token_value;
	struct s_tokennode	*next_token;
}	t_tokennode;

typedef struct s_parsenode
{
	t_type				type;
	char				*token_value;
	struct s_parsenode	*left_child;
	struct s_parsenode	*right_child;
}	t_parsenode;

typedef struct s_pipenode
{
	t_parsenode			*parse_tree;
	struct s_pipenode	*next_pipeline;
}	t_pipenode;

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
}	t_c_type;

t_envnode	*init_envlist(char **envp);
t_parsenode	*create_parsenode(t_type type, char *parsed_data);
t_pipenode	*create_pipenode(t_parsenode *parse_tree);

#endif