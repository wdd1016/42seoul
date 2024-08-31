/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:19:22 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/31 21:56:21 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_path_cd(t_envnode *env_list, char **cmd, char *home_path);
static void	cd_process(t_data *data, char *path, char *old_path);

void	execute_cd(t_data *data, t_treenode *node)
{
	t_envnode	*home;
	char		*old_path;
	char		*path;

	set_exit_status(0);
	home = get_env_node(data->env_list, "HOME");
	if ((home == NULLPOINTER || home->value == NULLPOINTER) && \
		((node->cmd)[1] == NULLPOINTER || ft_strcmp((node->cmd)[1], "~") == 0 \
			|| ft_strcmp((node->cmd)[1], "~") == '/'))
	{
		write(STDERR_FILENO, "minishell: cd: HOME not set\n", 28);
		set_exit_status(1);
		return ;
	}
	old_path = getcwd(NULLPOINTER, 0);
	path = find_path_cd(data->env_list, node->cmd, home->value);
	if (path)
		cd_process(data, path, old_path);
	free(old_path);
	free(path);
}

static char	*find_path_cd(t_envnode *env_list, char **cmd, char *home_path)
{
	t_envnode	*temp;

	if (cmd[1] == NULLPOINTER)
		return (ft_strdup(home_path));
	else if (cmd[1][0] == '\0')
		return (getcwd(NULLPOINTER, 0));
	else if (cmd[1][0] == '~' && (cmd[1][1] == '/' || cmd[1][1] == '\0'))
		return (ft_strjoin(home_path, cmd[1] + 1));
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		temp = get_env_node(env_list, "OLDPWD");
		if (temp == NULLPOINTER || temp->value == NULLPOINTER)
		{
			write(STDERR_FILENO, "minishell: cd: OLDPWD not set\n", 30);
			set_exit_status(1);
			return (NULLPOINTER);
		}
		write(STDOUT_FILENO, temp->value, ft_strlen(temp->value));
		write(STDOUT_FILENO, "\n", 1);
		return (ft_strdup(temp->value));
	}
	else
		return (ft_strdup(cmd[1]));
}

static void	cd_process(t_data *data, char *path, char *old_path)
{
	t_envnode	*pwd_node;
	char		*temp;

	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
			temp = ft_strjoin3("minishell: cd: ", path, \
								": No such file or directory\n");
		else
			temp = ft_strjoin3("minishell: cd: ", path, \
								": Permission denied\n");
		write(STDERR_FILENO, temp, ft_strlen(temp));
		set_exit_status(1);
		free(temp);
		return ;
	}
	set_env_node(data, ft_strdup("PWD"), getcwd(NULLPOINTER, 0));
	pwd_node = get_env_node(data->env_list, "PWD");
	if (old_path)
		set_env_node(data, ft_strdup("OLDPWD"), ft_strdup(old_path));
	else if (pwd_node && pwd_node->value)
		set_env_node(data, ft_strdup("OLDPWD"), ft_strdup(pwd_node->value));
	else
		set_env_node(data, ft_strdup("OLDPWD"), ft_strdup(path));
}
