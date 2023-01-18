/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_make_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:51:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/19 03:14:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_arrays(t_stacks *stk, char **strarr, int *idx);

static void	ft_count_array(t_stacks *stk, int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		stk->size += ft_count_words(argv[i], ' ');
		i++;
	}
	stk->array = (t_elemt *)malloc(sizeof(t_elemt) * stk->size);
	if (!stk->array)
		ft_error_ps(stk);
}

void	ft_make_array(t_stacks *stk, int argc, char **argv)
{
	char	**temp;
	int		idx;
	int		i;

	ft_count_array(stk, argc, argv);
	idx = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_count_words(argv[i], ' ') > 1)
		{
			temp = ft_split(argv[i], ' ');
			if (!temp)
				ft_error_ps(stk);
			ft_fill_arrays(stk, temp, &idx);
		}
		else if (ft_count_words(argv[i], ' ') == 1)
		{
			(stk->array)[idx] = ft_valid_atoi(stk, argv[i]);
			idx++;
		}
	}
}

static void	ft_fill_arrays(t_stacks *stk, char **strarr, int *idx)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		(stk->array)[(*idx)] = ft_valid_atoi(stk, strarr[i]);
		free(strarr[i]);
		i++;
		(*idx)++;
	}
	free(strarr);
}