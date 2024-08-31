/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 04:49:43 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 05:15:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_wildcard_files(char *wildcard_string, t_filelist *head);
static char	**expand_cmd(char **cmd, int *index, t_filelist *filelist, \
int total_count);

void	wildcard_process(t_treenode *node)
{
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
		find_wildcard_files(node->cmd[i], &head);
		if (head.next)
			node->cmd = expand_cmd(node->cmd, &i, head.next, head.total_count);
		free_file_list(head.next);
		head.total_count = 0;
		head.next = NULLPOINTER;
	}
}

static void	find_wildcard_files(char *wildcard_string, t_filelist *head)
{
	DIR		*dir;

	dir = opendir(".");
	if (!dir)
		return ;
	make_file_list(dir, head, wildcard_string);
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
