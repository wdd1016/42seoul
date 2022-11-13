/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:23:16 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:06 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (size > 0)
	{
		while (*(src + i) && i + 1 < size)
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = '\0';
	}
	count = 0;
	while (*(src + count))
		count++;
	return (count);
}
