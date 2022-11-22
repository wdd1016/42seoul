/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:38:32 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/11 13:31:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == ' ')
		return (1);
	else if (*str == '\f' || *str == '\r' || *str == '\v')
		return (1);
	else
		return (0);
}

int	ft_sum_atoi(char *str)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += *(str + i) - '0';
		i++;
	}
	return (sum);
}

int	ft_atoi(char *str)
{
	int	minus;
	int	atoi;

	minus = 1;
	while (ft_is_space(str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	atoi = minus * ft_sum_atoi(str);
	return (atoi);
}
