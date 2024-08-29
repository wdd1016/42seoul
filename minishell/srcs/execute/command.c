/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:04 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/29 23:58:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	command_wildcard_process(t_treenode *node);
static char	**expand_cmd(char **cmd, int *index, t_filelist *filelist);
static void	execute_command_child(t_envnode *env_list, t_treenode *node);
static char	*find_path(t_treenode *node, t_envnode *env_list, char *command);

void	execute_command(t_data *data, t_treenode *node)
{
	t_function_type	func_type;
	pid_t			pid;

	command_wildcard_process(node);
	func_type = get_function_type(node->cmd[0]);
	if (func_type != EXTERN_FUNCTION)
		execute_builtin_function(data, node, func_type);
	else
	{
		
		pid = fork_s();
		if (pid == 0)
			execute_command_child(data->env_list, node);
		else
		{
			signal_parent();
			wait(&pid);
			if (WIFEXITED(pid))
				g_exit_status = WEXITSTATUS(pid);
			else if (WIFSIGNALED(pid))
				g_exit_status = WTERMSIG(pid) + 128;
			signal_default();
		}
	}
}

static void	command_wildcard_process(t_treenode *node)
{
	t_filelist	*filelist;
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (node->cmd[++i])
	{
		if (ft_strchr(node->cmd[i], '*') == NULL)
			continue ;
		filelist = find_wildcard_files(node->cmd[i]);
		if (filelist)
			node->cmd = expand_cmd(node->cmd, &i, filelist);
		free_file_list(filelist);
	}		
}

static char	**expand_cmd(char **cmd, int *index, t_filelist *filelist)
{
	char	**new_cmd;
	int		before_index;
	int		i;

	i = 0;
	while (cmd[i])
		i++;
	new_cmd = (char **)malloc_s(sizeof(char *) * (i + filelist->total_count));
	before_index = *index;
	i = -1;
	while (++i < before_index)
		new_cmd[i] = cmd[i];
	while (filelist)
	{
		new_cmd[++i] = filelist->file_name;
		filelist = filelist->next;
	}
	*index = i;
	while (cmd[++before_index])
		new_cmd[++i] = cmd[before_index];
	new_cmd[++i] = NULL;
	free(cmd);
	return (new_cmd);
}

static void	execute_command_child(t_envnode *env_list, t_treenode *node)
{
	char	*path;
	char	**envp;
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
	char	**path_envp;
	int		i;

	path_line = (get_env_node(env_list, "PATH"))->value;
	if (path_line == NULL)
		non_exist_execute(node->cmd[0]);
	path_envp = ft_split(path_line, ':');
	i = -1;
	while (path_envp[++i])
	{
		path_line = ft_strjoin3(path_envp[i], "/", command);
		if (access(path_line, F_OK) == 0)
		{
			free(path_envp);
			return (path_line);
		}
		free(path_line);
	}
	free(path_envp);
	not_found_execute(node->cmd[0]);
	return (NULL);
}
