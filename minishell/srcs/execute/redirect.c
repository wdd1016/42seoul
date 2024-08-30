/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 03:49:40 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 21:37:38 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect_preprocess(t_data *data, t_treenode *file_node);
static int	execute_in_redirect(const char *file_name_or_fd, t_type type);
static int	execute_out_redirect(const char *file_name, t_type type);

int	execute_redirect(t_data *data, t_treenode *node)
{
	if (node == NULLPOINTER)
		return (ON);
	else if (redirect_preprocess(data, node->left_child) == ERROR)
		return (ERROR);
	else if (node->type == RE_IN || node->type == RE_HERE)
	{
		if (execute_in_redirect(node->left_child->cmd[0], node->type) == ERROR)
			return (ERROR);
	}
	else if (node->type == RE_OUT || node->type == RE_APPEND)
	{
		if (execute_out_redirect(node->left_child->cmd[0], node->type) == ERROR)
			return (ERROR);
	}
	return (execute_redirect(data, node->right_child));
}

static int	redirect_preprocess(t_data *data, t_treenode *file_node)
{
	symbol_process(data, file_node);
	wildcard_process(file_node);
	cmd_compress(file_node);
	if (file_node->cmd[0] == NULLPOINTER || file_node->cmd[1])
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, file_node->parsed_data, \
				ft_strlen(file_node->parsed_data));
		write(STDERR_FILENO, ": ambiguous redirect\n", 21);
		g_exit_status = 1;
		return (ERROR);
	}
	return (ON);
}

static int	execute_in_redirect(const char *file_name_or_fd, t_type type)
{
	int	fd;

	if (type == RE_IN)
	{
		fd = open(file_name_or_fd, O_RDONLY);
		if (fd == -1)
		{
			write(STDERR_FILENO, "minishell: ", 11);
			write(STDERR_FILENO, file_name_or_fd, ft_strlen(file_name_or_fd));
			if (!access(file_name_or_fd, F_OK))
				write(STDERR_FILENO, ": Permission denied\n", 20);
			else
				write(STDERR_FILENO, ": No such file or directory\n", 28);
			g_exit_status = 1;
			return (ERROR);
		}
	}
	else
		fd = ft_atoi(file_name_or_fd);
	dup2(fd, STDIN_FILENO);
	if (type == RE_IN)
		close(fd);
	return (ON);
}

static int	execute_out_redirect(const char *file_name, t_type type)
{
	int	fd;

	if (access(file_name, W_OK) && !access(file_name, F_OK))
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, file_name, ft_strlen(file_name));
		write(STDERR_FILENO, ": Permission denied\n", 20);
		g_exit_status = 1;
		return (ERROR);
	}
	if (type == RE_OUT)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		write(STDERR_FILENO, "minishell: ", 11);
		write(STDERR_FILENO, file_name, ft_strlen(file_name));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		g_exit_status = 1;
		return (ERROR);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (ON);
}
