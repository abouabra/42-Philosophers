
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
#include <stdlib.h>

void	*handle_philo(void *arg)
{
	t_args	*vars;
	int		i;

	vars = (t_args *)arg;
	i = *(vars->index);
	if(i % 2 == 1)
		usleep(100);
	
	while (1)
	{
		if(vars->kill_yourself)
			return 0;

		pthread_mutex_lock(&vars->mutex[i]);
		print_status(vars, IS_TAKING_FORK, i + 1);

		if(vars->n_of_philos > 1)
		{
			pthread_mutex_lock(&vars->mutex[(i + 1) % vars->n_of_philos]);
			print_status(vars, IS_TAKING_FORK, i + 1);
		}
		print_status(vars, IS_EATING, i + 1);
		ft_usleep(vars, vars->time_to_eat);
		if(vars->n_of_philos > 1)
			vars->eating_duration[i] = get_time();
		vars->eating_times[i]++;

		pthread_mutex_unlock(&vars->mutex[i]);
		if(vars->n_of_philos > 1)
			pthread_mutex_unlock(&vars->mutex[(i + 1) % vars->n_of_philos]);
		print_status(vars, IS_SLEEPING, i + 1);

		ft_usleep(vars, vars->time_to_sleep);
		print_status(vars, IS_THINKING, i + 1);

	}
	return (NULL);
}

void	make_philos(t_args *vars)
{
	int	i;

	vars->initial_time = get_time();
	memset(vars->th, 0, sizeof(vars->th));
	memset(vars->mutex, 0, sizeof(vars->mutex));
	memset(vars->eating_times, 0, sizeof(vars->eating_times));
	memset(vars->eating_duration, 0, sizeof(vars->eating_duration));
	i = -1;
		while (++i < vars->n_of_philos)
			vars->eating_duration[i] = get_time();
	i = -1;
	while (++i < vars->n_of_philos)
		pthread_mutex_init(&(vars->mutex[i]), NULL);
	i = -1;
	while (++i < vars->n_of_philos)
	{
		vars->index = &i;
		if (pthread_create(&vars->th[i], NULL, handle_philo, vars))
			return ;
		usleep(100);
	}

	while(1)
	{
		i = -1;
		while(++i < vars->n_of_philos)
		{
			if (get_interval(vars->eating_duration[i],get_time()) >= vars->time_to_die)
			{
				print_status(vars, IS_DEAD, i + 1);

				vars->kill_yourself = 1;

				end_phase(vars);
				exit(0);
			}
			if (vars->n_times_must_eat && is_every_one_ate(vars))
			{
				print_status(vars, IS_FULL, i + 1);
				
				vars->kill_yourself = 1;

				end_phase(vars);
				exit(0);
			}
		}
		usleep(50);
	}
}
