#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
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

typedef struct s_data
{
	char		*line;
	t_envnode	*env_list;
	t_tokennode	*token_list;
	t_pipenode	*pipe_list;
}	t_data;

#endif
