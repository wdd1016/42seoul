/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:53:51 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*temp_ptr;
	unsigned char	uch_value;
	size_t			i;

	i = 0;
	uch_value = (unsigned char)value;
	temp_ptr = (unsigned char *)ptr;
	while (i < len)
	{
		temp_ptr[i] = uch_value;
		i++;
	}
	return (ptr);
}
/*
int value -> converted to an unsigned char
*/