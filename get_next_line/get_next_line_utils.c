/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:12:00 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/24 13:40:30 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strchrindex(char *s, int c)
{
	char	temp;
	int		i;

	temp = (char)c;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == temp)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	char	*copy;

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}
