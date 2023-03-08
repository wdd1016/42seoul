/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/08 22:27:58 by juyojeon         ###   ########.fr       */
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
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

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
}	t_philo;

typedef struct s_data
{
	int				pnum;
	struct timeval	rtm;
	struct timeval	ntm;
	long			startdiff;
	int				eat_count;
	int				success_flag;
}	t_data;

# define CONTINUE 0
# define TERMINATE 1
# define FK_SEM 0
# define PRINT_SEM 1
# define PASS 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define FINISH_EAT 0
# define DEAD 1

int		ft_record_arguments(t_philo *info, int argc, char *argv[]);
int		ft_init_check_get_start_time(t_philo *info);
int		ft_think_sem_init(t_philo *info);
int		ft_sem_unlink_close(t_philo *info);
int		ft_child_process_routine(t_philo *info, long pnum);
void	ft_find_pnum_init_data(t_philo *info, t_data *data, int p_num);
int		ft_print(t_philo *pinfo, t_data *tdata, int flag);
void	ft_print_fork(t_philo *pinfo, t_data *tdata);
void	ft_print_eat(t_philo *pinfo, t_data *tdata);
void	ft_print_sleep(t_philo *pinfo, t_data *tdata);
void	ft_print_think(t_philo *pinfo, t_data *tdata);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);
void	ft_died(t_philo *info, t_data *data);
int		ft_error(t_philo *info, const char *str);
int		ft_error_process(int idx, t_philo *info, const char *str);

#endif