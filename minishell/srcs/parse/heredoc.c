/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:57:10 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 00:43:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			heredoc_child(t_data *data, t_herenode *node, char *target);
static t_herenode	*add_heredoc_node(t_data *data);

void	heredoc(t_data *data, size_t start, size_t end)
{
	t_herenode	*node;
	pid_t		pid;

	node = add_heredoc_node(data);
	pid = fork_s();
	if (pid == 0)
		heredoc_child(data, node, ft_substr(data->line, start, end - start));
	else
	{
		signal_parent();
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
		free(data->token.temp->parsed_data);
		data->token.temp->parsed_data = ft_itoa(node->fd);
	}
}

static void	heredoc_child(t_data *data, t_herenode *node, char *target)
{
	char	*ln;
	size_t	i;

	signal_child();
	while (1)
	{
		ln = readline("> ");
		if (!ln || ft_strcmp(ln, target) == 0)
		{
			free(ln);
			exit(0);
		}
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
