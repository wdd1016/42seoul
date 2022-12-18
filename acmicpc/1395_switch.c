#include <stdio.h>
#include <stdlib.h>

int main()
{
	int s_count, w_count;
	int inf, start, end;

	scanf("%d %d", &s_count, &w_count);

	int tree[4 * s_count]; // make tree, no arr <- all 0

	for (int i = 0; i < 4 * s_count; i++)
		tree[i] = 0;
	for (int j = 0; j < w_count; j++)
	{	
		scanf("%d %d %d", inf, start, end);
		if (inf == 0)
			update_rev(start, end);
		else
			printf("%d", sum_tree());
	}
}

int	update_rev(int start, int end, int index, int left, int right)
// start : 함수의 시작 idx, end : 함수의 끝 idx, left : 기준 idx
{

}

int sum_tree()
{

}
