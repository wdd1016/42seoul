/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:05:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/07 22:35:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_parent_process_routine(t_philo *info);
static int	ft_close_free(t_philo *info);

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
	if (ft_think_sem_init(info) == TERMINATE)
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
	pid_t	temp;
	int		i;
	int		j;
	int		status;

	i = -1;
	while (++i < info->num_people)
	{
		temp = waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == DEAD)
		{
			j = -1;
			while (++j < info->num_people)
				if ((info->pids)[j] != temp)
					kill((info->pids)[j], SIGTERM);
			j = i;
			while (++j < info->num_people)
				waitpid(-1, &status, 0);
			break ;
		}
	}
	if (i == info->num_people)
		printf("All Philosophers Finish defined meals\n");
	return (ft_close_free(info));
}

static int	ft_close_free(t_philo *info)
{
	sem_close((info->semaphore)[FK_SEM]);
	sem_close((info->semaphore)[PRINT_SEM]);
	free(info->pids);
	free(info);
	exit(0);
	return (0);
}
