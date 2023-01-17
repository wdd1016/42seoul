/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_make_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:51:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/17 22:27:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_arrays(t_stacks *stk, char **strarr, int *idx);
static void	ft_isnumspace(t_stacks *stk, char *str);

static void	ft_count_array(t_stacks *stk, int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_error_ps(stk);
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

	ft_count_array(stk, argc, argv);
	idx = 1;
	while (idx < stk->size)
	{
		if (ft_count_words(argv[argc], ' ') > 1)
		{
			temp = ft_split(argv[argc], ' ');
			if (!temp)
				ft_error_ps(stk);
			ft_fill_arrays(stk, temp, &idx);
		}
		else if (ft_count_words(argv[argc], ' ') == 1)
		{
			(stk->array)[idx] = ft_valid_atoi(stk, argv[argc]);
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

static void	ft_isnumspace(t_stacks *stk, char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != ' ')
			ft_error_ps(stk);
		str++;
	}
}