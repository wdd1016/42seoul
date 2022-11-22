/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:41:37 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/17 14:26:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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
	if (copy == NULL)
		return (NULL);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array_strs;
	int			i;

	array_strs = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (array_strs == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array_strs[i].size = ft_strlen(av[i]);
		array_strs[i].str = av[i];
		array_strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	array_strs[i].str = 0;
	return (array_strs);
}
