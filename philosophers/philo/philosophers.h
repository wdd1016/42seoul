/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/27 23:21:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

typedef struct	s_interact
{
	long			finisher_count;
	int				pil_numbers;
	int				exit_flag;
	pthread_mutex_t	*forkmutex;
	pthread_mutex_t	sysmutex[2];
}	t_interact;

typedef struct	s_philo
{
	struct timeval	starttime;
	pthread_t		*threadnum;
	long			num_people;
	long			lifetime;
	long			mealtime;
	long			sleeptime;
	long			max_meal;
	t_interact		inter;
}	t_philo;

long	ft_atol(const char *str);

#endif