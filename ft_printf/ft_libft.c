/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:22:52 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp;

	temp = (char)c;
	while (*s)
	{
		if (*s == temp)
			return ((char *)s);
		s++;
	}
	if (*s == temp)
		return ((char *)s);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	const char	*copy;

	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	uch_c;
	size_t			i;

	i = 0;
	uch_c = (unsigned char)c;
	temp_b = (unsigned char *)b;
	while (i < len)
	{
		temp_b[i] = uch_c;
		i++;
	}
	return (b);
}
