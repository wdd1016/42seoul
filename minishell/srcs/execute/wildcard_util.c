/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:08:46 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 21:42:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_match_file(char *target_string, char *file_name);
static t_filelist	*create_filenode(t_filelist *head, t_filelist *tail, \
char *file_name, char *dir_prefix);

void	make_file_list(DIR *dir, t_filelist *head, char *target, char *dpath)
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
			tail = create_filenode(head, tail, file->d_name, dpath);
		file = readdir(dir);
	}
	closedir(dir);
}

static int	is_match_file(char *target_string, char *file_name)
{
	if (*target_string != '.' && *file_name == '.')
		return (OFF);
	while (*target_string)
	{
		if (*target_string == '*')
		{
			while (*target_string == '*')
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
char *file_name, char *dir_prefix)
{
	t_filelist	*new_node;

	new_node = (t_filelist *)malloc_s(sizeof(t_filelist));
	if (dir_prefix && dir_prefix[0] != '\0')
		new_node->file_name = ft_strjoin3(dir_prefix, "/", file_name);
	else
		new_node->file_name = ft_strdup(file_name);
	new_node->total_count = 0;
	new_node->next = NULLPOINTER;
	tail->next = new_node;
	head->total_count++;
	return (new_node);
}
