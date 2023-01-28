/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:37:26 by myko              #+#    #+#             */
/*   Updated: 2023/01/29 02:32:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		cnt;
	int		ft_cnt;

	ft_cnt = 0;
	cnt = 0;
	ft_printf("----test----\n");
	ft_cnt = ft_printf("%d %s %x %X %p", 512, "abc", 12, 33, &cnt);
	printf("\n");
	cnt = printf("%d %s %x %X %p", 512, "abc", 12, 33, &cnt);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
