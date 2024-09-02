#include "minishell.h"

void	execute_env(t_envnode *head)
{
	set_exit_status(0);
	if (!head)
		return ;
	while (head)
	{
		if (head->value)
		{
			write(STDOUT_FILENO, head->key, ft_strlen(head->key));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, head->value, ft_strlen(head->value));
			write(STDOUT_FILENO, "\n", 1);
		}
		head = head->next;
	}
}
