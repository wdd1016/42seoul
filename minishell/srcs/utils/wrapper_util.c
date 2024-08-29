/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:56:25 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 01:43:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*malloc_s(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULLPOINTER)
		system_error("Allocation Error!\n");
	return (ptr);
}

int	fork_s(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		system_error("Fork Error!\n");
	return (pid);
}
