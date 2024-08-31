/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:08:46 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 05:05:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_match_file(char *target_string, char *file_name);
static t_filelist	*create_filenode(t_filelist *head, t_filelist *tail, \
char *file_name);

void	make_file_list(DIR *dir, t_filelist *head, char *target)
{
	struct dirent	*file;
	t_filelist		*tail;

	tail = head;
	while (tail->next)
		tail = tail->next;
	file = readdir(dir);
	while (file)
	{
		if (is_match_file(target, file->d_name) == ON)
			tail = create_filenode(head, tail, file->d_name);
		file = readdir(dir);
	}
	closedir_s(dir);
}

static int	is_match_file(char *target_string, char *file_name)
{
	if (*target_string != '.' && *file_name == '.')
		return (OFF);
	while (*target_string)
	{
		if (*target_string == '*')
		{
			target_string++;
			while (*file_name && *target_string != *file_name)
				file_name++;
		}
		else
		{
			if (*target_string != *file_name)
				return (OFF);
			target_string++;
			file_name++;
		}
	}
	if (*target_string == '\0' && *file_name == '\0')
		return (ON);
	else
		return (OFF);
}

static t_filelist	*create_filenode(t_filelist *head, t_filelist *tail, \
char *file_name)
{
	t_filelist	*new_node;

	new_node = (t_filelist *)malloc_s(sizeof(t_filelist));
	new_node->file_name = ft_strdup(file_name);
	new_node->total_count = 0;
	new_node->next = NULLPOINTER;
	tail->next = new_node;
	head->total_count++;
	return (new_node);
}
