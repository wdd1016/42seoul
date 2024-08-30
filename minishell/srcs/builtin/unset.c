/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:03:56 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 23:04:45 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_env_node(t_envnode *env_list, char *key);

void	execute_unset(t_envnode *head, t_treenode *node)
{
	char	*command;
	int		i;
	int		j;

	set_exit_status(0);
	if (node->cmd[1] == NULLPOINTER)
		return ;
	i = 0;
	while ((node->cmd)[++i])
	{
		command = (node->cmd)[i];
		j = 0;
		while (command[j] && (ft_isalnum(command[j]) || command[j] == '_'))
			j++;
		if (command[i] == '\0')
			delete_env_node(head, command);
		else
			set_exit_status(1);
	}
}

static void	delete_env_node(t_envnode *env_list, char *key)
{
	if (ft_strcmp(env_list->key, key) == 0)
	{
		free(env_list->key);
		free(env_list->value);
		env_list = env_list->next;
		return ;
	}
	while (env_list->next)
	{
		if (ft_strcmp(env_list->next->key, key) == 0)
		{
			free(env_list->next->key);
			free(env_list->next->value);
			env_list->next = env_list->next->next;
			return ;
		}
		env_list = env_list->next;
	}
}
