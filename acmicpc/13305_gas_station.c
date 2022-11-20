#include <stdio.h>
#include <stdlib.h>

void ft_max_cost(int *price, int *distance, int max, unsigned long long *cost)
{
    int i;
    int temp_price_min;
    unsigned long long dis_sum = 0;
    
    temp_price_min = price[0];
    for (i = 0; i <= max; i++)
    {
        if (price[i] < temp_price_min || i == max)
        {
            *cost += (unsigned long long)temp_price_min * dis_sum;
            temp_price_min = price[i];
            dis_sum = 0;
        }
        dis_sum += distance[i];
    }
}

int main()
{
    int price[4] = {5, 2, 4, 1};
    int distance[3] = {2, 3, 1};
    int i = 4;
    int j;
    int max = 0;
    unsigned long long cost = 0;

//    scanf("%d", &i);
//    fflush(stdin);
//   price = (int *)malloc(sizeof(int) * i);
//    distance = (int *)malloc(sizeof(int) * i);
//    for (j=0; j<i-1; j++)
//   {
//        scanf("%d", &distance[j]);
//    }
 //   fflush(stdin);
//    for (j=0; j<i; j++)
//    {
//        scanf("%d", &price[j]);
//    }
//    distance[i-1] = 0;
    max = i-1;
    ft_max_cost(price, distance, max, &cost);
    printf("%llu", cost);
	return 0;
}