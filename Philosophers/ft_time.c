/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:49:53 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/25 17:05:28 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)wait_time)
		usleep(100);
}

t_time	ft_get_time(void)
{
	struct timeval	tv;
	t_time			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%llu\n", time);
	return (time);
}