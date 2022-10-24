/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:13:41 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/24 20:13:42 by yacis@stude      ###   ########.fr       */
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
int		ft_atoi(const char *str);
void	ft_init_philos(t_philo *philo, int ac, char **av);
void	ft_init_mutex(t_philo *philo, char **av, pthread_mutex_t *forks,
			pthread_mutex_t *death);
t_time	ft_get_time(void);
void	ft_sleep(int wait_time);

#endif