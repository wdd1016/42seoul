#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char    num1[10005];
	char	num2[10005];
	int	i, j, k, temp;

	for (i=0; i<10004; i++)
	{
		num1[i] = '0';
		num2[i] = '0';
	}
	num1[i] = '\0';
	num2[i] = '\0';
	scanf("%s %s", num1, num2);
	temp = strlen(num1);
	k = 0;
	num1[temp] = '0';
	while (--temp >= 0)
	{
		num1[10003 - k] = num1[temp];
		num1[temp] = '0';
		k++;
	}
	temp = strlen(num2);
	k = 0;
	num2[temp] = '0';
	while (--temp >= 0)
	{
		num2[10003 - k] = num2[temp];
		num2[temp] = '0';
		k++;
	}
	for (j=0; j<10003; j++)
	{
		temp = (num1[j] - '0' + num2[j] - '0') + ((num1[j + 1] - '0' + num2[j + 1] - '0') / 10);
		temp %= 10;
		num1[j] = temp + '0';
	}
	temp = num1[j] - '0' + num2[j] - '0';
	temp %= 10;
	num1[j] = temp + '0';
	for (j=0; num1[j] == '0'; j++);
	printf("%s", num1 + j);
}