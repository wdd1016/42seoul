/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:50:00 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 21:36:32 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_print(t_envnode *head);
static int	inspect_command_export(char *command, int *append_flag);
static void	export_declare(t_data *data, char *command, int append_flag);
static char	**env_list_to_export(t_envnode *head);

void	execute_export(t_data *data, t_treenode *node)
{
	int	append_flag;
	int	i;

	set_exit_status(0);
	if (node->cmd[1] == NULLPOINTER)
		return (export_print(data->env_list));
	i = 0;
	while (node->cmd[++i])
	{
		append_flag = OFF;
		if (inspect_command_export(node->cmd[i], &append_flag) == ERROR)
		{
			write(STDERR_FILENO, "minishell: export: `", 20);
			write(STDERR_FILENO, node->cmd[i], ft_strlen(node->cmd[i]));
			write(STDERR_FILENO, "': not a valid identifier\n", 26);
			set_exit_status(1);
			continue ;
		}
		export_declare(data, node->cmd[i], append_flag);
	}
}

static void	export_print(t_envnode *head)
{
	char	**envs;
	int		i;

	if (!head)
		return ;
	envs = env_list_to_export(head);
	i = 0;
	while (envs[i])
	{
		write(STDOUT_FILENO, envs[i], ft_strlen(envs[i]));
		free(envs[i]);
		i++;
	}
	free(envs);
}

static int	inspect_command_export(char *command, int *append_flag)
{
	int	i;

	i = 0;
	if (ft_isalpha(command[i]) == OFF && command[i] != '_')
		return (ERROR);
	i++;
	while (command[i] && command[i] != '=')
	{
		if (command[i] == '+' && command[i + 1] == '=')
			(*append_flag) = ON;
		else if (ft_isalnum(command[i]) == OFF && command[i] != '_')
			return (ERROR);
		i++;
	}
	return (ON);
}

static void	export_declare(t_data *data, char *command, int append_flag)
{
	t_envnode	*same_key_node;
	char		*equal_ptr;
	char		*temp;

	equal_ptr = ft_strchr(command, '=');
	if (equal_ptr == NULLPOINTER && \
	get_env_node(data->env_list, command) == NULLPOINTER)
		return (set_env_node(data, ft_strdup(command), NULLPOINTER));
	else if (equal_ptr == NULLPOINTER)
		return ;
	*equal_ptr = '\0';
	if (append_flag == ON)
		*(equal_ptr - 1) = '\0';
	same_key_node = get_env_node(data->env_list, command);
	if (same_key_node == NULLPOINTER)
		return (set_env_node(data, ft_strdup(command), \
								ft_strdup(equal_ptr + 1)));
	if (append_flag == ON)
		temp = ft_strjoin(same_key_node->value, equal_ptr + 1);
	else
		temp = ft_strdup(equal_ptr + 1);
	free(same_key_node->value);
	same_key_node->value = temp;
}

static char	**env_list_to_export(t_envnode *head)
{
	char	**envs;
	char	*temp;
	int		i;

	if (!head)
		return (NULLPOINTER);
	envs = (char **)malloc_s(sizeof(char *) * (head->total_count + 1));
	i = 0;
	while (head)
	{
		if (head->value)
		{
			temp = ft_strjoin3("=\"", head->value, "\"\n");
			envs[i] = ft_strjoin3("declare -x ", head->key, temp);
			free(temp);
		}
		else
			envs[i] = ft_strjoin3("declare -x ", head->key, "\n");
		head = head->next;
		i++;
	}
	envs[i] = NULLPOINTER;
	quick_sort(envs, 0, i - 1);
	return (envs);
}
