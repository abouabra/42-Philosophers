/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:26 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/16 14:26:58 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	end_phase(t_args *vars)
{
	int	i;

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

int	main(int ac, char **av)
{
	t_args	*vars;

	if (ac < 5)
		return (0);
	vars = ft_calloc(1, sizeof(t_args));
	if (!vars)
		return (0);
	if (!check_args(vars, av))
	{
		free(vars);
		return (0);
	}
	make_philos(vars);
	return (0);
}
