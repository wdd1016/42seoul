/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:37:26 by myko              #+#    #+#             */
/*   Updated: 2022/12/03 23:32:10 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	cnt;
	int	ft_cnt;

	ft_cnt = 0;
	cnt = 0;
	ft_printf("----test----\n");
	ft_cnt = ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("\n");
	cnt = printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
