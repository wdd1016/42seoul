/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:32:01 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/09 08:47:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	ft_valid_line_last(int *str_in, int *str_out);
extern int	ft_valid_line_four(int *str_in, int *str_out, int order);

int	ft_test_four(int *str_in, int *str_out, int order)
{
	int	sum;
	int	i;
	int	count;

	count = order % 4;
	while (count > 0)
	{
		if (*(str_out + order) == *(str_out + order - count))
			return (0);
		count--;
	}
	i = -1;
	sum = 0;
	while (++i < 4)
		sum += *(str_out + order - i);
	if (sum != 10)
		return (0);
	return (ft_valid_line_four(str_in, str_out, order));
}

int	ft_test_last(int *str_in, int *str_out)
{
	int	sum;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		sum = 0;
		j = 0;
		while (j < 4)
		{
			sum += *(str_out + i + 4 * j);
			j++;
		}
		if (sum != 10)
			return (0);
		i++;
	}
	return (ft_valid_line_last(str_in, str_out));
}
