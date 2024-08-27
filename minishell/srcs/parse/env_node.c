/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:41:54 by danpark           #+#    #+#             */
/*   Updated: 2024/08/28 02:43:29 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			**split_env(char *str);

t_envnode	*init_envlist(const char **envp)
{
	t_envnode	head;
	t_envnode	*tmp_node;
	char		**tmp;
	int			i;

	head.next = NULL;
	head.total_count = 0;
	tmp_node = &head;
	i = 0;
	while (envp[i])
	{
		tmp = split_env(envp[i]);
		if (!ft_strcmp(tmp[0], "OLDPWD"))
		{
			free(tmp[1]);
			tmp[1] = NULL;
		}
		tmp_node->next = create_envnode(&head, tmp[0], tmp[1]);
		free(tmp);
		tmp_node = tmp_node->next;
		i++;
	}
	if (head.next)
		head.next->total_count = head.total_count;
	return (head.next);
}

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

char	**env_list_to_envp(t_envnode *head)
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

char	*get_env_value(t_envnode *env_list, char *key)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, key))
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}

static char	**split_env(char *str)
{
	int		i;
	char	**s_spt;
	char	*equal_address;

	equal_address = ft_strchr(str, '=');
	if (equal_address == NULL)
	{
		s_spt = (char **)malloc_s(sizeof(char *) * 2);
		s_spt[0] = ft_strdup_s(str);
		s_spt[1] = NULL;
		return (s_spt);
	}
	s_spt = (char **)malloc_s(sizeof(char *) * 3);
	s_spt[0] = (char *)malloc_s(sizeof(char) * \
		(ft_strlen(str) - ft_strlen(equal_address) + 1));
	i = -1;
	while (str[++i] != '=')
		s_spt[0][i] = str[i];
	s_spt[0][i] = '\0';
	s_spt[1] = ft_strdup_s(equal_address + 1);
	s_spt[2] = NULL;
	return (s_spt);
}
