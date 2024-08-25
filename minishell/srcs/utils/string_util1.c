/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:21:06 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/21 01:48:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && i + 1 < n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			break ;
		i++;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

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

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		len_str;
	size_t		i;
	char		*n_str;

	len_str = ft_strlen(s);
	if (len_str <= start)
		len = 0;
	else
		len_str -= start;
	if (len_str < len)
		len = len_str;
	n_str = (char *)malloc_s(sizeof(char) * (len + 1));
	if (!n_str)
		return (0);
	i = 0;
	while (i < len)
	{
		n_str[i] = s[start + i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
