/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 07:25:26 by yacis             #+#    #+#             */
/*   Updated: 2022/10/29 07:25:26 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_dinner, &philo[i]);
		i++;
		usleep(100);
	}
	while (*philo->is_dead != 1)
		ft_check_death(philo);
}

void	ft_init_mutex(t_philo *philo, char **argv,
	pthread_mutex_t *forks, pthread_mutex_t *death)
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
	while (i < ft_atol(argv[1]))
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}

void	ft_init_philos(t_philo *philo, int argc, char **argv)
{
	int	is_dead;
	int	i;

	i = 0;
	is_dead = 0;
	while (i < ft_atol(argv[1]))
	{
		philo[i].id = i;
		philo[i].time_to_die = ft_atol(argv[2]);
		philo[i].time_to_eat = ft_atol(argv[3]);
		philo[i].time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			philo[i].must_eat = ft_atol(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].meals_eaten = 0;
		philo[i].philo_num = ft_atol(argv[1]);
		philo[i].is_dead = &is_dead;
		i++;
	}
	philo->total_eaten = 0;
}



int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (argc != 5 && argc != 6)
		return (1);
	if (ft_check_args(argc, argv) == 0)
		return (2);
	philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo)
		return (3);
	ft_init_philos(philo, argc, argv);
	ft_init_mutex(philo, argv, forks, death);
	ft_join_threads(philo, argv);
	ft_free(philo, forks, death);
	return (0);
}
