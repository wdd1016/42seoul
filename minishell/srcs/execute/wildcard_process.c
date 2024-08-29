/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 04:49:43 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 04:57:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_filelist	*find_wildcard_files(char *target_string);
static char			**expand_cmd(char **cmd, int *index, t_filelist *filelist);

void	wildcard_process(t_treenode *node)
{
	t_filelist	*filelist;
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (node->cmd[++i])
	{
		if (ft_strchr(node->cmd[i], '*') == NULLPOINTER)
			continue ;
		filelist = find_wildcard_files(node->cmd[i]);
		if (filelist)
			node->cmd = expand_cmd(node->cmd, &i, filelist);
		free_file_list(filelist);
	}		
}

static t_filelist	*find_wildcard_files(char *target_string)
{
	DIR				*dir;
	t_filelist		head;
	char			*directory;

	directory = get_directory(target_string);
	if (!directory)
		dir = opendir(".");
	else
		dir = opendir(directory);
	if (!dir)
	{
		free(directory);
		return (NULLPOINTER);
	}
	head.total_count = 0;
	head.next = NULLPOINTER;
	make_file_list(dir, &head, target_string, directory);
	if (head.next)
		head.next->total_count = head.total_count;
	free(directory);
	return (head.next);
}

static char	**expand_cmd(char **cmd, int *index, t_filelist *filelist)
{
	char	**new_cmd;
	int		before_index;
	int		i;

	i = 0;
	while (cmd[i])
		i++;
	new_cmd = (char **)malloc_s(sizeof(char *) * (i + filelist->total_count));
	before_index = *index;
	i = -1;
	while (++i < before_index)
		new_cmd[i] = cmd[i];
	while (filelist)
	{
		new_cmd[++i] = filelist->file_name;
		filelist = filelist->next;
	}
	*index = i;
	while (cmd[++before_index])
		new_cmd[++i] = cmd[before_index];
	new_cmd[++i] = NULLPOINTER;
	free(cmd);
	return (new_cmd);
}
