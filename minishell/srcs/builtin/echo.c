#include "minishell.h"

static size_t	is_option(char **cmd);

void	execute_echo(t_treenode *node)
{
	size_t	last_option_idx;
	size_t	idx;

	set_exit_status(0);
	last_option_idx = is_option(node->cmd);
	idx = last_option_idx + 1;
	if (node->cmd[idx] != NULLPOINTER)
	{
		while ((node->cmd)[idx])
		{
			write(STDOUT_FILENO, (node->cmd)[idx], ft_strlen((node->cmd)[idx]));
			if ((node->cmd)[idx + 1])
				write(STDOUT_FILENO, " ", 1);
			idx++;
		}
	}
	if (last_option_idx == 0)
		write(STDOUT_FILENO, "\n", 1);
}

static size_t	is_option(char **cmd)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] != '\0')
				return (i - 1);
		}
		else
			return (i - 1);
		i++;
	}
	return (i - 1);
}
