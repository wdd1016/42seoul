#include "minishell.h"

void	directory_execute(DIR *dir, char *command)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": is a directory\n", 17);
	closedir(dir);
	exit(126);
}

void	non_exist_execute(char *command)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": No such file or directory\n", 28);
	exit(127);
}

void	permission_denied_execute(char *command)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": Permission denied\n", 20);
	exit(126);
}

void	not_found_execute(char *command)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": command not found\n", 20);
	exit(127);
}
