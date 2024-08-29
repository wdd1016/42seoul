/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:41:54 by danpark           #+#    #+#             */
/*   Updated: 2024/08/30 01:38:46 by juyojeon         ###   ########.fr       */
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

	head.next = NULLPOINTER;
	head.total_count = 0;
	tmp_node = &head;
	i = -1;
	while (envp[++i])
	{
		tmp = split_env(envp[i]);
		if (ft_strcmp(tmp[0], "OLDPWD") == 0)
		{
			free(tmp[1]);
			tmp[1] = NULLPOINTER;
		}
		tmp_node->next = create_envnode(&head, tmp[0], tmp[1]);
		free(tmp);
		tmp_node = tmp_node->next;
	}
	if (head.next)
		head.next->total_count = head.total_count;
	return (head.next);
}

static char	**split_env(char *str)
{
	int		i;
	char	**s_spt;
	char	*equal_address;

	equal_address = ft_strchr(str, '=');
	if (equal_address == NULLPOINTER)
	{
		s_spt = (char **)malloc_s(sizeof(char *) * 2);
		s_spt[0] = ft_strdup(str);
		s_spt[1] = NULLPOINTER;
		return (s_spt);
	}
	s_spt = (char **)malloc_s(sizeof(char *) * 3);
	s_spt[0] = (char *)malloc_s(sizeof(char) * \
		(ft_strlen(str) - ft_strlen(equal_address) + 1));
	i = -1;
	while (str[++i] != '=')
		s_spt[0][i] = str[i];
	s_spt[0][i] = '\0';
	s_spt[1] = ft_strdup(equal_address + 1);
	s_spt[2] = NULLPOINTER;
	return (s_spt);
}
