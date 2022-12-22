/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/23 00:15:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	arr_size;
	char	*temp;
	void	*ptr;

	arr_size = size * count;
	ptr = malloc(arr_size);
	if (!ptr)
		return (0);
	i = 0;
	temp = (char *)ptr;
	while (i < arr_size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}

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

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;
	char	*temp_s1;
	char	*temp_s2;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	temp = str;
	temp_s1 = (char *)s1;
	temp_s2 = (char *)s2;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (str);
}
