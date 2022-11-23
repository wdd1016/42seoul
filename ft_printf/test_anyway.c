/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_anyway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/24 00:21:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static int	ft_write_str_count(const char *str, int *count)
{
	if (write(1, *str, 1) < 0)
		return (-1);
	(*count)++;
	return (1);
}

int main()
{
	int	i;
	char str[3] = {'a', 'g'};

	ft_write_str_count(str++, &i);
//	i = printf("%2147483647d", 30);
	printf("%d", i);
}
