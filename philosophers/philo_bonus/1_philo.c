/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:05:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/05 02:58:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_is_fin_dining(t_philo *info);
static void	ft_all_free_destroy(t_philo *info);

int	main(int argc, char *argv[])
{
	t_philo	*info;
	int		i;

	info = (t_philo *)malloc(sizeof(t_philo));
	if (!info || !memset(info, 0, sizeof(t_philo)))
		return (ft_error(info, "Allocation Error\n"));
	if (ft_record_arguments(info, argc, argv) == TERMINATE)
		return (ft_error(info, "Argument Error\n"));
	if (ft_init_check_get_start_time(info) == TERMINATE)
		return (-1);
	if (ft_think_sem_threadt_init(info) == TERMINATE)
		return (ft_error(info, "Generation Error\n"));
	i = -1;
	while (++i < info->num_people)
	{
		(info->pids)[i] = fork();
		if ((info->pids)[i] < 0)
			return (ft_error_process(i, info, "Process create Error\n"));
		else if ((info->pids)[i] == 0)
			break ;
	}
	if (i < info->num_people)
		ft_child_process_routine(info, i + 1);
	else
		ft_parent_process_routine(info);
	return (0);
}

void	ft_child_process_routine(t_philo *info, long pnum)
{
}

void	ft_parent_process_routine(t_philo *info)
{
}

static int	ft_is_fin_dining(t_philo *info)
{
	if (info->inter->fin_count != info->num_people)
		return (CONTINUE);
	usleep(1000);
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
