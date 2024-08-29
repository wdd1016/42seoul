/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:18:31 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/29 23:15:10 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_env(t_envnode *head)
{
	g_exit_status = 0;
	while (head)
	{
		if (head->value)
		{
			write(STDOUT_FILENO, head->key, ft_strlen(head->key));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, head->value, ft_strlen(head->value));
			write(STDOUT_FILENO, "\n", 1);
		}
		head = head->next;
	}
}