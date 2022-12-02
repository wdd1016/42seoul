/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:37:26 by myko              #+#    #+#             */
/*   Updated: 2022/12/02 23:43:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	cnt;
	int	ft_cnt;

	ft_cnt = 0;
	cnt = 0;
	ft_printf("----test----\n");
	ft_cnt = ft_printf("%d", 53245);
	ft_cnt = ft_printf("%d%s %c%s %X %i", 42, "Seoul", 'K', "delphinus", -2147483647, 0x2a);
	printf("\n");
	cnt = printf("%d%s %c%s %X %i", 42, "Seoul", 'K', "delphinus", -2147483647, 0x2a);
	printf("\n");
	printf("ft_printf cnt: %d\n", ft_cnt);
	printf("printf cnt: %d\n", cnt);
}
