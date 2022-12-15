/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_anyway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 06:11:52 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// 9223372039002259500
// 9223372039002259458
int main()
{
	int i; //= ft_atoi("21474836401");
	char	*str = "cspdiuxX%";
	i = 0;
	i = printf("%#5xkk\n", 32);
//	printf("%p\n", 0);
	printf("%d", i);

}
