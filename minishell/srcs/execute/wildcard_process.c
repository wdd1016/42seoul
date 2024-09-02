#include "minishell.h"

static void	find_wildcard_files(char *wildcard_string, t_filelist *head, \
char *directory);
static void	make_dir_list(DIR *dir, t_filelist *new, char *wildcard_str);
static char	**expand_cmd(char **cmd, int *index, t_filelist *filelist, \
int total_count);

void	wildcard_process(t_treenode *node)
{
	char		*fir_directory;
	t_filelist	head;
	int			i;

	i = -1;
	head.file_name = NULLPOINTER;
	head.total_count = 0;
	head.next = NULLPOINTER;
	while (node->cmd[++i])
	{
		if (ft_strchr(node->cmd[i], '*') == NULLPOINTER)
			continue ;
		fir_directory = ft_strdup(".");
		find_wildcard_files(node->cmd[i], &head, fir_directory);
		free(fir_directory);
		if (head.next)
			node->cmd = expand_cmd(node->cmd, &i, head.next, head.total_count);
		free_file_list(head.next);
		head.total_count = 0;
		head.next = NULLPOINTER;
	}
}

static void	find_wildcard_files(char *wildcard_str, t_filelist *head, \
char *directory)
{
	char		*temp;
	char		*next_dir;
	t_filelist	new;
	t_filelist	*tmp_node;
	DIR			*dir;

	dir = opendir(directory);
	if (!dir)
		return ;
	temp = ft_strchr(wildcard_str, '/');
	if (temp)
	{
		make_dir_list(dir, &new, wildcard_str);
		tmp_node = new.next;
		while (tmp_node)
		{
			next_dir = ft_strjoin3(directory, "/", tmp_node->file_name);
			find_wildcard_files(temp + 1, head, next_dir);
			free(next_dir);
			tmp_node = tmp_node->next;
		}
		free_file_list(new.next);
	}
	else
		make_file_list(dir, head, wildcard_str, directory + 2);
}

static void	make_dir_list(DIR *dir, t_filelist *new, char *wildcard_str)
{
	char	*temp;

	new->file_name = NULLPOINTER;
	new->total_count = 0;
	new->next = NULLPOINTER;
	temp = ft_strchr(wildcard_str, '/');
	*temp = '\0';
	make_file_list(dir, new, wildcard_str, NULLPOINTER);
	*temp = '/';
}

static char	**expand_cmd(char **cmd, int *index, t_filelist *filelist, \
int total_count)
{
	char	**new_cmd;
	int		before_index;
	int		i;

	i = 0;
	while (cmd[i])
		i++;
	new_cmd = (char **)malloc_s(sizeof(char *) * (i + total_count));
	before_index = *index;
	i = -1;
	while (++i < before_index)
		new_cmd[i] = cmd[i];
	while (filelist)
	{
		new_cmd[i++] = filelist->file_name;
		filelist->file_name = NULLPOINTER;
		filelist = filelist->next;
	}
	*index = i - 1;
	free(cmd[before_index]);
	while (cmd[++before_index])
		new_cmd[i++] = cmd[before_index];
	new_cmd[i] = NULLPOINTER;
	free(cmd);
	return (new_cmd);
}
