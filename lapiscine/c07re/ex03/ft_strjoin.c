/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:25:13 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/17 13:45:02 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strs_measure(int size, char **strs, char *sep)
{
	int	length_strs;
	int	sep_len;
	int	i;
	int	j;

	length_strs = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (*(strs[i] + j))
		{
			length_strs++;
			j++;
		}
		i++;
	}
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	length_strs += (size - 1) * sep_len;
	return (length_strs);
}

void	ft_string_complete(int size, char **strs, char *sep, char *merge)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (*(strs[i] + j))
		{
			*merge = *(strs[i] + j);
			merge++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			*merge = sep[j];
			merge++;
			j++;
		}
		i++;
	}
	*merge = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_merge;
	int		str_lens;

	if (size == 0)
	{
		str_merge = (char *)malloc(sizeof(char));
		if (str_merge == 0)
			return (0);
		else
		{
			*str_merge = '\0';
			return (str_merge);
		}
	}
	str_lens = ft_strs_measure(size, strs, sep);
	str_merge = (char *)malloc(sizeof(char) * (str_lens + 1));
	if (str_merge == 0)
		return (0);
	ft_string_complete(size, strs, sep, str_merge);
	return (str_merge);
}
