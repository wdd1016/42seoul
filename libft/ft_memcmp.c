/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:54:42 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 21:07:06 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;
	size_t				i;

	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	i = 0;
	while (i + 1 < n)
	{
		if (temp_s1[i] != temp_s2[i])
			break ;
		i++;
	}
	return (temp_s1[i] - temp_s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_memcmp("p999assf", "4ss", 5));
	return 0;
}
*/
