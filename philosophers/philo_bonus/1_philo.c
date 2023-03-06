/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:05:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/06 23:49:38 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_parent_process_routine(t_philo *info);
static int	ft_is_exit_fin_dining(t_philo *info);

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
		return (ft_child_process_routine(info, i + 1));
	else
		return (ft_parent_process_routine(info));
}

static int	ft_parent_process_routine(t_philo *info)
{
	int	i;

	while (ft_is_exit_fin_dining(info) == CONTINUE)
		usleep(1000);
	i = -1;
	usleep(3000);
	while (++i < info->num_people)
		kill((info->pids)[i], SIGTERM);
	i = -1;
	while (++i < 3)
		sem_close((info->semaphore)[i]);
	free(info->pids);
	free(info);
	exit(0);
	return (0);
}

static int	ft_is_exit_fin_dining(t_philo *info)
{
	int	flag;

	flag = CONTINUE;
	sem_wait((info->semaphore)[EXIT_FLAG]);
	if (info->exit_flag != 0)
		flag = TERMINATE;
	sem_post((info->semaphore)[EXIT_FLAG]);
	if (flag == TERMINATE)
		return (TERMINATE);
	sem_wait((info->semaphore)[MEAL_FIN_COUNT]);
	if (info->fin_count == info->num_people)
		flag = TERMINATE;
	sem_post((info->semaphore)[MEAL_FIN_COUNT]);
	if (flag != TERMINATE)
		return (CONTINUE);
	usleep(1000);
	sem_wait((info->semaphore)[EXIT_FLAG]);
	(info->exit_flag)++;
	printf("All Philosophers Finish defined meals\n");
	sem_post((info->semaphore)[EXIT_FLAG]);
	return (TERMINATE);
}
