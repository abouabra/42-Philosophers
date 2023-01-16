/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:42:15 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/16 14:25:19 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status_2(t_args *vars, int status, int id)
{
	if (status == IS_THINKING)
		printf("%ld %d is thinking\n",
			get_interval(vars->initial_time, get_time()), id);

	if (status == IS_DEAD)
		printf("%ld %d has died\n",
			get_interval(vars->initial_time, get_time()), id);

	if (status == IS_FULL)
		printf("%ld EVERY ONE ATE\n",
			get_interval(vars->initial_time, get_time()));

}

void	print_status(t_args *vars, int status, int id)
{
	if (vars->kill_yourself)
		return ;

	if (status == IS_TAKING_FORK)
		printf("%ld %d has taken a fork\n",
			get_interval(vars->initial_time, get_time()), id);

	if (status == IS_EATING)
		printf("%ld %d is eating\n",
			get_interval(vars->initial_time, get_time()), id);

	if (status == IS_SLEEPING)
		printf("%ld %d is sleeping\n",
			get_interval(vars->initial_time, get_time()), id);
			
	print_status_2(vars, status, id);
}

int	is_every_one_ate(t_args *vars)
{
	(void) vars;
	return 0;
}
