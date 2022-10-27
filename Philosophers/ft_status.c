/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:49:24 by yacis             #+#    #+#             */
/*   Updated: 2022/10/27 16:50:58 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_dead(t_philo *philo, int i, t_time time)
{
	if ((int)time > philo[i].time_to_die)
	{
		printf("%llu %d %s\n", time, philo->id + 1, "died");
		*philo->is_dead = 1;
		return (1);
	}
	return (0);
}

int ft_finish_serving(t_philo *philo, int *j, int *result)
{
	if (philo->must_eat != -1)
	{
		while (*j < philo->philo_num)
			*result += philo[(*j)++].meals_eaten;
		if (*result == philo->philo_num * philo->must_eat)
		{
			*philo->is_dead = 1;
			return (1);
		}
	}
	return (0);
}

void ft_check_dead(t_philo *philo)
{
	t_time time;
	int i;
	int j;
	int result;

	i = 0;
	j = 0;
	result = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_lock(philo->death);
		time = ft_get_time() - philo[i].last_meal;
		if (ft_dead(philo, i, time) || ft_finish_serving(philo, &j, &result))
			break;
		i++;
		pthread_mutex_unlock(philo->death);
	}
}

int ft_print_status(t_philo *philo, char *status)
{
	t_time time;

	time = ft_get_time() - philo->start_time;
	pthread_mutex_lock(philo->death);
	if (*philo->is_dead == 0)
		printf("%llu %d %s\n", time, philo->id + 1, status);
	pthread_mutex_unlock(philo->death);
	return (0);
}