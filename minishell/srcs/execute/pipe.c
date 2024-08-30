/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:28:22 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 21:38:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	wait(&pid);
	wait(&pid2);
	if (WIFEXITED(pid2))
		g_exit_status = WEXITSTATUS(pid2);
	else if (WIFSIGNALED(pid2))
		g_exit_status = WTERMSIG(pid2) + 128;
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
	g_exit_status = 0;
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	execute_tree_consider_no_command(data, node->right_child);
	exit(g_exit_status);
}
