#include "minishell.h"

static void	delete_env_node(t_data *data, char *key);

void	execute_unset(t_data *data, t_treenode *node)
{
	char	*command;
	int		i;
	int		j;

	set_exit_status(0);
	if (node->cmd[1] == NULLPOINTER)
		return ;
	i = 0;
	while ((node->cmd)[++i])
	{
		command = (node->cmd)[i];
		j = 0;
		while (command[j] && (ft_isalnum(command[j]) || command[j] == '_'))
			j++;
		if (command[j] == '\0')
			delete_env_node(data, command);
		else
			set_exit_status(1);
	}
}

static void	delete_env_node(t_data *data, char *key)
{
	t_envnode	*temp;
	t_envnode	*prev;

	if (ft_strcmp(data->env_list->key, key) == 0)
	{
		free(data->env_list->key);
		free(data->env_list->value);
		free(data->env_list);
		data->env_list = data->env_list->next;
		return ;
	}
	prev = data->env_list;
	while (prev->next)
	{
		if (ft_strcmp(prev->next->key, key) == 0)
		{
			free(prev->next->key);
			free(prev->next->value);
			temp = prev->next;
			prev->next = prev->next->next;
			free(temp);
			return ;
		}
		prev = prev->next;
	}
}
