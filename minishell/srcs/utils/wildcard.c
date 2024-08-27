/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:08:46 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 02:06:51 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			make_file_list(DIR *dir, t_filelist *head, \
char *target, char *directory);
static char			*get_directory(char *target_string);
static int			is_match_file(char *target_string, char *file_name);
static t_filelist	*create_filenode(t_filelist *head, t_filelist *tail, \
char *directory, char *file_name);

t_filelist	*find_wildcard_files(char *target_string)
{
	DIR				*dir;
	t_filelist		head;
	char			*directory;

	directory = get_path(target_string);
	if (!directory)
		dir = opendir(".");
	else
		dir = opendir(directory);
	if (!dir)
	{
		free(directory);
		return (NULL);
	}
	head.total_count = 0;
	head.next = NULL;
	make_file_list(dir, &head, target_string, directory);

	if (head.next)
		head.next->total_count = head.total_count;
	free(directory);
	return (head.next);
}

static void	make_file_list(DIR *dir, t_filelist *head, \
char *target, char *directory)
{
	struct dirent	*file;
	t_filelist 	*tail;

	readdir_s(dir);
	readdir_s(dir);
	file = readdir(dir);
	tail = head;
	while (file)
	{
		if (is_match_file(target + ft_strlen(directory), file->d_name) == ON)
			tail = create_filenode(&head, tail, directory, file->d_name);
		file = readdir(dir);
	}
	closedir_s(dir);
}

static char	*get_directory(char *target_string)
{
	char	*directory;
	int		i;

	directory = NULL;
	i = ft_strlen(target_string);
	while (i >= 0 && target_string[i] != '/')
		i--;
	if (i == -1)
		return (directory);
	directory = ft_substr(target_string, 0, i + 1);
	return (directory);
}

static int	is_match_file(char *target_string, char *file_name)
{
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
char *directory, char *file_name)
{
	t_filelist	*new_node;

	new_node = (t_filelist *)malloc_s(sizeof(t_filelist));
	if (directory)
		new_node->file_name = ft_strjoin(directory, file_name);
	else
		new_node->file_name = ft_strdup(file_name);
	new_node->total_count = 0;
	new_node->next = NULL;
	tail->next = new_node;
	head->total_count++;
	return (new_node);
}
