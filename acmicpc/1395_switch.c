#include <stdio.h>
#include <stdlib.h>

static int	update_rev(int start, int end, int index, int left, \
int right, int *tree, int *lazy);
static int sum_tree(int start, int end, int index, int left, \
int right, int *tree, int *lazy);
static void turnover_lazy(int start, int mid, int end, \
int index, int *tree, int *lazy);

int main()
{
	int s_count, w_count; // s_count : switch 개수, w_count : 일의 수
	int inf, left, right, k; // inf : 0 or 1

	scanf("%d %d", &s_count, &w_count);

	int tree[4 * s_count]; // make tree, arr <- all 0
	int lazy[4 * s_count];
//	int arr[s_count] = { 값들 };

//	init(0, s_count - 1, 1, arr, tree); 
	for (int i = 0; i < 4 * s_count; i++)
	{
		tree[i] = 0;
		lazy[i] = 0;
	}
	for (int j = 0; j < w_count; j++)
	{	
		scanf("%d %d %d", &inf, &left, &right);
		if (inf == 0)
			update_rev(1, s_count, 1, left, right, tree, lazy);
		else
			{
				k = sum_tree(1, s_count, 1, left, right, tree, lazy);
				printf("%d\n", k);
			}
	
	}
	return 0;
}

static int	update_rev(int start, int end, int index, int left, int right, int *tree, \
int *lazy) // start, end : 함수내 시작과 끝 arr[]idx, left, right : 판별 기준 arr[]idx, index : 현재 tree[]idx
{
	int mid = (start + end) / 2;
	if (lazy[index] == 1)
	{
		turnover_lazy(start, mid, end, index, tree, lazy);
		//lazy를 아래 노드에 전달
	}
	if (right < start || end < left) // 범위에 벗어나는 경우
		return tree[index];
	else if (left <= start && end <= right) // 함수범위가 기준범위내에 포함되는 경우
	{
		if (start == end) // 끝에 도달하는 경우
		{
			tree[index] = !tree[index]; // 반전
			return tree[index];
		}
		else
		{
			lazy[index] = !lazy[index]; // lazy는 반전(0 <-> 1)만 기록하므로 2번적용시 원래상태 저장
			tree[index] = (end - start + 1) - tree[index]; // 전체개수에 대한 반전
			return tree[index];
		}
	}
	else
	{
		tree[index] = update_rev(start, mid, index * 2, left, right, tree, lazy) + \
		update_rev(mid + 1, end, index * 2 + 1, left, right, tree, lazy);
		return tree[index];
	}
}

static int sum_tree(int start, int end, int index, int left, \
int right, int *tree, int *lazy)
{
	int mid = (start + end) / 2;
	if (lazy[index] == 1)
	{
		turnover_lazy(start, mid, end, index, tree, lazy);
		//lazy를 아래 노드에 전달		
	}
	if (right < start || end < left) // 함수범위가 기준범위에서 벗어나는 경우
		return 0;
	else if (left <= start && end <= right) // 함수범위가 기준범위내에 포함되는 경우
		return tree[index];
	else
	{
		return (sum_tree(start, mid, index * 2, left, right, tree, lazy) + \
		sum_tree(mid + 1, end, index * 2 + 1, left, right, tree, lazy));
	}
}

static void turnover_lazy(int start, int mid, int end, int index, int *tree, int *lazy)
{
	lazy[index] = 0; // lazy를 물려주므로 이제 0의 값을 가짐

	if (start != mid)
		lazy[index * 2] = 1;
	if (mid + 1 != end)
		lazy[index * 2 + 1] = 1; // lazy 물려줌

	tree[index * 2] = (mid - start + 1) - tree[index * 2];
	tree[index * 2 + 1] = (end - mid) - tree[index * 2 + 1]; // lazy 받았으니 적용 (line 48~49)
}

/* 아래 내용은 lazy_Propagation이 구현되지 않아, 타임에러가 발생
static int	update_rev(int start, int end, int index, int left, int right, int *tree)
// start, end : 함수내 시작과 끝 arr[]idx, left, right : 판별 기준 arr[]idx, index : 현재 tree[]idx
{
	if (right < start || end < left) // 범위에 벗어나는 경우
		return tree[index];
	else if (start == end) // 끝에 도달하는 경우
	{
		tree[index] = !tree[index];
		return tree[index];
	}
	else
	{
		int mid = (start + end) / 2;
		tree[index] = update_rev(start, mid, index * 2, left, right, tree) + \
		update_rev(mid + 1, end, index * 2 + 1, left, right, tree);
		return tree[index];
	}
}

static int sum_tree(int start, int end, int index, int left, int right, int *tree)
{
	if (right < start || end < left) // 함수범위가 기준범위에서 벗어나는 경우
		return 0;
	else if (left <= start && end <= right) // 함수범위가 기준범위내에 포함되는 경우
		return tree[index];
	else
	{
		int mid = (start + end) / 2;
		tree[index] = sum_tree(start, mid, index * 2, left, right, tree) + \
		sum_tree(mid + 1, end, index * 2 + 1, left, right, tree);
		return tree[index];
	}
}
*/

/*
int init(int start, int end, int index, int *arr, int *tree)
{
	if (start == end)
	{
		tree[index] = arr[start];
		return tree[index];
	}
	else
	{
		int mid = (start + end) / 2;
		tree[index] = init(start, mid, index * 2, arr, tree) + \
		init(mid + 1, end, index * 2 + 1, arr, tree);
		return tree[index];
	}
}
*/
