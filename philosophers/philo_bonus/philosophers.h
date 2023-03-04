/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/05 02:46:45 by juyojeon         ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_philo
{
	struct timeval	stm;
	pid_t			*pids;
	long			num_people;
	long			lifetime;
	long			mealtime;
	long			sleeptime;
	long			thinkt;
	long			max_meal;
	sem_t			*semaphore[3];
	long			fin_count;
	int				exit_flag;
}	t_philo;

typedef struct s_data
{
	int				pnum;
	struct timeval	rtm;
	struct timeval	ntm;
	long			startdiff;
	int				eat_count;
}	t_data;

# define CONTINUE 0
# define TERMINATE 1
# define FK_SEM 0
# define EXIT_FLAG 1
# define MEAL_FIN_COUNT 2
# define PASS 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

int		ft_record_arguments(t_philo *info, int argc, char *argv[]);
int		ft_init_check_get_start_time(t_philo *info);
int		ft_think_sem_threadt_init(t_philo *info);
int		ft_sem_unlink_close(t_philo *info);

#endif