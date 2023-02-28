/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:44:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/28 02:00:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_philo_struct(t_philo *info)
{
	info = (t_philo *)malloc(sizeof(t_philo));
	if (!info)
		return (0);
	info->num_people = 0;
	info->lifetime = 0;
	info->mealtime = 0;
	info->sleeptime = 0;
	info->max_meal = 0;
	info->threads = 0;
	info->inter = 0;
	info->inter = (t_interact *)malloc(sizeof(t_interact));
	info->inter->fin_count = 0;
	info->inter->pil_num = 0;
	info->inter->exit_flag = 0;
	info->inter->forkmutex = 0;
	return (1);
}

int	ft_record_arguments(t_philo *info, int argc, char *argv[])
{
	long	*times[5];
	int		i;

	times[1] = &(info->num_people);
	times[2] = &(info->lifetime);
	times[3] = &(info->mealtime);
	times[4] = &(info->sleeptime);
	if (argc <= 4 || argc >= 7)
		return (0);
	i = 0;
	while (++i < 5)
	{
		*(times[i]) = ft_atol(argv[i]);
		if (*(times[i]) == 0)
			return (0);
	}
	if (argc == 5)
		info->max_meal = 0;
	else
	{
		info->max_meal = ft_atol(argv[5]);
		if (info->max_meal == 0)
			return (0);
	}
	return (1);
}

int	ft_mutex_threadt_init(t_philo *info)
{
	int	i;

	info->inter->forkmutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* (info->num_people));
	if (info->inter->forkmutex == 0)
		return (0);
	info->threads = (pthread_t *)malloc(sizeof(pthread_t) * info->num_people);
	if (info->threads == 0)
		return (0);
	i = -1;
	while (++i < info->num_people)
		if (pthread_mutex_init(&(info->inter->forkmutex)[i], NULL) == -1)
			return (0);
	i = -1;
	while (++i < 2)
		if (pthread_mutex_init(&(info->inter->sysmutex)[i], NULL) == -1)
			return (0);
	return (1);
}
