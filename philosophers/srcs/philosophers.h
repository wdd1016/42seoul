/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/02 22:01:27 by juyojeon         ###   ########.fr       */
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
	long			fin_count;
	int				pil_num;
	int				exit_flag;
	pthread_mutex_t	*forkmutex;
	pthread_mutex_t	sysmutex[3];
}	t_interact;

typedef struct	s_philo
{
	struct timeval	starttime;
	pthread_t		*threads;
	long			num_people;
	long			lifetime;
	long			mealtime;
	long			sleeptime;
	long			max_meal;
	t_interact		*inter;
}	t_philo;

typedef struct s_data
{
	int				pnum;
	struct timeval	reftime;
	long			startdiff;
	long			refdiff;
	int				fir_fork;
	int				sec_fork;
	int				eat_count;
}	t_data;

# define CONTINUE 0
# define TERMINATE 1
# define FIL_NUM 0
# define EXIT_FLAG 1
# define MEAL_FIN_COUNT 2

long	ft_atol(const char *str);
int		ft_init_philo_struct(t_philo *share);
int		ft_record_arguments(t_philo *share, int argc, char *argv[]);
int		ft_mutex_threadt_init(t_philo *info);
void	ft_find_pnum_init_data(t_philo *pinfo, t_data *tdata);
void	*ft_thread_routine(void *arg);

#endif