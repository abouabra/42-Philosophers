/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:44:51 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/15 19:05:42 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_food(t_args *vars, int i)
{
	pthread_mutex_lock(&vars->mutex[i]);
	print_status(vars, IS_TAKING_FORK, i + 1);
	if (vars->n_of_philos > 1)
	{
		pthread_mutex_lock(&vars->mutex[(i + 1) % vars->n_of_philos]);
		print_status(vars, IS_TAKING_FORK, i + 1);
		print_status(vars, IS_EATING, i + 1);
		ft_usleep(vars, vars->time_to_eat);
		vars->eating_duration[i] = get_time();
		vars->eating_times[i]++;
		pthread_mutex_unlock(&vars->mutex[i]);
		pthread_mutex_unlock(&vars->mutex[(i + 1) % vars->n_of_philos]);
	}
}

void	*handle_philo(void *arg)
{
	t_args	*vars;
	int		i;

	vars = (t_args *)arg;
	i = *(vars->index);
	if (i % 2 == 1)
		usleep(100);
	while (1)
	{
		if (vars->kill_yourself)
			return (0);
		philo_food(vars, i);
		print_status(vars, IS_SLEEPING, i + 1);
		ft_usleep(vars, vars->time_to_sleep);
		print_status(vars, IS_THINKING, i + 1);
	}
	return (NULL);
}

void	init_values(t_args *vars)
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
}

void	make_philos(t_args *vars)
{
	int	i;

	init_values(vars);
	while (1)
	{
		i = -1;
		while (++i < vars->n_of_philos)
		{
			if (get_interval(vars->eating_duration[i],
					get_time()) >= vars->time_to_die
				|| (vars->n_times_must_eat && is_every_one_ate(vars)))
			{
				if (vars->n_times_must_eat && is_every_one_ate(vars))
					print_status(vars, IS_FULL, i + 1);
				else
					print_status(vars, IS_DEAD, i + 1);
				vars->kill_yourself = 1;
				end_phase(vars);
				exit(0);
			}
		}
		usleep(50);
	}
}
