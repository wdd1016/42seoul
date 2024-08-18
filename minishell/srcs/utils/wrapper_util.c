/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:56:25 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/18 00:03:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*malloc_s(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
        write(2, "Allocation Error!\n", 18);
        exit(1);
	}
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