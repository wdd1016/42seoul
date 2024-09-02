#include "minishell.h"

static void	tilde_expansion(t_data *data, char **str_ptr);
static void	double_quote_expansion(t_data *dt, char **str_ptr);
static void	quote_erase(char **str_ptr, size_t start, size_t end);

void	symbol_process(t_data *data, t_treenode *node)
{
	size_t	i;

	i = 0;
	while (node->parsed_data[i])
	{
		if (node->parsed_data[i] == '\'')
			i = quote(data, node->parsed_data, '\'', i);
		else if (node->parsed_data[i] == '\"')
			i = quote(data, node->parsed_data, '\"', i);
		else if (node->parsed_data[i] == '$' && \
		node->parsed_data[i + 1] != ' ' && node->parsed_data[i + 1] != '\0')
			i = expansion(data->env_list, &(node->parsed_data), i + 1, \
						ft_substr(node->parsed_data, 0, i));
		else
			i++;
	}
	node->cmd = ft_split(node->parsed_data, ' ');
	i = -1;
	while (node->cmd[++i])
		tilde_expansion(data, &(node->cmd[i]));
	i = -1;
	while (node->cmd[++i])
		double_quote_expansion(data, &(node->cmd[i]));
}

static void	tilde_expansion(t_data *data, char **str_ptr)
{
	t_envnode	*home;
	char		*temp;

	home = get_env_node(data->env_list, "HOME");
	if (!home)
		return ;
	if ((*str_ptr)[0] == '~' && \
		((*str_ptr)[1] == '\0' || (*str_ptr)[1] == '/'))
	{
		temp = ft_strjoin(home->value, (*str_ptr) + 1);
		free(*str_ptr);
		*str_ptr = temp;
	}
}

static void	double_quote_expansion(t_data *dt, char **str_ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*str_ptr)[i])
	{
		if ((*str_ptr)[i] == '\'')
		{
			quote_erase(str_ptr, i, quote(dt, *str_ptr, '\'', i) - 1);
			i--;
		}
		else if ((*str_ptr)[i] == '\"')
		{
			j = i;
			while ((*str_ptr)[++i] != '\"')
				if ((*str_ptr)[i] == '$' && (*str_ptr)[i + 1] != ' ' && \
					(*str_ptr)[i + 1] != '\0')
					i = expansion(dt->env_list, str_ptr, i + 1, \
								ft_substr(*str_ptr, 0, i)) - 1;
			quote_erase(str_ptr, j, quote(dt, *str_ptr, '\"', j) - 1);
			i--;
		}
		else
			i++;
	}
}

static void	quote_erase(char **str_ptr, size_t start, size_t end)
{
	char	*new_data;
	size_t	i;

	new_data = (char *)malloc_s(sizeof(char) * (ft_strlen(*str_ptr) - 1));
	i = -1;
	while (++i < start)
		new_data[i] = (*str_ptr)[i];
	while (++i < end)
		new_data[i - 1] = (*str_ptr)[i];
	while ((*str_ptr)[++i])
		new_data[i - 2] = (*str_ptr)[i];
	new_data[i - 2] = '\0';
	free(*str_ptr);
	*str_ptr = new_data;
}
