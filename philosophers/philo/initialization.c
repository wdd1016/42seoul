/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:44:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/27 23:20:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_philo_struct(t_philo *share)
{
	share->num_people = 0;
	share->lifetime = 0;
	share->mealtime = 0;
	share->sleeptime = 0;
	share->max_meal = 0;
	share->threadnum = 0;
	share->inter.finisher_count = 0;
	share->inter.pil_numbers = 0;
	share->inter.exit_flag = 0;
	share->inter.forkmutex = 0;
	return (1);
}

int	ft_record_arguments(t_philo *share, int argc, char *argv[])
{
	long	*times[5];
	int		i;

	times[1] = &(share->num_people);
	times[2] = &(share->lifetime);
	times[3] = &(share->mealtime);
	times[4] = &(share->sleeptime);
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
		share->max_meal = 0;
	else
	{
		share->max_meal = ft_atol(argv[5]);
		if (share->max_meal == 0)
			return (0);
	}
	return (1);
}

