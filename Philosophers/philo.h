/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:50:07 by yacis             #+#    #+#             */
/*   Updated: 2022/10/27 21:24:46 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_philo{
	int		id;
	int		philo_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	int		meals_eaten;
	int		total_eaten;
	int		*is_dead;
	t_time	last_meal;
	t_time	start_time;
	pthread_t	thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}		t_philo;

void	ft_args_control(int ac, char **av);
void	ft_args_check_number(int ac, char **av);
void	ft_args_count(int ac);
long	ft_atoi(const char *str);
void	ft_init_philos(t_philo *philo, int ac, char **av);
void	ft_init_mutex(t_philo *philo, char **av, pthread_mutex_t *forks,
			pthread_mutex_t *death);
void	ft_join_thread(t_philo *philo, char **av);
t_time	ft_get_time(void);
void	ft_sleep(int wait_time);
void	*ft_dinner(void *args);
int		ft_print_status(t_philo *philo, char *status);
int		ft_finish_serving(t_philo *philo, int *j, int *result);
void	ft_check_dead(t_philo *philo);
int		ft_dead(t_philo *philo, int i, t_time time);
void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);

#endif