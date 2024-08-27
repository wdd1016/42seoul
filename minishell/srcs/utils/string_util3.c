/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:01:59 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 02:33:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
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
