/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:26 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/30 16:29:55 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_args	*vars;

	if (ac < 5 || ac > 6)
		return (0);
	vars = my_alloc(sizeof(t_args));
	if (!vars)
		return (0);
	if (!check_args(vars, av))
		custom_exit(0);
	make_philos(vars);
	custom_exit(0);
	return (0);
}
