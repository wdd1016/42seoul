/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:57:25 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/26 21:00:23 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

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

typedef struct s_token_data
{
	t_tokennode	*head;
	t_tokennode	*temp;
	size_t		start;
	size_t		end;
	size_t		bracket_count;
	int			command_flag;
	int			syntax_flag;
}	t_token_data;

typedef struct s_data
{
	char			*line;
	size_t			line_length;
	t_token_data	token;
	t_envnode		*env_list;
	t_herenode		*heredoc_list;
	t_treenode		*parse_tree;
}	t_data;

#endif