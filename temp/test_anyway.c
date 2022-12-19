/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_anyway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/19 04:43:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
 #include <stdlib.h>
 #include <limits.h>
 #define BUFFER_SIZE 5

// 9223372039002259500
// 9223372039002259458
int main()
{
	int i; //= ft_atoi("21474836401");
//	char	*str = "cspdiuxX%";
	i = EOF;
	i = printf("%d\n", BUFFER_SIZE);
//	printf("%p\n", 0);
	printf("%d", i);

}
