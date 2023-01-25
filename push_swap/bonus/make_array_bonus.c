/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:51:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/25 22:04:46 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_fill_arrays(t_stacks *stk, char **argv, int current, int *idx);
static int	ft_valid_atoi(t_stacks *stk, const char *str);

void	ft_make_array(t_stacks *stk, int argc, char **argv)
{
	int		idx_stack;
	int		idx_argc;

	if (argc == 1)
		exit(0);
	idx_argc = 1;
	while (idx_argc < argc)
	{
		stk->size += ft_count_words(argv[idx_argc], ' ');
		idx_argc++;
	}
	stk->array = (int *)malloc(sizeof(int) * stk->size);
	if (!stk->array)
		ft_error_ps(stk);
	idx_stack = 0;
	idx_argc = 0;
	while (++idx_argc < argc)
		ft_fill_arrays(stk, argv, idx_argc, &idx_stack);
}

static void	ft_fill_arrays(t_stacks *stk, char **argv, int current, int *idx)
{
	char	**temp;
	int		i;

	if (ft_count_words(argv[current], ' ') > 1)
	{
		temp = ft_split(argv[current], ' ');
		if (!temp)
			ft_error_ps(stk);
		i = 0;
		while (temp[i])
		{
			(stk->array)[(*idx)] = ft_valid_atoi(stk, temp[i]);
			free(temp[i]);
			i++;
			(*idx)++;
		}
		free(temp);
	}
	else if (ft_count_words(argv[current], ' ') == 1)
	{
		(stk->array)[*idx] = ft_valid_atoi(stk, argv[current]);
		(*idx)++;
	}
}

static int	ft_valid_atoi(t_stacks *stk, const char *str)
{
	int			minus;
	long long	sum;

	minus = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + minus * (*str - '0');
		if (sum < -2147483648 || sum > 2147483647)
			ft_error_ps(stk);
		str++;
	}
	while (*str == ' ')
		str++;
	if (*str != '\0')
		ft_error_ps(stk);
	return ((int)sum);
}
