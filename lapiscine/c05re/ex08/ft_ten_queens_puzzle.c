/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:08:38 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/12 11:37:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_int(int *array, int index_max)
{
	char	ch;
	int		i;

	i = 0;
	while (i <= index_max)
	{
		ch = array[i] + '0';
		write(1, &ch, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_valid_place(int *queen, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (queen[i] == queen[index])
			return (0);
		if (queen[i] - (index - i) == queen[index])
			return (0);
		if (queen[i] + (index - i) == queen[index])
			return (0);
		i++;
	}
	return (1);
}

void	ft_queens_write(int *queen, int *count, int index)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		queen[index] = i;
		if (ft_is_valid_place(queen, index) == 1)
		{
			if (index == 9)
			{
				ft_write_int(queen, index);
				(*count)++;
			}
			else
				ft_queens_write(queen, count, index + 1);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queen[10];
	int	*count;
	int	cnt;

	cnt = 0;
	count = &cnt;
	ft_queens_write(queen, count, 0);
	return (*count);
}
