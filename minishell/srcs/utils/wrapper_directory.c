/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:02:58 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 01:56:45 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
