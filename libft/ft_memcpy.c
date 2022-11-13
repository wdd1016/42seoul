/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:05:15 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:10 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	if (dest < src)
	{
		while (i < count)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = count;
		while (i-- > 0)
			temp_dest[i] = temp_src[i];
	}
	return (dest);
}
