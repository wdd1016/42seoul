/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:01:59 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 19:04:55 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*temp;

	str = (char *)malloc_s(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	temp = str;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	*temp = '\0';
	return (str);
}

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*str;
	char	*temp;

	str = (char *)malloc_s(sizeof(char) * \
						(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	temp = str;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	if (s3)
		while (*s3)
			*temp++ = *s3++;
	*temp = '\0';
	return (str);
}

int	ft_atoi(const char *str)
{
	int			minus;
	int			sum;

	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + minus * (*str - '0');
		str++;
	}
	return (sum);
}
