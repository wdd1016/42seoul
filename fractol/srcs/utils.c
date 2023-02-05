/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:09:50 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/05 21:31:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}

void	ft_error(t_data *all, int errnum)
{
	if (all->win)
		mlx_clear_window(all->mlx, all->win);
	if (all->img)
		mlx_destroy_image(all->mlx, all->img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->coor)
		free(all->coor);
	free(all->mlx);
	perror(strerror(errnum));
	exit(1);	
}

double	ft_atod(char *str)
{
	int		minus;
	int		integral;
	double	decimal;

	minus = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	integral = 0;
	while (*str >= '0' && *str <= '9')
	{
		integral = (integral * 10) + minus * (*str - '0');
		str++;
	}
	decimal = 0;
	if (*str == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			decimal = (decimal / 10) + minus * (*str - '0');
			str++;
		}		
	}
	return (10.0);
}
