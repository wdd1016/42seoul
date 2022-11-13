/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:53:16 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 21:05:51 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && i + 1 < n)
	{
		if (*s1 != *s2)
			break ;
		i++;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_strncmp("1999assf", "4ss", 5));
	return 0;
}
*/