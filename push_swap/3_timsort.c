/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_timsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:44:28 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/18 04:34:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const int	RUN = 32;

typedef struct s_index
{
	int	left;
	int	right;
	int	mid;
	int	len1;
	int	len2;
} t_index;

static int	ft_merge(t_elemt *arr, t_index id);
static void	ft_merge2(t_elemt *arr, t_elemt *lt, t_elemt *rt, t_index id);
static void	ft_insertsort(t_elemt *arr, int left, int right);

int	ft_timsort(t_elemt *arr, int n)
{
	int		temp;
	t_index	index;

	temp = 0;
	while (temp < n)
	{
		ft_insertsort(arr, temp, MIN(temp + RUN - 1, n - 1));
		temp += RUN;
	}
	temp = RUN;
	while (temp < n)
	{
		index.left = 0;
		while (index.left < n)
		{
			index.mid = index.left + temp - 1;
			index.right = MIN(index.left + 2 * temp - 1, n - 1);
			if (index.mid < index.right)
				if (ft_merge(arr, index) == 0)
					return (0);
			index.left += 2 * temp;
		}
		temp *= 2;
	}
	return (1);
}
// temp = index or size
// array[0...n-1] (similar to merge sort)
// Sort individual subarrays of size RUN
// pick starting point of left sub array. We are going to merge
// arr[left..left+size-1] and arr[left+size, left+2*size-1]
// After every merge, we increase left by 2*size
// find ending point of left sub array
// mid+1 is starting point of right sub array
// merge sub array arr[left.....mid] & arr[mid+1....right]

static int	ft_merge(t_elemt *arr, t_index id)
{
	t_elemt	*arrleft;
	t_elemt	*arrright;
	int	i;

	id.len1 = id.mid - id.left + 1;
	id.len2 = id.right - id.mid;
	arrleft = (t_elemt *)malloc(sizeof(t_elemt) * (id.len1));
	if (!arrleft)
		return (0);
	arrright = (t_elemt *)malloc(sizeof(t_elemt) * (id.len2));
	if (!arrright)
	{
		free(arrleft);
		return (0);
	}
	i = -1;
	while (++i < id.len1)
		arrleft[i] = arr[id.left + i];
	i = -1;
	while (++i < id.len2)
		arrright[i] = arr[id.mid + i + 1];
	ft_merge2(arr, arrleft, arrright, id);
	return (1);
}

static void	ft_merge2(t_elemt *arr, t_elemt *lt, t_elemt *rt, t_index id)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = id.left;
	while (i < id.len1 && j < id.len2)
	{
		if (lt[i] <= rt[j])
			arr[k] = lt[i++];
		else
			arr[k] = rt[j++];
		k++;
	}
	while (i < id.len1)
		arr[k++] = lt[i++];
	while (j < id.len2)
		arr[k++] = rt[j++];
	free(lt);
	free(rt);
}

static void	ft_insertsort(t_elemt *arr, int left, int right)
{
	t_elemt	key;
	int		i;
	int		j;

	i = left + 1;
	while (i <= right)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}
