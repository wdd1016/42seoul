/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:09:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/09 08:47:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valid_count_last(int *str_out, int order, int view, int direction)
{
	int	i;
	int	value;
	int	count;

	if (direction == 1)
		i = 0;
	else
		i = 3;
	value = 0;
	count = 0;
	while (i >= 0 && i <= 3)
	{
		if (*(str_out + order + 4 * i) > value)
		{
			value = *(str_out + order + 4 * i);
			count++;
		}
		i = i + direction;
	}
	if (count == view)
		return (1);
	else
		return (0);
}

int	ft_valid_line_last(int *str_in, int *str_out)
{
	int	i;
	int	up;
	int	down;

	i = 0;
	while (i < 4)
	{
		up = *(str_in + i);
		down = *(str_in + 4 + i);
		if (ft_valid_count_last(str_out, i, up, 1) == 0)
			return (0);
		else if (ft_valid_count_last(str_out, i, down, -1) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_count_four(int *str_out, int order, int view, int direction)
{
	int	i;
	int	value;
	int	count;

	if (direction == 1)
		i = 3;
	else
		i = 0;
	value = 0;
	count = 0;
	while (i >= 0 && i <= 3)
	{
		if (*(str_out + order - i) > value)
		{
			value = *(str_out + order - i);
			count++;
		}
		i = i - direction;
	}
	if (count == view)
		return (1);
	else
		return (0);
}

int	ft_valid_line_four(int *str_in, int *str_out, int order)
{
	int	left;
	int	right;

	left = *(str_in + 8 + order / 4);
	right = *(str_in + 12 + order / 4);
	if (ft_valid_count_four(str_out, order, left, 1) == 0)
		return (0);
	else if (ft_valid_count_four(str_out, order, right, -1) == 0)
		return (0);
	else
		return (1);
}
