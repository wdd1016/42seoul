/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:57:10 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 02:09:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			heredoc_child(t_data *data, t_herenode *node, char *target);
static t_herenode	*add_heredoc_node(t_data *data);

void	heredoc(t_data *data, size_t start, size_t end)
{
	t_herenode	*node;
	pid_t		pid;
	char		*line;
	char		*target;

	node = add_heredoc_node(data);
	signal_parent();
	pid = fork_s();
	if (pid == 0)
		heredoc_child(data, node, ft_substr(data->line, start, end - start));
	else
	{
		wait(&pid);
		if (WIFSIGNALED(pid))
			g_exit_status = pid;
		signal_default();
		close(node->fd);
		node->fd = open(node->file_name, O_RDONLY);
		if (node->fd == -1)
			system_error("Open system call Error!\n");
		unlink(node->file_name);
		add_token(data, RE_HERE);
		free(data->token.tail->parsed_data);
		data->token.tail->parsed_data = ft_itoa(node->fd);
	}
}

static void	heredoc_child(t_data *data, t_herenode *node, char *target)
{
	char	*line;
	size_t	i;

	signal_child();
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, target) == 0)
		{
			free(line);
			exit(0);
		}
		i = 0;
		while (line[i])
		{
			if (line[i] == '$' && line[i + 1] != ' ' && line[i + 1] != '\0')
				i = expansion(data->env_list, &line, i + 1, ft_substr(line, 0, i));
			else
				i++;
		}
		write(node->fd, line, ft_strlen(line));
		write(node->fd, "\n", 1);
		free(line);
	}
	free(target);
}

static t_herenode	*add_heredoc_node(t_data *data)
{
	t_herenode	*temp;
	t_herenode	*node;

	temp = (t_herenode *)malloc_s(sizeof(t_herenode));
	temp->next = NULL;
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

