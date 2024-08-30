/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:57:02 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 23:04:49 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_option(char *command);

void	execute_echo(t_treenode *node)
{
	size_t	idx;

	set_exit_status(0);
	if ((node->cmd)[1] == NULLPOINTER)
		write(STDOUT_FILENO, "\n", 1);
	else
	{
		if (is_option((node->cmd)[1]) == OFF)
			idx = 1;
		else
			idx = 2;
		while ((node->cmd)[idx])
		{
			write(STDOUT_FILENO, (node->cmd)[idx], ft_strlen((node->cmd)[idx]));
			if ((node->cmd)[idx + 1])
				write(STDOUT_FILENO, " ", 1);
			idx++;
		}
		if (is_option((node->cmd)[1]) == OFF)
			write(STDOUT_FILENO, "\n", 1);
	}
}

static int	is_option(char *command)
{
	int	i;

	if (command[0] == '-' && command[1] == 'n')
	{
		i = 2;
		while (command[i] == 'n')
			i++;
		if (command[i] == '\0')
			return (ON);
	}
	return (OFF);
}
