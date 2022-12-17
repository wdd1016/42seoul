#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[6];

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &arr[i]);
		if (i < 2)
			arr[i] = 1 - arr[i];
		else if (i < 5)
			arr[i] = 2 - arr[i];
		else
			arr[i] = 8 - arr[i];
		printf("%d ", arr[i]);
	}
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	int	sum = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		sum += num * num;
	}
	printf("%d", sum % 10);
}