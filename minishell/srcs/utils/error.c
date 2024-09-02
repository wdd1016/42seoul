#include "minishell.h"

void	parse_error(t_data *data, char *msg)
{
	write(STDERR_FILENO, "minishell: syntax error near unexpected token `", 47);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\'\n", 2);
	set_exit_status(258);
	free_tokens(data);
	data->token.syntax_flag = ON;
}

void	system_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	eof_exit(void)
{
	write(STDOUT_FILENO, "\033[1A", 4);
	write(STDOUT_FILENO, "\033[11C", 5);
	write(STDOUT_FILENO, "exit\n", 5);
	exit(g_exit_status);
}

void	execve_error(char *command)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": command not exectuted\n", 24);
	exit(1);
}
