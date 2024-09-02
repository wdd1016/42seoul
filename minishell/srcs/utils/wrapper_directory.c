#include "minishell.h"

struct dirent	*readdir_s(DIR *dir)
{
	struct dirent	*file;

	file = readdir(dir);
	if (!file)
		system_error("readdir error\n");
	return (file);
}

void	closedir_s(DIR *dir)
{
	if (closedir(dir) == -1)
		system_error("closedir error\n");
}
