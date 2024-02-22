/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:44:51 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/30 16:30:08 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_for_eat(t_args *vars)
{
	char	*name;

	if (vars->n_times_must_eat && is_full(vars))
	{
		name = ft_strjoin_gnl(ft_itoa(vars->id), "_IS_FULL");
		sem_close(sem_open(name, O_CREAT | O_EXCL, 0644, 1));
	}
	if (vars->n_times_must_eat && is_every_one_ate(vars))
	{
		if (vars->id == 0)
			print_status(vars, IS_FULL, vars->id + 1);
		custom_exit(0);
	}
}

void	*check_for_death(void *args)
{
	t_args	*vars;

	vars = (t_args *)args;
	while (1)
	{
		if (get_interval(vars->eating_duration,
				get_time()) >= vars->time_to_die)
		{
			sem_close(sem_open("/IM_DEAD", O_CREAT | O_EXCL, 0644, 1));
			print_status(vars, IS_DEAD, vars->id + 1);
			vars->kill_yourself = 1;
		}
		if (sem_open("/IM_DEAD", O_EXCL, 0644, 1) != SEM_FAILED)
		{
			unlink("/IM_DEAD");
			custom_exit(0);
		}
		check_for_eat(vars);
		usleep(100);
	}
	return (NULL);
}

void	eating_stage(t_args *vars)
{
	if (vars->n_of_philos > 1)
	{
		sem_wait(vars->forks);
		print_status(vars, IS_TAKING_FORK, vars->id + 1);
		print_status(vars, IS_EATING, vars->id + 1);
		usleep(1000 * vars->time_to_eat);
		vars->eating_duration = get_time();
		vars->eating_times += 1;
		sem_post(vars->forks);
		sem_post(vars->forks);
	}
}

void	philo_life(void *args)
{
	pthread_t	ph;
	t_args		*vars;

	vars = (t_args *)args;
	pthread_create(&ph, NULL, check_for_death, vars);
	while (1)
	{
		sem_wait(vars->forks);
		print_status(vars, IS_TAKING_FORK, vars->id + 1);
		eating_stage(vars);
		print_status(vars, IS_SLEEPING, vars->id + 1);
		usleep(1000 * vars->time_to_sleep);
		print_status(vars, IS_THINKING, vars->id + 1);
	}
}

void	make_philos(t_args *vars)
{
	int	i;
	int	id;

	init_philos(vars);
	vars->eating_duration = get_time();
	i = -1;
	while (++i < vars->n_of_philos)
	{
		id = fork();
		if (id == -1)
			return ;
		if (id == 0)
		{
			vars->id = i;
			philo_life(vars);
			exit(0);
		}
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
}
