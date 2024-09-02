#include "minishell.h"

static void			heredoc_child(t_data *data, t_herenode *node, char *target);
static void			heredoc_parents(t_data *data, t_herenode *node, pid_t pid);
static t_herenode	*add_heredoc_node(t_data *data);

void	heredoc(t_data *data)
{
	struct termios	old_termios;
	t_herenode		*node;
	pid_t			pid;

	tcgetattr(STDIN_FILENO, &old_termios);
	node = add_heredoc_node(data);
	pid = fork_s();
	if (pid == 0)
		heredoc_child(data, node, data->token.temp->parsed_data);
	else
	{
		signal_parent();
		wait(&pid);
		signal_default();
		tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
		heredoc_parents(data, node, pid);
	}
}

static void	heredoc_child(t_data *data, t_herenode *node, char *target)
{
	char	*ln;
	size_t	i;

	signal_heredoc_child();
	while (1)
	{
		ln = readline("> ");
		if (ln == NULLPOINTER || ft_strcmp(ln, target) == 0)
			break ;
		i = 0;
		while (ln[i])
		{
			if (ln[i] == '$' && ln[i + 1] != ' ' && ln[i + 1] != '\0')
				i = expansion(data->env_list, &ln, i + 1, ft_substr(ln, 0, i));
			else
				i++;
		}
		write(node->fd, ln, ft_strlen(ln));
		write(node->fd, "\n", 1);
		free(ln);
	}
	if (ln == NULLPOINTER)
		write(STDOUT_FILENO, "\033[1A\033[2C", 8);
	close(node->fd);
	exit(0);
}

static void	heredoc_parents(t_data *data, t_herenode *node, pid_t pid)
{
	if (WIFSIGNALED(pid))
	{
		signal_after_heredoc_process();
		close(node->fd);
		unlink(node->file_name);
		free_tokens(data);
		data->token.syntax_flag = ON;
	}
	else
	{
		close(node->fd);
		node->fd = open(node->file_name, O_RDONLY);
		if (node->fd == -1)
			system_error("Open system call Error!\n");
		unlink(node->file_name);
		free(data->token.temp->parsed_data);
		data->token.temp->parsed_data = ft_itoa(node->fd);
	}
}

static t_herenode	*add_heredoc_node(t_data *data)
{
	t_herenode	*temp;
	t_herenode	*node;

	temp = (t_herenode *)malloc_s(sizeof(t_herenode));
	temp->next = NULLPOINTER;
	temp->file_name = generate_random_heredoc_filepath(12);
	while (access(temp->file_name, F_OK) == 0)
	{
		free(temp->file_name);
		temp->file_name = generate_random_heredoc_filepath(12);
	}
	temp->fd = open(temp->file_name, O_RDWR | O_CREAT, 0644);
	if (temp->fd == -1)
		system_error("Open system call Error!\n");
	node = data->heredoc_list;
	if (!node)
		data->heredoc_list = temp;
	else
	{
		while (node->next)
			node = node->next;
		node->next = temp;
	}
	return (temp);
}
