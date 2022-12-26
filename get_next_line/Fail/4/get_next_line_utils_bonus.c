/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 17:10:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_process_len(t_list *uselist, char *newbuffer, ssize_t len)
{
	int		i;

	i = 0;
	while (newbuffer[i])
	{
		if (newbuffer[i] == '\n')
		{
			i++;
			uselist->len_return += i;
			uselist->len_remain += len - i;
			uselist->state = END;
			return ;
		}
		i++;
	}
	uselist->len_return += i;
	return ;
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

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	count = 0;
	while (src[count])
		count++;
	return (count);
}

char	*ft_gnl_strjoin(t_list *uselist, char *s2, ssize_t len)
{
	char	*str;
	char	*s1;
	char	*temp;

	str = (char *)malloc(sizeof(char) * (uselist->len_return + len + 1));
	if (!str)
		return (0);
	temp = str;
	s1 = uselist->buffer;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	*temp = '\0';
	return (str);
}
