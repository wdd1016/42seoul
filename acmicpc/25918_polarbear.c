#include <stdlib.h>
#include <stdio.h>

int main()
{
	int		i;
	int		j;
	int		k;
	char	*str;
	char	*temp = 0;
	int left = 0;
	int right = 0;
	int count = 0;

	scanf("%d", &i);
	if (i % 2 > 0)
	{
		printf("%d", -1);
		return 0;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	for (j=0; j<i; j++)
	{
		scanf(" %c", &str[j]);
		if (str[j] == '(')
			left++;
		else
			right++;
	}
	if (left != right)
	{
		printf("%d", -1);
		return 0;		
	}
	str[i] = 0;
	temp = str;
	j = 0;
	k = 0;
	while (1)
	{
		if (str[j] == 0)
		{
			if (j == 0)
				break ;
			else
			{
				temp[k] = '\0';
				j = 0;
				k = 0;
				count++;
			}
		}
		else if (str[j + 1] != 0 && str[j] != str[j + 1])
		{
			j += 2;
		}
		else
		{
			temp[k] = str[j];
			k++;
			j++;
		}
	}
	printf("%d", count);
	return 0;
}