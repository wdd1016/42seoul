/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:21:12 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 21:37:29 by juyojeon         ###   ########.fr       */
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
	new_node->next = NULLPOINTER;
	head->total_count++;
	return (new_node);
}

t_envnode	*get_env_node(t_envnode *env_list, char *key)
{
	if (!env_list)
		return (NULLPOINTER);
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, key))
			return (env_list);
		env_list = env_list->next;
	}
	return (NULLPOINTER);
}

void	set_env_node(t_data *data, char *key, char *value)
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
