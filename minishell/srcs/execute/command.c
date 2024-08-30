/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:04 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 23:04:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void				execute_command_child(t_envnode *env_list, \
t_treenode *node);
static char				*find_path(t_treenode *node, t_envnode *env_list, \
char *command);
static t_function_type	get_function_type(char *command);
static char				**env_list_to_envp(t_envnode *head);

void	execute_command(t_data *data, t_treenode *node)
{
	pid_t	pid;

	if (execute_tree(data, node->left_child) == ERROR || \
		execute_tree(data, node->right_child) == ERROR)
		return ;
	symbol_process(data, node);
	wildcard_process(node);
	cmd_compress(node);
	if (node->cmd[0] == NULLPOINTER)
		return (set_exit_status(0));
	if (get_function_type(node->cmd[0]) != EXTERN_FUNCTION)
		return (execute_builtin_function(data, node, \
											get_function_type(node->cmd[0])));
	pid = fork_s();
	if (pid == 0)
		return (execute_command_child(data->env_list, node));
	signal_parent();
	wait(&pid);
	if (WIFEXITED(pid))
		set_exit_status(WEXITSTATUS(pid));
	else if (WIFSIGNALED(pid))
		set_exit_status(WTERMSIG(pid) + 128);
	signal_default();
}

static void	execute_command_child(t_envnode *env_list, t_treenode *node)
{
	char	*path;
	DIR		*dir;

	signal_child();
	if (ft_strchr(node->cmd[0], '/'))
	{
		dir = opendir(node->cmd[0]);
		if (dir)
			directory_execute(dir, node->cmd[0]);
		else if (access(node->cmd[0], F_OK) == -1)
			non_exist_execute(node->cmd[0]);
		else
			path = ft_strdup(node->cmd[0]);
	}
	else
		path = find_path(node, env_list, node->cmd[0]);
	if (access(path, X_OK) == -1)
		permission_denied_execute(node->cmd[0]);
	if (execve(path, node->cmd, env_list_to_envp(env_list)) == -1)
		execve_error(node->cmd[0]);
	exit(0);
}

static char	*find_path(t_treenode *node, t_envnode *env_list, char *command)
{
	char	*path_line;
	char	*line;
	char	**path_envp;
	int		i;

	path_line = (get_env_node(env_list, "PATH"))->value;
	if (path_line == NULLPOINTER)
		non_exist_execute(node->cmd[0]);
	path_envp = ft_split(path_line, ':');
	i = -1;
	while (path_envp[++i])
	{
		line = ft_strjoin3(path_envp[i], "/", command);
		if (access(line, F_OK) == 0)
		{
			free(path_envp);
			return (line);
		}
		free(line);
	}
	free(path_envp);
	not_found_execute(node->cmd[0]);
	return (NULLPOINTER);
}

static t_function_type	get_function_type(char *command)
{
	if (ft_str_alphabet_cmp(command, "cd") == 0)
		return (CD_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "echo") == 0)
		return (ECHO_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "env") == 0)
		return (ENV_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "exit") == 0)
		return (EXIT_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "export") == 0)
		return (EXPORT_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "pwd") == 0)
		return (PWD_BUILTIN);
	else if (ft_str_alphabet_cmp(command, "unset") == 0)
		return (UNSET_BUILTIN);
	else
		return (EXTERN_FUNCTION);
}

static char	**env_list_to_envp(t_envnode *head)
{
	char	**envp;
	int		i;

	envp = (char **)malloc_s(sizeof(char *) * (head->total_count + 1));
	i = 0;
	while (head)
	{
		if (head->value)
			envp[i] = ft_strjoin3(head->key, "=", head->value);
		else
			envp[i] = ft_strdup(head->key);
		i++;
		head = head->next;
	}
	envp[i] = NULLPOINTER;
	return (envp);
}
