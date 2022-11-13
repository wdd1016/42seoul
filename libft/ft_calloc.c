/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:04:12 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/13 20:11:15 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	main(void)
{
	printf("%p\n", ft_calloc(5000,100));
	return 0;
}
*/
