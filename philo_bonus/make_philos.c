/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:44:51 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/16 14:51:05 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

void philo_life(t_args *vars)
{
	if(vars->id % 2 == 1)
		usleep(50);
	while(1)
	{
		print_status(vars, IS_TAKING_FORK, vars->id +1);
		sem_wait(vars->forks);
		print_status(vars, IS_TAKING_FORK, vars->id +1);
		sem_wait(vars->forks);
		
		print_status(vars, IS_EATING, vars->id +1);
		ft_usleep(vars, vars->time_to_eat);

		
		sem_post(vars->forks);
		sem_post(vars->forks);


		print_status(vars, IS_SLEEPING, vars->id +1);
		ft_usleep(vars, vars->time_to_sleep);
		print_status(vars, IS_THINKING, vars->id +1);
	}
}

void	make_philos(t_args *vars)
{
	int i;
	int id;
	
	vars->forks = sem_open("/FORKS", O_CREAT | O_EXCL, 0644, vars->n_of_philos);
	vars->initial_time = get_time();
	i = -1;
	while(++i < vars->n_of_philos)
	{
		vars->id = i;
		id = fork();
		if(id == -1)
			return;
		if(id == 0)
		{
			philo_life(vars);
			exit(0);
		}
	}

	while(waitpid(-1, NULL, 0) > 0)
		;
	sem_close(vars->forks);
	sem_unlink("/FORKS");
}
