/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:55:24 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 00:59:43 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_pwd(t_envnode *head)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		cwd = ft_strdup(get_env_node(head, "PWD")->value);
	write(STDOUT_FILENO, cwd, ft_strlen(cwd));
	write(STDOUT_FILENO, "\n", 1);
	free(cwd);
	g_exit_status = 0;
}
