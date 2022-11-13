/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:33:38 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/13 20:55:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*copy;

	copy = str;
	while (*str)
		str++;
	return (str - copy);
}
/*
#include <stdio.h>
 int	main(void)
 {
	 printf("%d", ft_strlen("sddaf"));
 }
 */