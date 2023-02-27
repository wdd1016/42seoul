/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:05:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/27 23:21:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo	*share;
	int		i;

	share = (t_philo *)malloc(sizeof(t_philo));
	if (share == 0 || ft_init_philo_struct(share) == 0)
		return (ft_error(share, "Allocation Error\n"));
	if (ft_record_arguments(share, argc, argv) == 0)
		return (ft_error(share, "Argument Error\n"));
	if (ft_mutex_init(share) == 0)
		return (ft_error(share, "Mutex generation Error\n"));
	if (gettimeofday(&(share->starttime), NULL) == -1)
		return (ft_error(share, "Time parcing Error\n"));
	i = -1;
	while (++i < share->num_people)
	{
		if (pthread_create() != 0)
			return (ft_error_join(share, "Thread create Error"));
	}
}

int	ft_mutex_init(t_philo *share)
{
	int	i;

	share->inter.forkmutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* (share->num_people + 1));
	if (share->inter.forkmutex == 0)
		return (0);
	i = -1;
	while (++i < share->num_people + 1)
		if (pthread_mutex_init(&(share->inter.forkmutex)[i], NULL) == -1)
			return (0);
	i = -1;
	while (++i < 2)
		if (pthread_mutex_init(&(share->inter.sysmutex)[i], NULL) == -1)
			return (0);
	return (1);
}

int	ft_error(t_philo *share, const char *str)
{
	printf("%s", str);
	if (share->inter.forkmutex)
		free(share->inter.forkmutex);
	if (share->threadnum)
		free(share->threadnum);
	if (share)
		free(share);
	return (-1);
}
