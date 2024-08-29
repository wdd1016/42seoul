/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_preprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 03:13:05 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 03:33:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	envp[i] = NULLPOINTER;
	return (envp);
}
