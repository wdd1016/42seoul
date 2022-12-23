/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 22:53:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_idx(const char *str, int ch)
{
	char	temp;
	int		end_idx;

	temp = (char)ch;
	end_idx = 0;
	if (!str)
		return (-1);
	while (str[end_idx])
	{
		if (str[end_idx] == temp)
			return (end_idx);
		end_idx++;
	}
	return (-1);
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

char	*ft_strjoin_free_change(t_buffer *u_gnl, char *s1, char *s2)
{
	char	*str;
	char	*temp;
	char	*temp_s1;
	char	*temp_s2;

	temp_s1 = (char *)s1;
	temp_s2 = (char *)s2;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(temp_s2);
		return (0);
	}
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	free(temp_s1);
	while (*s2)
		*temp++ = *s2++;
	free(temp_s2);
	*temp = '\0';
	u_gnl->buffer = str;
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
