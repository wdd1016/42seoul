/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:18:54 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/16 00:44:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_val_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_len_set(char *str, char const *set)
{
	char	*temp;
	size_t	str_len;
	size_t	len;

	str_len = ft_strlen(str);
	temp = str + str_len - 1;
	len = 0;
	while (ft_val_set(*str, set))
	{
		str++;
		len++;
	}
	if (str_len == len)
		return (len);
	while (ft_val_set(*temp, set))
	{
		temp--;
		len++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	char	*str;
	size_t	len;

	temp = (char *)s1;
	len = ft_strlen(temp) - ft_len_set(temp, set);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (ft_val_set(*temp, set))
		temp++;
	while (len > 0)
	{
		*str = *temp;
		str++;
		temp++;
	}
	*temp = '\0';
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s",ft_strtrim("abcde", "a"));
	return 0;
}
*/