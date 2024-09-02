#include "minishell.h"

void	*malloc_s(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULLPOINTER)
		system_error("Allocation Error!\n");
	return (ptr);
}

int	fork_s(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		system_error("Fork Error!\n");
	return (pid);
}
