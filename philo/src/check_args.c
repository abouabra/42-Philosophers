/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:38:22 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/15 18:41:18 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	check_args(t_args *vars, char **av)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!ft_is_number(av[i + 1]))
			return (0);
		if (ft_atoi(av[i + 1]) < 0)
			return (0);
	}
	vars->n_of_philos = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	if (!av[5])
		vars->n_times_must_eat = 0;
	else
	{
		vars->n_times_must_eat = ft_atoi(av[5]);
		if (vars->n_times_must_eat < 0)
			return (0);
	}
	return (1);
}
