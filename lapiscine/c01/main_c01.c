/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyeki <jungyeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:36:03 by jungyeki          #+#    #+#             */
/*   Updated: 2022/10/03 12:10:03 by jungyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ex00/ft_ft.c"
#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"

int main(void)
{
	int	nbr0;
	printf("\n----ex00----\n");
    ft_ft(&nbr0);
	printf("\n%d : 42면 답\n", nbr0);

	int	nbr1;
	int *nbr2 = &nbr1;
	int	**nbr3 = &nbr2;
	int ***nbr4 = &nbr3;
	int ****nbr5 = &nbr4;
	int *****nbr6 = &nbr5;
	int ******nbr7 = &nbr6;
	int *******nbr8 = &nbr7;
	int ********nbr9 = &nbr8;
    printf("\n----ex01----\n");
    ft_ultimate_ft(&nbr9);
    printf("\n%d : 42면 답\n", nbr1);

	int	i = 2;
	int	j = 24;
    printf("\n----ex02----\n");
	printf("\nbefore : %d, %d\n", i, j);
    ft_swap(&i, &j);
    printf("after :  %d, %d\n순서 잘 바뀌었으면 답\n", i, j);

    printf("\n----ex03----\n");
	int div;
	int mod;
    ft_div_mod(10, 3, &div, &mod);
	printf("\ndiv : %d, mod : %d",div ,mod);
    printf("\ndiv : 3, mod : 1 이면 답\n");

    printf("\n----ex04----\n");
	int a = 10;
	int	b = 3;
    ft_ultimate_div_mod(&a, &b);
    printf("\ndiv : %d, mod : %d", a, b);
	printf("\ndiv : 3, mod : 1 이면 답\n");

	printf("\n----ex05----\n\n");
	char *str5 = "We need coffee, especially me";
	ft_putstr(str5);
	printf("\nWe need coffee, especially me 가 보이면 정답\n");

    printf("\n----ex06----\n\n");
	char *str6 = "1234567890";
    printf("%d", ft_strlen(str6));
    printf("\n10 이 나오면 정답\n");

    printf("\n----ex07----\n\n");
    int tab[13] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size = 13;
	printf("Before : ");
	i = 0;
	while (i < 13)
	{
		printf("%d ", tab[i]);
		i++;
	}
	ft_rev_int_tab(tab, size);
	
    printf("\nAfter :  ");
	i = 0;
	while (i < 13)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n역순 맞으면 정답\n\n");

    printf("\n----ex08----\n");
    int	tab1[13] = {10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
	i = 0;
	printf("Before : ");
	while (i < 13)
	{
		printf("%d ", tab1[i]);
		i++;
	}
	printf("\nAfter :  ");
	ft_sort_int_tab(tab1, size);
	i = 0;
	while (i < 13)
    {
		printf("%d ", tab1[i]);
		i++;
    }
	printf("\n정렬 잘 되었으면 정답\n");
    printf("\n고생하셨습니다.\n\n");
    return(0);
}
