/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:19:22 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 01:43:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_path(t_envnode *env_list, char **cmd, char *old_path);
static void	cd_process(t_data *data, char *path, char *old_path, \
char **cmd);

void	execute_cd(t_data *data, t_treenode *node)
{
	char	*old_path;
	char	*path;

	old_path = getcwd(NULLPOINTER, 0);
	path = find_path(data->env_list, node->cmd, old_path);
	if (path)
		cd_process(data, path, old_path, node->cmd);
	free(old_path);
	free(path);
}

static char	*find_path(t_envnode *env_list, char **cmd, char *old_path)
{
	char	*path;

	if (cmd[1] == NULLPOINTER)
		path = ft_strdup((get_env_node(env_list, "HOME"))->value);
	else if (cmd[1][0] == '\0')
		path = ft_strdup(old_path);
	else if (cmd[1][0] == '~' && cmd[1][1] == '/')
		path = ft_strjoin((get_env_node(env_list, "HOME"))->value, cmd[1] + 1);
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		path = ft_strdup((get_env_node(env_list, "OLDPWD"))->value);
		if (path == NULLPOINTER)
		{
			write(STDERR_FILENO, "minishell: cd: OLDPWD not set\n", 30);
			g_exit_status = 1;
			return (NULLPOINTER);
		}
		write(STDOUT_FILENO, path, ft_strlen(path));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		path = ft_strdup(cmd[1]);
	return (path);
}

static void	cd_process(t_data *data, char *path, char *old_path, \
char **cmd)
{
	char	*temp;

	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
			temp = ft_strjoin3("minishell: cd: ", path, \
								": No such file or directory\n");
		else
			temp = ft_strjoin3("minishell: cd: ", path, \
								": Permission denied\n");
		write(STDERR_FILENO, temp, ft_strlen(temp));
		g_exit_status = 1;
		free(temp);
	}
	else
	{
		if (old_path)
			set_env(data, ft_strdup("OLDPWD"), ft_strdup(old_path));
		else
			set_env(data, ft_strdup("OLDPWD"), \
					ft_strdup((get_env_node(data->env_list, "PWD"))->value));
		set_env(data, ft_strdup("PWD"), getcwd(NULLPOINTER, 0));
		g_exit_status = 0;
	}
}
