/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:42:15 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/14 17:35:19 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status_2(t_args *vars, int status, int id)
{
	if (status == IS_THINKING)
		printf("%ld %d is thinking\n",
			get_interval(vars->initial_time, get_time()),
			id);
	if (status == IS_DEAD)
		printf("%ld %d has died\n",
			get_interval(vars->initial_time, get_time()),
			id);
	if (status == IS_FULL)
		printf("%ld EVERY ONE ATE\n",
			get_interval(vars->initial_time, get_time()));
	sem_post(vars->print);
}

void	print_status(t_args *vars, int status, int id)
{
	sem_wait(vars->print);
	if (vars->kill_yourself)
		return ;
	if (status == IS_TAKING_FORK)
		printf("%ld %d has taken a fork\n",
			get_interval(vars->initial_time, get_time()),
			id);
	if (status == IS_EATING)
		printf("%ld %d is eating\n",
			get_interval(vars->initial_time, get_time()),
			id);
	if (status == IS_SLEEPING)
		printf("%ld %d is sleeping\n",
			get_interval(vars->initial_time, get_time()),
			id);
	print_status_2(vars, status, id);
}

int	is_full(t_args *vars)
{
	if (vars->eating_times < vars->n_times_must_eat)
		return (0);
	return (1);
}

int	is_every_one_ate(t_args *vars)
{
	int		i;
	char	*name;
	sem_t	*tmp;

	i = -1;
	while (++i < vars->n_of_philos)
	{
		name = ft_strjoin_gnl(ft_itoa(i), "_IS_FULL");
		tmp = sem_open(name, O_EXCL, 0644, 1);
		if (tmp == SEM_FAILED)
			return (0);
		sem_close(tmp);
	}
	return (1);
}

void	init_philos(t_args *vars)
{
	int		i;
	char	*name;

	sem_unlink("/FORKS");
	sem_unlink("/PRINT");
	sem_unlink("/IM_DEAD");
	i = -1;
	while (++i < 200)
	{
		name = ft_strjoin_gnl(ft_itoa(i), "_IS_FULL");
		sem_unlink(name);
	}
	vars->forks = sem_open("/FORKS", O_CREAT | O_EXCL, 0644, vars->n_of_philos);
	vars->print = sem_open("/PRINT", O_CREAT | O_EXCL, 0644, 1);
	vars->initial_time = get_time();
}
