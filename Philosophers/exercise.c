/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:10:01 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/24 21:12:24 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void	*my_thread_fun(void *vargp)
{
	sleep(1);
	printf("Selam\n");
	return NULL;
}

int	main(void)
{
	pthread_t	thread_id;

	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, my_thread_fun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}