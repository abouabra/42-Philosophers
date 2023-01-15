/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:56:27 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/15 13:19:37 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

long get_interval(time_t before, time_t after)
{
	// if(before > after)
	// 	return before - after;
	return after - before;
}

long get_time(void)
{
	struct timeval tmp;
	time_t elapsed_time;

	if(gettimeofday(&tmp, NULL) == -1)
	{
		printf("GETTIEMOFDAY\n");
		exit(0);
	}
	elapsed_time = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	return elapsed_time;
}

void ft_usleep(t_args *vars, int time)
{
	time_t waiting_until = get_time() + time;
	// printf("Waiting until: %ld\n", waiting_until);
	while (waiting_until > get_time() && vars->kill_yourself == 0)
		usleep(50);
}
