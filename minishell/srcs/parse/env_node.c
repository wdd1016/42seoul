/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:41:54 by danpark           #+#    #+#             */
/*   Updated: 2024/08/18 00:40:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_envnode	*create_envnode(char *key, char *value);
static char			**split_env(char *str);

t_envnode	*init_envlist(char **envp)
{
	int			i;
	char		**tmp;
	t_envnode	*tmp_node;
	t_envnode	*head_node;

	i = -1;
	head_node = create_envnode(NULL, NULL);
	tmp_node = head_node;
	while (envp[++i])
	{
		tmp = split_env(envp[i]);
		if (!ft_strcmp(tmp[0], "OLDPWD"))
		{
			free(tmp[1]);
			tmp[1] = NULL;
		}
		tmp_node->next = create_envnode(tmp[0], tmp[1]);
		free(tmp);
		tmp_node = tmp_node->next;
	}
	return (head_node);	
}

static t_envnode	*create_envnode(char *key, char *value)
{
	t_envnode	*new_node;

	new_node = (t_envnode *)malloc(sizeof(t_envnode));
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
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
