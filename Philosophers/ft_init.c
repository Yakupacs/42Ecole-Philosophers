/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:22:44 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/24 20:14:00 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(t_philo *philo, int ac, char **av)
{
	int	i;
	int	dead;

	i = 0;
	dead = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i;
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo[i].must_eat = ft_atoi(av[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].meals_eaten = 0;
		philo[i].philo_num = ft_atoi(av[1]);
		philo[i].is_dead = &dead;
		i++;
	}
	philo->total_eaten = 0;
}

void	ft_init_mutex(t_philo *philo, char **av, pthread_mutex_t *forks,
	pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		philo[i].left_fork_mutex = &forks[i];
		philo[i].right_fork_mutex = &forks[(i + 1) % philo->philo_num];
		i++;
	}
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}
