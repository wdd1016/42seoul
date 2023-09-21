/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:39:30 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/24 19:06:51 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_format(const char *path, const char *format)
{
	size_t	p_len;
	size_t	f_len;
	size_t	p_idx;
	size_t	f_idx;

	p_len = ft_strlen(path);
	f_len = ft_strlen(format);
	if (p_len <= f_len)
		return (FAILURE);
	p_idx = p_len - f_len;
	f_idx = 0;
	while (p_idx < p_len)
	{
		if (path[p_idx] != format[f_idx])
			return (FAILURE);
		p_idx++;
		f_idx++;
	}
	return (SUCCESS);
}

static int	return_color(const char *str, int return_value)
{
	if (*str != '\0')
		return (-1);
	else
		return (return_value);
}

int	color_to_i(const char *str)
{
	int	temp;
	int	return_value;
	int	i;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	i = 0;
	return_value = 0;
	while (++i <= 3)
	{
		temp = 0;
		while (*str >= '0' && *str <= '9' && temp < 255)
		{
			temp = (temp * 10) + (*str - '0');
			str++;
		}
		if (temp > 255 || (*str != ',' && i != 3) || (*str != '\0' && i == 3))
			return (-1);
		return_value = (return_value << 8) + temp;
		if (*str == ',')
			str++;
		while (*str == ' ')
			str++;
	}
	return (return_color(str, return_value));
}
