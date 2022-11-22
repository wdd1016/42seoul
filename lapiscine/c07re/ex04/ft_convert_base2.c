/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:52:03 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/14 10:25:38 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == ' ')
		return (1);
	else if (*str == '\f' || *str == '\r' || *str == '\v')
		return (1);
	else
		return (0);
}

int	base_num_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (is_space(base + i) == 1)
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ch_num_base_index(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	sum_atoi_base(char *str, char *base, int base_num, int minus)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	if (minus < 0)
	{
		while (ch_num_base_index(str[i], base) >= 0)
		{
			sum *= base_num;
			sum -= ch_num_base_index(str[i], base);
			i++;
		}
	}
	else
	{
		while (ch_num_base_index(str[i], base) >= 0)
		{
			sum *= base_num;
			sum += ch_num_base_index(str[i], base);
			i++;
		}
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_number;
	int	minus;
	int	atoi;

	base_number = base_num_valid(base);
	minus = 1;
	while (is_space(str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	atoi = sum_atoi_base(str, base, base_number, minus);
	return (atoi);
}
