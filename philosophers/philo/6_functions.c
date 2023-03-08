/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:39:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/08 18:47:56 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long	sum;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		if (sum > 2147483647)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (sum);
}

size_t	ft_strlen(const char *s)
{
	const char	*copy;

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

int	ft_error(t_philo *info, const char *str)
{
	write(2, str, strlen(str));
	if (info && info->inter && info->inter->forkmutex)
		free(info->inter->forkmutex);
	if (info && info->inter)
		free(info->inter);
	if (info && info->threads)
		free(info->threads);
	if (info)
		free(info);
	return (-1);
}

int	ft_error_thread(int idx, t_philo *info, const char *str)
{
	int		i;
	void	*temp;

	pthread_mutex_lock(&(info->inter->sysmutex)[EXIT_FLAG]);
	(info->inter->exit_flag)++;
	pthread_mutex_unlock(&(info->inter->sysmutex)[EXIT_FLAG]);
	i = -1;
	while (++i < idx)
		pthread_join((info->threads)[i], &temp);
	i = -1;
	while (++i < info->num_people)
		pthread_mutex_destroy(&(info->inter->forkmutex)[i]);
	i = -1;
	while (++i < 2)
		pthread_mutex_destroy(&(info->inter->sysmutex)[i]);
	write(2, str, strlen(str));
	if (info && info->inter && info->inter->forkmutex)
		free(info->inter->forkmutex);
	if (info && info->inter)
		free(info->inter);
	if (info && info->threads)
		free(info->threads);
	if (info)
		free(info);
	return (-1);
}
