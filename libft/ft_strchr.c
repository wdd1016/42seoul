/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:22:52 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:41:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	temp;

	temp = (char)c;
	while (*str)
	{
		if (*str == temp)
			return (str);
		str++;
	}
	if (*str == temp)
		return (str);
	else
		return (0);
}
