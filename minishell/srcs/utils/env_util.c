/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:21:12 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 01:25:45 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envnode	*create_envnode(t_envnode *head, char *key, char *value)
{
	t_envnode	*new_node;

	new_node = (t_envnode *)malloc_s(sizeof(t_envnode));
	new_node->key = key;
	new_node->value = value;
	new_node->total_count = 0;
	new_node->next = NULL;
	head->total_count++;
	return (new_node);
}

const char	**env_list_to_envp(t_envnode *head)
{
	char		**envp;
	int			i;

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
	envp[i] = NULL;
	return (envp);
}

t_envnode	*get_env_node(t_envnode *env_list, char *key)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, key))
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

void	set_env(t_data *data, char *key, char *value)
{
	t_envnode	*temp;

	temp = data->env_list;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			free(temp->key);
			free(temp->value);
			temp->key = key;
			temp->value = value;
			return ;
		}
		temp = temp->next;
	}
	temp = create_envnode(data->env_list, key, value);
	temp->next = data->env_list;
	temp->total_count = data->env_list->total_count;
	data->env_list = temp;
}
