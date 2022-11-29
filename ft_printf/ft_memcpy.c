/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:05:15 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/28 19:34:35 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;
	size_t				i;

	i = 0;
	if (!dst && !src)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	if (dst < src)
	{
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = n;
		while (i-- > 0)
			temp_dst[i] = temp_src[i];
	}
	return (dst);
}
