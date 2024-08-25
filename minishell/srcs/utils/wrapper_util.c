/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:56:25 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 01:13:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*malloc_s(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		system_error("Allocation Error!\n");
	return (ptr);
}

char	*ft_strdup_s(const char *s1)
{
	size_t	len;
	char	*copy;
	char	*temp;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc_s(sizeof(char) * (len + 1));
	temp = copy;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (copy);
}

int	fork_s(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		system_error("Fork Error!\n");
	return (pid);
}
