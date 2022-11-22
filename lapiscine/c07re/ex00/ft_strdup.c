/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:16:43 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/14 20:55:50 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		str_len;
	int		i;
	char	*copy;

	str_len = 0;
	i = 0;
	while (src[str_len])
		str_len++;
	copy = (char *)malloc(sizeof(char) * (str_len + 1));
	if (copy == 0)
		return (0);
	else
	{
		while (src[i])
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
}
