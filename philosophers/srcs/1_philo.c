/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:05:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/04 17:28:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_is_fin_dining(t_philo *info);
static void	ft_all_free_destroy(t_philo *info);

int	main(int argc, char *argv[])
{
	t_philo	*info;
	int		i;
	void	*temp;

	info = (t_philo *)malloc(sizeof(t_philo));
	if (!info || ft_init_philo_struct(info) == TERMINATE)
		return (ft_error(info, "Allocation Error\n"));
	if (ft_record_arguments(info, argc, argv) == TERMINATE)
		return (ft_error(info, "Argument Error\n"));
	if (ft_init_check_get_start_time(info) == TERMINATE)
		return (-1);
	if (ft_think_mutex_threadt_init(info) == TERMINATE)
		return (ft_error(info, "Generation Error\n"));
	i = -1;
	while (++i < info->num_people)
		if (pthread_create(&(info->threads)[i], NULL, ft_th_routine, info) != 0)
			return (ft_error_thread(i, info, "Thread create Error\n"));
	while (info->inter->exit_flag == 0 && ft_is_fin_dining(info) == CONTINUE)
		usleep(1000);
	i = -1;
	while (++i < info->num_people)
		pthread_join((info->threads)[i], &temp);
	ft_all_free_destroy(info);
	return (0);
}

static int	ft_is_fin_dining(t_philo *info)
{
	if (info->inter->fin_count != info->num_people)
		return (CONTINUE);
	pthread_mutex_lock(&(info->inter->sysmutex)[EXIT_FLAG]);
	(info->inter->exit_flag)++;
	printf("All Philosophers Finish defined meals\n");
	pthread_mutex_unlock(&(info->inter->sysmutex)[EXIT_FLAG]);	
	return (TERMINATE);
}

static void	ft_all_free_destroy(t_philo *info)
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
