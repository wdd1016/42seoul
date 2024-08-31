/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:04 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 02:51:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int				execute_command_child(t_envnode *env_list, \
t_treenode *node);
static char				*find_path_cmd(t_treenode *node, t_envnode *env_list, \
char *command);
static t_function_type	get_function_type(char *command);
static char				**env_list_to_envp(t_envnode *head);

int	execute_command(t_data *data, t_treenode *node)
{
	pid_t	pid;

	if (execute_tree_consider_no_command(data, node->left_child) == ERROR || \
		execute_tree_consider_no_command(data, node->right_child) == ERROR)
		return (ERROR);
	symbol_process(data, node);
	wildcard_process(node);
	if (node->cmd[0] == NULLPOINTER)
	{
		set_exit_status(0);
		return (OFF);
	}
	if (get_function_type(node->cmd[0]) != EXTERN_FUNCTION)
		return (execute_builtin_function(data, node, \
											get_function_type(node->cmd[0])));
	pid = fork_s();
	if (pid == 0)
		return (execute_command_child(data->env_list, node));
	signal_parent();
	wait(&pid);
	signal_default();
	set_exit_status(WEXITSTATUS(pid));
	if (WIFSIGNALED(pid))
		signal_after_process(pid);
	return (ON);
}

static int	execute_command_child(t_envnode *env_list, t_treenode *node)
{
	char	*path;
	DIR		*dir;

	signal_child();
	if (node->cmd[0][0] == '\0')
		not_found_execute(node->cmd[0]);
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
		path = find_path_cmd(node, env_list, node->cmd[0]);
	if (access(path, X_OK) == -1)
		permission_denied_execute(node->cmd[0]);
	if (execve(path, node->cmd, env_list_to_envp(env_list)) == -1)
		execve_error(node->cmd[0]);
	exit(0);
	return (0);
}

static char	*find_path_cmd(t_treenode *node, t_envnode *env_list, char *command)
{
	t_envnode	*temp;
	char		*line;
	char		**path_envp;
	int			i;

	temp = get_env_node(env_list, "PATH");
	if (temp == NULLPOINTER || temp->value == NULLPOINTER)
		non_exist_execute(node->cmd[0]);
	path_envp = ft_split(temp->value, ':');
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
