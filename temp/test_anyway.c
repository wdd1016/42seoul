/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_anyway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/22 19:52:02 by juyojeon         ###   ########.fr       */
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
//	i = EOF;
	char	*str = 0;
	char	k;
	k = str[0];
	i = printf("%c\n", k);
//	printf("%p\n", 0);
	printf("%d", i);

}
