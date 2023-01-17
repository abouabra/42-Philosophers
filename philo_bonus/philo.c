/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:26 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/17 14:37:20 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_phase(t_args *vars)
{

	free(vars);
}

int	main(int ac, char **av)
{
	t_args	*vars;

	if (ac < 5 || ac > 6)
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
	end_phase(vars);
	return (0);
}
