/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:27:44 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/24 17:15:17 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_args_count(int ac)
{
	if (ac != 5 && ac != 6)
		exit(EXIT_SUCCESS);
}

void	ft_args_check_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!('0' <= av[i][j] && av[i][j] <= '9'))
				exit(EXIT_SUCCESS);
			j++;
		}
		i++;
	}
}

void	ft_args_control(int ac, char **av)
{
	ft_args_count(ac);
	ft_args_check_number(ac, av);
}