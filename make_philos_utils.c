
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:22:31 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/07 16:10:44 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_args *vars, int status, int id)
{
	if(vars->kill_yourself)
		return;
	if(status == IS_TAKING_FORK)
		printf("%s %ld %d has taken a fork\n%s",vars->colors[GREEN],
		get_interval(vars->initial_time, get_time()),
		id, vars->colors[RESET]);
}

int is_every_one_ate(t_args *vars)
{
	int i;
	
	i=-1;
	while(++i < vars->n_of_philos)
		if(vars->eating_times[i] < vars->n_times_must_eat)
			return 0;
	return 1;
}