/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:21:12 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/29 02:19:12 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_insert_envnode(int difference, t_envnode *node, \
char *key, char *value);

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
			envp[i] = ft_strjoin(head->key, "=");
		i++;
		head = head->next;
	}
	envp[i] = NULL;
	return (envp);
}

const char	*get_env_value(t_envnode *env_list, char *key)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, key))
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}

void	set_env(t_envnode **env_list, char *key, char *value)
{
	int			difference;
	t_envnode	*temp;

	temp = *env_list;
	difference = ft_strcmp(temp->key, key);
	if (difference > 0)
	{
		*env_list = create_envnode(temp, key, value);
		(*env_list)->total_count = temp->total_count;
		(*env_list)->next = temp;
		return ;
	}
	else if (difference == 0)
		return (change_insert_envnode(difference, temp, key, value));
	while (temp->next)
	{
		difference = ft_strcmp(temp->key, key);
		if (difference >= 0)
			return (change_insert_envnode(difference, temp, key, value));
	}
	return (change_insert_envnode(difference, temp, key, value));
}

static void	change_insert_envnode(int difference, t_envnode *node, \
char *key, char *value)
{
	if (difference == 0)
	{
		free(node->key);
		free(node->value);
		node->key = key;
		node->value = value;
	}
	else
	{
		node->next = create_envnode(node->next, key, value);
	}
}
