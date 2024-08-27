/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:47:17 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 01:10:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	combine_str(char *prev_str, t_envnode *env, char **str_ptr, \
size_t end);

size_t	expansion(t_envnode *env, char **str_ptr, size_t start, char *prev_str)
{
	size_t	end;
	char	*key;

	end = start;
	if ((*str_ptr)[end] == '?')
	{
		key = ft_itoa(g_exit_status);
		end++;
	}
	else
	{
		while ((*str_ptr)[end] && ft_isalnum((*str_ptr)[end]))
			end++;
		key = ft_substr(*str_ptr, start, end - start);
	}
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			break ;
		env = env->next;
	}
	free(key);
	return (combine_str(prev_str, env, str_ptr, end));
}

static size_t	combine_str(char *prev_str, t_envnode *env, char **str_ptr, \
size_t end)
{
	char	*temp;
	size_t	new_idx;

	if (env)
	{
		new_idx = ft_strlen(prev_str) + ft_strlen(env->value);
		temp = ft_strjoin3(prev_str, env->value, *str_ptr + end);
	}
	else
	{
		new_idx = ft_strlen(prev_str);
		temp = ft_strjoin(prev_str, *str_ptr + end);
	}
	free(prev_str);
	free(*str_ptr);
	*str_ptr = temp;
	return (new_idx);
}
