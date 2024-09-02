#include "minishell.h"

void	signal_handler(int sig)
{
	(void)sig;
	set_exit_status(1);
	rl_replace_line("", 0);
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}
/* The signal_handler function has an integer parameter sig,
and it should update the global g_exit_status accordingly. */

void	signal_after_process(pid_t status)
{
	set_exit_status(WTERMSIG(status) + 128);
	if (WTERMSIG(status) == SIGQUIT)
		write(STDOUT_FILENO, "Quit: 3\n", 8);
	else
		write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	signal_after_heredoc_process(void)
{
	set_exit_status(1);
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	signal_after_pipe_process(pid_t status)
{
	if (WTERMSIG(status) == SIGQUIT)
		write(STDOUT_FILENO, "Quit: 3\n", 8);
	else
		write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}
