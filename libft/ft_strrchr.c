/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:41:12 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	temp;
	size_t	str_len;

	temp = (char)c;
	str_len = ft_strlen(str);
	while (str_len > 0)
	{
		if (str[str_len] == temp)
			return (str + str_len);
		str_len--;
	}
	if (*str == temp)
		return (str);
	else
		return (0);
}
