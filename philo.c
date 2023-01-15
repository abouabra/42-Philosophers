/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:26 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/15 18:37:39 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void end_phase(t_args *vars)
{
	int i;

	i = -1;
	while (++i < vars->n_of_philos)
		pthread_mutex_unlock(&(vars->mutex[i]));
	i = -1;
	while (++i < vars->n_of_philos)
		pthread_mutex_destroy(&(vars->mutex[i]));
	i = -1;
	while (++i < vars->n_of_philos)
		pthread_join(vars->th[i], NULL);
	free(vars);
}

void fill_colors(t_args *vars)
{
	vars->colors[RESET] = "\033[0m";
	vars->colors[RED] = "\033[1;31m";
	vars->colors[GREEN] = "\033[1;32m";
	vars->colors[BLUE] = "\033[1;34m";
	vars->colors[YELLOW] = "\033[1;33m";
	vars->colors[WHITE] = "\033[1;37m";
}

int main(int ac, char **av)
{
	t_args *vars;

	if(ac < 5)
		return 0;
	vars = ft_calloc(1, sizeof(t_args));
	if(!vars)
		return 0;
	if(!check_args(vars,av))
	{
		free(vars);
		return 0;
	}
	fill_colors(vars);
	make_philos(vars);
	return 0;
}
