#include "minishell.h"

static void	pipe_after_process(pid_t pid2);
static void	execute_pipe_left_child(t_data *data, t_treenode *node, \
int *pipe_fd);
static void	execute_pipe_right_child(t_data *data, t_treenode *node, \
int *pipe_fd);

void	execute_pipe(t_data *data, t_treenode *node)
{
	pid_t	pid;
	pid_t	pid2;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork_s();
	if (pid == 0)
		execute_pipe_left_child(data, node, pipe_fd);
	signal_parent();
	pid2 = fork_s();
	if (pid2 == 0)
		execute_pipe_right_child(data, node, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	pipe_after_process(pid2);
}

static void	pipe_after_process(pid_t pid2)
{
	pid_t	temp;
	pid_t	status1;
	pid_t	status2;

	if (wait(&temp) == pid2)
	{
		wait(&status1);
		status2 = temp;
	}
	else
	{
		wait(&status2);
		status1 = temp;
	}
	set_exit_status(WEXITSTATUS(status2));
	if (WIFSIGNALED(status2))
	{
		set_exit_status(WTERMSIG(status2) + 128);
		signal_after_pipe_process(status2);
	}
}

static void	execute_pipe_left_child(t_data *data, t_treenode *node, \
int *pipe_fd)
{
	signal_child();
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	execute_tree_consider_no_command(data, node->left_child);
	exit(g_exit_status);
}

static void	execute_pipe_right_child(t_data *data, t_treenode *node, \
int *pipe_fd)
{
	signal_child();
	set_exit_status(0);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	execute_tree_consider_no_command(data, node->right_child);
	exit(g_exit_status);
}
