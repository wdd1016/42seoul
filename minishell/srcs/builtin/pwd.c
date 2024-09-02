#include "minishell.h"

void	execute_pwd(t_envnode *head)
{
	t_envnode	*temp;
	char		*cwd;

	cwd = getcwd(NULLPOINTER, 0);
	if (cwd == NULLPOINTER)
	{
		temp = get_env_node(head, "PWD");
		if (temp == NULLPOINTER || temp->value == NULLPOINTER)
		{
			write(STDERR_FILENO, "minishell: pwd: PWD not set\n", 29);
			set_exit_status(1);
			return ;
		}
		cwd = ft_strdup(temp->value);
	}
	write(STDOUT_FILENO, cwd, ft_strlen(cwd));
	write(STDOUT_FILENO, "\n", 1);
	free(cwd);
	set_exit_status(0);
}
