/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:23:51 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/24 21:50:06 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// av[1] -> philo count
// av[2] -> die time
// av[3] -> eat time
// av[4] -> sleep time

int	main(int ac, char **av)
{
	t_philo		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	ft_args_control(ac, av);
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (0);
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	death = malloc(sizeof(pthread_mutex_t));
	ft_init_philos(philo, ac, av);
	ft_init_mutex(philo, av, forks, death);
}
