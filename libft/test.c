/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:13:59 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:24:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char    *str1 = 0;
    char    *str2 = 0;


//   *(str1 + 10) = 'k';

//    char    str3[20];
//    char    *ptr1 = str1;
//    char    *ptr2 = str1;
//    memmove(ptr2, ptr1, 999);
//   printf("%s\n", str1);
//	memmove(str2, str1, 122);
//	memcpy(str3, "copy successful", strlen("copy successful") + 1);
//	printf("str2: %s\n", str2);
//    printf("%d", strncmp(str1, str2, 3));
//    printf("%d", toupper(-50));
//  strchr(str1, 0);
    printf("%d\n", memcmp(str1, str2, 5));
/*
str1: %s\n str3: %s\n
    int i;

    for (i = 0; i < 300; i++)
    {
        printf("%c, %d, %d\n", i, i, isprint(i));
    }
*/
    return 0;
}
