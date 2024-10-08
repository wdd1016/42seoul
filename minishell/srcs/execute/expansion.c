#include "minishell.h"

static size_t	combine_str(char *prev_str, t_envnode *env, char **str_ptr, \
size_t end);
static size_t	exit_code_expansion(char **str_ptr, char *prev_str, \
size_t start);

size_t	expansion(t_envnode *env, char **str_ptr, size_t start, char *prev_str)
{
	size_t	end;
	char	*key;

	end = start;
	if ((*str_ptr)[end] == '?')
		return (exit_code_expansion(str_ptr, prev_str, start));
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

static size_t	exit_code_expansion(char **str_ptr, char *prev_str, \
size_t start)
{
	char	*intenger;
	char	*temp;
	size_t	new_idx;

	intenger = ft_itoa(g_exit_status);
	new_idx = ft_strlen(prev_str) + ft_strlen(intenger);
	temp = ft_strjoin3(prev_str, intenger, *str_ptr + start + 1);
	free(prev_str);
	free(*str_ptr);
	free(intenger);
	*str_ptr = temp;
	return (new_idx);
}
