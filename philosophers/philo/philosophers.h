/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/10 16:03:34 by juyojeon         ###   ########.fr       */
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

typedef struct s_interact
{
	long			fin_count;
	int				pil_num;
	int				exit_flag;
	pthread_mutex_t	*forkmutex;
	pthread_mutex_t	sysmutex[4];
}	t_interact;

typedef struct s_philo
{
	struct timeval	stm;
	pthread_t		*threads;
	long			num_people;
	long			lifetime;
	long			mealtime;
	long			sleeptime;
	long			thinkt;
	long			max_meal;
	t_interact		*inter;
}	t_philo;

typedef struct s_data
{
	int				pnum;
	struct timeval	rtm;
	struct timeval	ntm;
	long			startdiff;
	int				fir_fork;
	int				sec_fork;
	int				eat_count;
}	t_data;

# define CONTINUE 0
# define TERMINATE 1
# define FIL_NUM 0
# define EXIT_FLAG 1
# define MEAL_FIN_COUNT 2
# define GETTIME 3
# define PASS 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

int		ft_init_philo_struct(t_philo *info);
int		ft_record_arguments(t_philo *info, int argc, char *argv[]);
int		ft_init_check_get_start_time(t_philo *info);
int		ft_think_mutex_threadt_init(t_philo *info);
void	*ft_th_routine(void *arg);
void	ft_find_pnum_init_data(t_philo *pinfo, t_data *tdata);
void	ft_die(t_philo *pinfo, t_data *tdata);
int		ft_is_max_meal(t_philo *pinfo, t_data *tdata);
void	ft_print(t_philo *pinfo, t_data *tdata, int flag);
void	ft_print_fork(t_philo *pinfo, t_data *tdata);
void	ft_print_eat(t_philo *pinfo, t_data *tdata);
void	ft_print_sleep(t_philo *pinfo, t_data *tdata);
void	ft_print_think(t_philo *pinfo, t_data *tdata);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);
int		ft_error(t_philo *info, const char *str);
int		ft_error_thread(int idx, t_philo *info, const char *str);
#endif