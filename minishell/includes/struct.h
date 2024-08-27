/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:57:25 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 02:57:00 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define NULL 0
# define ON 1
# define OFF 0
# define ERROR -1

# include <stdlib.h>

int	g_exit_status;

typedef struct s_envnode
{
	char				*key;
	char				*value;
	int					total_count;
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

typedef struct s_filelist
{
	char				*file_name;
	int					total_count;
	struct s_filelist	*next;
}	t_filelist;

typedef enum e_function_type
{
	CD_BUILTIN,
	ECHO_BUILTIN,
	ENV_BUILTIN,
	EXIT_BUILTIN,
	EXPORT_BUILTIN,
	PWD_BUILTIN,
	UNSET_BUILTIN,
	EXTERN_FUNCTION
}	t_function_type;

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