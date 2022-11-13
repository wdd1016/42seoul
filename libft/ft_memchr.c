/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:23:34 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:56:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		temp;
	unsigned char	*ptr_temp;
	size_t				i;

	temp = (unsigned char)c;
	ptr_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_temp[i] == temp)
			return (ptr_temp + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
void	*strstrstr(void)
{
	char *ptrr;
	char a = 'c';
	ptrr = &a;
	return (ptrr);
}
int	main(void)
{
	printf("%0xd\n", *(int *)strstrstr());
	return 0;
}
*/
