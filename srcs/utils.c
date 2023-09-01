/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:39:30 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 17:14:22 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_is_cubformat(const char *path, const char *format)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(path) - 1;
	j = ft_strlen(format) - 1;
	while (i > 0)
	{
		k = 0;
		while (path[i - k] == format[j - k])
		{
			k++;
			if (k > j)
				return (SUCCESS);
			else if (k > i)
				return (FAILURE);
		}
		i--;
	}
	return (FAILURE);
}
