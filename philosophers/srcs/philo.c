/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:05:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/28 20:26:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo	*info;
	int		i;
	void	*temp;

	if (ft_init_philo_struct(info) == 0)
		return (ft_error(info, "Allocation Error\n"));
	if (ft_record_arguments(info, argc, argv) == 0)
		return (ft_error(info, "Argument Error\n"));
	if (ft_mutex_threadt_init(info) == 0)
		return (ft_error(info, "Generation Error\n"));
	if (gettimeofday(&(info->starttime), NULL) == -1)
		return (ft_error(info, "Time parcing Error\n"));
	i = -1;
	while (++i < info->num_people)
		if (pthread_create(&(info->threads)[i], NULL, ft_thread_routine, info) != 0)
			return (ft_error_join(i, info, "Thread create Error"));
	while (info->inter->exit_flag == 0 && ft_is_fin_dining(info) == 0)
		usleep(2500);
	i = -1;
	while (++i < info->num_people)
		pthread_join((info->threads)[i], &temp);
	ft_all_free_destroy(info);
	return (0);
}

int	ft_is_fin_dining(t_philo *info)
{
	if (info->inter->fin_count != info->num_people)
		return (0);
	(info->inter->exit_flag)++;
	write(1, "All Philosophers Finish defined meals\n", 38);
	return (1);
}

void	ft_all_free_destroy(t_philo *info)
{
	int	i;

	i = -1;
	while (++i < info->num_people)
		pthread_mutex_destroy(&(info->inter->forkmutex)[i]);
	i = -1;
	while (++i < 2)
		pthread_mutex_destroy(&(info->inter->sysmutex)[i]);
	if (info->inter->forkmutex)
		free(info->inter->forkmutex);
	if (info->inter)
		free(info->inter);
	if (info->threads)
		free(info->threads);
	if (info)
		free(info);
}

int	ft_error(t_philo *info, const char *str)
{
	printf("%s", str);
	if (info->inter->forkmutex)
		free(info->inter->forkmutex);
	if (info->inter)
		free(info->inter);
	if (info->threads)
		free(info->threads);
	if (info)
		free(info);
	return (-1);
}
