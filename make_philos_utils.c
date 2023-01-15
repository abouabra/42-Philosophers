
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

void print_status(t_args *vars, char *status, int id)
{
	printf("%ld %d %s", get_interval(vars->initial_time, get_time()), id, status);
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