/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:04:47 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 22:38:50 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "parse.h"
# include "utils.h"

int	g_exit_status;

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
