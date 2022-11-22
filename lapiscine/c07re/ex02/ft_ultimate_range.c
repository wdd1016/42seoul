/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:07:57 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/19 11:04:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	i;
	long long	value;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	value = max - min;
	*range = (int *)malloc(sizeof(int) * value);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < value)
	{
		*(*range + i) = min + i;
		i++;
	}
	return (max - min);
}
